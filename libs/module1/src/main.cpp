#include <globalVars.h>
#include <entry.h>
#include <entryvec.h>
#include <timedata.h>
#include <procedures.h>

// Arguments are now caught using Boost
#include <boost/program_options.hpp>
#include <exception>

namespace po = boost::program_options;

int main(int argc, char* argv[]) {

  // Options: associated flags and values:
  std::string msg;
  bool nomsg = false;
  bool reset = false;
  bool show  = false;

  // Boost command line parser:
  try {
    po::options_description desc("Allowed options");
    desc.add_options()
      ("-m", po::value<std::string>(), "Append an entry to the logfile")
      ("reset", "Reset today's logfile")
      ("show", "Print logfile to screen");

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

    if (vm.count("show")) {
      show = true;
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
  if (nomsg and not show) {
    touchFile(fn);
    return 0;
  }

  // Read file into a vector of entries, then close it:
  EntryVec ev = readFile(fn);

  // If --show but no message, print and exit:
  if (show and nomsg) {
    std::cout << ev;
    return 0;
  }

  // Create new entry:
  Entry e(daytime,msg);
  
  // Append entry to vector:
  ev.pushFileEntry(e);

  // "and not nomsg" is superfluous and here only for clarity
  if (show and not nomsg) {
    std::cout << ev;
  }

  // Write full EntryVec to file, close it.
  writeFile(fn, ev);

  return 0;
}
