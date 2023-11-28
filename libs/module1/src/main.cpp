#include <globalVars.h>
#include <entry.h>
//#include <entryvec.h>
#include <timedata.h>

int main(int argc, char* argv[]) {

  if (argc > 2) {
    std::cout << "Too many arguments provided; exiting." << "\n";
    return 100;
  }

  // Get date and time.
  timeData t;
  std::string daydate,daytime;
  daydate = t.gdd();
  daytime = t.gdt();

  // Set filename
  std::string path = LGF_PATH;
  std::string fn;

  fn = path + "/" + daydate + "_logfile.dat";

  // (Create and) open logfile.
  std::fstream lgf;
  lgf.open(fn, std::fstream::in | std::fstream::out | std::fstream::app);

  if (argc == 1) {
    std::cout << "No log message provided; creating the logfile (if not existing already) and exiting." << "\n";
    lgf.close();
    return 0;
  }

  // Create new entry:
  std::string msg = argv[1];
  Entry e;

  e.timecode = daytime; 
  e.inputtxt = msg; // Could all be done in 1 line: Entry e(daytime,argv[2]);

  lgf << e;  

  // Close logfile
  lgf.close();

  return 0;
}
