//#include <entry.h>
//#include <entryvec.h>
//#include <timedata.h>

#include <procedures.h>

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

