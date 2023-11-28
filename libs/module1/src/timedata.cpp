#include <timedata.h>


// Constructor:
timeData::timeData() {
  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);
    
  ddate = std::to_string(now -> tm_mday) + '-' + 
          std::to_string(now -> tm_mon + 1) + '-' + 
          std::to_string(now -> tm_year + 1900);
      
  dtime = std::to_string(now -> tm_hour) + ':' +
          std::to_string(now -> tm_min) + ':' +
          std::to_string(now -> tm_sec);
}

// Accessors:
std::string timeData::gdd() {
  return ddate;
}

std::string timeData::gdt() {
  return dtime;
}
