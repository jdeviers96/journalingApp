#ifndef PROCEDURES_H
#define PROCEDURES_H

#include <string>
#include <fstream>
#include <iostream>
#include "entryvec.h"

void resetFile(std::string fn);
void touchFile(std::string fn);
EntryVec readFile(std::string fn);
void writeFile(std::string fn, EntryVec &ev);

#endif // PROCEDURES_H

