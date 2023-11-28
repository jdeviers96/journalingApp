#include <entry.h>

int main() {
  Entry e;

  if ((e.timecode == "") and (e.inputtxt == "")) {
    return 0;
  }
  return 1;

}