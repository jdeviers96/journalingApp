#ifndef ENTRYVEC_H
#define ENTRYVEC_H

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>

#include <entry.h>


class EntryVec {
  private:
    std::vector<Entry> entries;
  public:
    // Constructors:
    EntryVec(); // default

    //Mutators:
    void pushFileEntry(Entry e);
    void popFileEntry();


    // Accessors:
    std::vector<Entry> getFileEntries();

    // Destructor:

    // Overloaded insertion/extraction operators
    friend std::ostream & operator<<(std::ostream &os, EntryVec &l);
    friend std::istream & operator>>(std::istream &is, EntryVec &l);
    friend std::fstream & operator>>(std::fstream &fs, EntryVec &l);

    // Overloaded fcts:
    int size();
    void clear();
};

#endif
