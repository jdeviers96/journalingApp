#include <globalVars.h>
#include <entry.h>
#include <entryvec.h>
#include <timedata.h>

int main(int argc, char* argv[]) {

  if (argc > 2) {
    std::cout << "Too many arguments provided; exiting." << "\n";
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
  if (argc == 1) {
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
  std::string msg = argv[1];
  Entry e(daytime,msg);
  
  // Append entry to vector:
  ev.pushFileEntry(e);

  // Save full entryvec to file, overwriting it:
  lgf << ev;  

  // Close logfile:
  lgf.close();

  return 0;
}
