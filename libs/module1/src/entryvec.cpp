#include <entry.h>
#include <entryvec.h>



// Constructors:
EntryVec::EntryVec() {} // default

//Mutators:
void EntryVec::pushFileEntry(Entry e) {
  (this->entries).push_back(e);
}
void EntryVec::popFileEntry() {
  (this->entries).pop_back();
}


// Accessors:
std::vector<Entry> EntryVec::getFileEntries() {
  return entries;
}


// Overloaded size() fct:
int EntryVec::size() {
  return (this->entries).size();
}


std::ostream & operator<<(std::ostream &os, EntryVec &l) {
  for (int i=0; i<l.getFileEntries().size(); i++) {
    os << l.getFileEntries()[i]; // No \n b/c uses Entry's overloaded << which prints newlines.
  }
  return os;
}

std::istream & operator>>(std::istream &is, EntryVec &l) {
  Entry e;
  is >> e;
  l.pushFileEntry(e);
  return is;
}

std::fstream & operator>>(std::fstream &fs, EntryVec &l) {
  Entry e;
  while (fs >> e) {
    l.pushFileEntry(e);
  }
  return fs;
}
