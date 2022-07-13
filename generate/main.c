#include <stdlib.h>
#include <time.h>

#include "generate.h"

int main() {
  srand((unsigned int)time(NULL));
  DoctorDataGenerate();
  PersonDataGenerate();
  VaccineDataGenerate();
  RecordDataGenerate();
  return 0;
}