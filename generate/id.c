#include "id.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// int转char
void IntToChar(int val, char id[], int l) {
  while (val > 0) {
    id[--l] = (val % 10) + 48;
    val = val / 10;
  }
}
// 产生随机身份证号，存储在id字符串
void GetKeyNum(char id[]) {
  int w[18] = {7, 9, 10, 5,  8, 4, 2, 1, 6,
               3, 7, 9,  10, 5, 8, 4, 2, 1};  // w是位权值数组
  int sum = 0;
  for (int i = 0; i < 17; i++)  //前17位的位权值相加
  {
    sum += w[i] * (id[i] - 48);
  }
  for (int i = 0; i <= 9; i++)  //遍历判断，求最后一位
  {
    if ((sum + i) % 11 == 1) {
      id[17] = i + 48;
      return;
    }
  }
  id[17] = 'X';
}

void RandomId(char id[], int seed) {
  int l = 0;  //位置

  srand((unsigned)time(NULL) + seed * 1234);

  for (int i = 0; i < 18; i++) id[i] = '0';
  int Addr_ID;   // 110000-659001  110000 + rand()%549002
  int Year_ID;   // 1900-2022      1900 + rand()%123
  int Month_ID;  // 01-12          1 + rand()%12
  int Day_ID;    // 01-28          1 + rand()%28
  int Key_word;  // 100-999	    100+rand()%900
  int random = rand();

  /* 前17位按照一定要求随机生成 */
  Addr_ID = 110000 + random % 549002;
  IntToChar(Addr_ID, id, l + 6);
  Year_ID = 1900 + random % 123;
  IntToChar(Year_ID, id, l + 10);
  Month_ID = 1 + random % 12;
  IntToChar(Month_ID, id, l + 12);
  Day_ID = 1 + random % 28;
  IntToChar(Day_ID, id, l + 14);
  Key_word = 100 + random % 900;
  IntToChar(Key_word, id, l + 17);

  /* 计算第18位 */
  GetKeyNum(id);
}