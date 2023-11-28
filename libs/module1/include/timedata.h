#ifndef TIMEDATA_H
#define TIMEDATA_H

#include <iostream>
#include <string>
#include <ctime>

class timeData {
  private:
    std::string ddate;
    std::string dtime;

  public:
    // Constructor:
    timeData();
    // Accessors:
    std::string gdd();
    std::string gdt();

};

#endif
