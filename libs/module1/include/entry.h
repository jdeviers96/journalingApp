#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


struct Entry {
  std::string timecode;
  std::string inputtxt;

  // Constructor: 
  Entry(std::string t = "", std::string i = "");
  
  // Overloaded insertion/extraction operators
  friend std::ostream & operator<<(std::ostream &os, const Entry &e);
  friend std::istream & operator>>(std::istream &is, Entry &e);
  friend std::fstream & operator>>(std::fstream &fs, Entry &e);
};

#endif
