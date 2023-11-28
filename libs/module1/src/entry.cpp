#include <entry.h>

// Constructor: 
Entry::Entry(std::string t, std::string i) {
  timecode = t; 
  inputtxt = i;
}


std::ostream & operator<<(std::ostream &os, const Entry &e) {
  os << e.timecode << "    " << e.inputtxt << "\n";
  return os;
}


std::istream & operator>>(std::istream &is, Entry &e) {
  is >> e.timecode >> e.inputtxt;
  return is;
}


std::fstream & operator>>(std::fstream &fs, Entry &e) {
  std::string line;
  getline(fs,line);

  std::stringstream ss(line);
  std::string key,tmp,val;

  ss >> key;
  while (ss >> tmp) {
    val += tmp + " ";
  }

  e.timecode = key;
  e.inputtxt = val;

  return fs;
}

