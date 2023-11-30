#include <globalVars.h>
#include <entry.h>
#include <entryvec.h>
#include <timedata.h>
#include <procedures.h>

// Arguments are now caught using Boost
#include <boost/program_options.hpp>
#include <exception>

namespace po = boost::program_options;

/*
void resetFile(std::string fn) {
  std::fstream lgf;
  lgf.open(fn, std::fstream::out | std::fstream::trunc);
  EntryVec ev;
  lgf << ev;
  lgf.close();
}

void touchFile(std::string fn) {
  std::fstream lgf;
  lgf.open(fn, std::fstream::out | std::fstream::app);
  std::cout << "No log message provided; creating the logfile (if not existing already) and exiting." << "\n";
  lgf.close();
}

EntryVec readFile(std::string fn) {
  std::fstream lgf;
  lgf.open(fn, std::fstream::in);
  EntryVec ev;
  lgf >> ev;
  lgf.close();
  return ev;
}

void writeFile(std::string fn, EntryVec &ev) {
  std::fstream lgf;
  lgf.open(fn, std::fstream::out | std::fstream::trunc); // Reopen, in overwrite mode
  lgf << ev;
  lgf.close();
}
*/

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


  // If --reset, open file in overwrite mode and write an empty entryvec:
  if (reset) {
    resetFile(fn);
    return 0;
  }

  // If there is no message, open file in app mode to just touch it:
  if (nomsg) {
    touchFile(fn);
    return 0;
  }

  // Read file into a vector of entries, then close it:
  EntryVec ev = readFile(fn);

  // Create new entry:
  Entry e(daytime,msg);
  
  // Append entry to vector:
  ev.pushFileEntry(e);

  // Write full EntryVec to file, close it.
  writeFile(fn, ev);

  return 0;
}
