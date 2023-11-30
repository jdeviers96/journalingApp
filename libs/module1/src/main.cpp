#include <globalVars.h>
#include <entry.h>
#include <entryvec.h>
#include <timedata.h>

// Arguments are now caught using Boost
#include <boost/program_options.hpp>
#include <exception>

namespace po = boost::program_options;

int main(int argc, char* argv[]) {

  // Options: associated flags and values:
  std::string msg;
  bool nomsg = false;
  bool reset = false;

  // Boost command line parser:
  try {
    po::options_description desc("Allowed options");
    desc.add_options()
      ("-m", po::value<std::string>(), "Append an entry to the logfile")
      ("reset", "Reset today's logfile");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
 
    if (vm.count("-m")) {
      msg = vm["-m"].as<std::string>();
    } else {
      nomsg = true;
    }

    if (vm.count("reset")) {
      std::cout << "Resetting the logfile." << "\n";
      reset = true;
    }
  }

  catch(std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }

  catch(...) {
    std::cerr << "Exception of unknown type!" << "\n";
    return 100;
  }

  // Get date and time:
  timeData t;
  std::string daydate,daytime;
  daydate = t.gdd();
  daytime = t.gdt();

  // Set filename:
  std::string path = LGF_PATH;
  std::string fn;

  fn = path + "/" + daydate + "_logfile.dat";

  // (Create and) open logfile, READ mode:
  std::fstream lgf;
  lgf.open(fn, std::fstream::in);

  // Check there is a message:
  if (nomsg and (not reset)) {
    std::cout << "No log message provided; creating the logfile (if not existing already) and exiting." << "\n";
    lgf.close();
    return 0;
  }

  // Read file into a vector of entries:
  EntryVec ev;
  lgf >> ev;

  // Done reading from file: close it b/c can't both read and write from a file:
  lgf.close();
  lgf.open(fn, std::fstream::out | std::fstream::trunc); // Reopen, in overwrite mode

  // Create new entry:
  Entry e(daytime,msg);
  
  // Append entry to vector:
  ev.pushFileEntry(e);

  // This occurs after file and entry reading, which is unnecessary overhead.
  if (reset) {
    ev.clear();
  }

  // Save full entryvec to file, overwriting it:
  lgf << ev;  

  // Close logfile:
  lgf.close();

  return 0;
}
