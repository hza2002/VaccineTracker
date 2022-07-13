#ifndef _ID_H
#define _ID_H

char id[20];

void IntToChar(int val, char id[], int l);  // int转char
void RandomId(char id[],
              int seed);    // 产生随机身份证号
void GetKeyNum(char id[]);  // 生成校验位

#endif