#include "id.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int Finish_ID[20];
int l = 0;

char GetKeyNum() {
  char keyword;
  char Right_Val[20] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
  int Cmp_ID[20] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
  int Sum_ID = 0;
  int Temp_ID[20];  //用来临时存储乘后数据
  for (int i = 0; i < 17; i++) {
    Temp_ID[i] = Cmp_ID[i] * Finish_ID[i];
  }
  for (int i = 0; i < 17; i++) {
    Sum_ID = Sum_ID + Temp_ID[i];
  }
  Sum_ID = Sum_ID % 11;
  keyword = Right_Val[Sum_ID];
  return keyword;
}

void split(int Number, int count, int temprary) {
  int k = l;
  temprary = temprary / 10;
  for (l; l < k + count; l++) {
    Finish_ID[l] = Number / temprary;
    Number = Number % temprary;
    temprary = temprary / 10;
  }
  return;
}

int Digit(int Number) {
  int temprary = 1;
  int count = 0;
  while (1) {
    if (Number < temprary) {
      count++;
      goto outport;
    } else {
      temprary = temprary * 10;
      count++;
    }
  }
outport:
  count--;
  split(Number, count, temprary);
  return count;
}

int main() {
  for (int p = 0; p < 10; ++p) {
    int Addr_ID;   // 110000-659001  110000 + rand()%549001
    int Year_ID;   // 1900-1996     1900 + rand()%97
    int Month_ID;  // 01-12         1 + rand()%11
    int Day_ID;    // 01-28         1 + rand()%27
    int Key_ID;    // 100-999       100+rand()%899
    int Cmp_ID;

    Addr_ID = (1 + rand() % 5) * 100000 + (1 + rand() % 2) * 10000;
    Digit(Addr_ID);
    Year_ID = 1900 + rand() % 97;
    Digit(Year_ID);
    Month_ID = 10 + rand() % 2;
    Digit(Month_ID);
    Day_ID = 10 + rand() % 17;
    Digit(Day_ID);
    Key_ID = 100 + rand() % 899;
    Digit(Key_ID);

    char keyword;
    keyword = GetKeyNum();

    for (int i = 0; i < 17; i++) {
      printf("%d", Finish_ID[i]);
    }
    printf("%c\n", keyword);
  }
  return 0;
}