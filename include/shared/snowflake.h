#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H

#include <stdlib.h>
#include <sys/time.h>

/*
  https://github.com/52fhy/snowflake-c
  snowflake ID 生成策略
  毫秒级时间41位+机器ID 10位+毫秒内序列12位。
  前41bits是以微秒为单位的timestamp。
  接着10bits是事先配置好的机器ID。
  最后12bits是累加计数器。
  macheine id(10bits)标明最多只能有1024台机器同时产生ID，
  sequence number(12bits)也标明1台机器1ms中最多产生4096个ID，
  *注意点，因为使用到位移运算，所以需要64位操作系统，不然生成的ID会有可能不正确
*/

typedef long long int_64;

// IdWorker Struct
struct IdWorker {
  int_64 worker_id;
  int_64 last_time_stamp;
  unsigned int sequence;
};

typedef struct IdWorker id_worker;

// 2^12 -1 = 4095
#define MASK_SEQUENCE 4095

// Epoch is set to the twitter snowflake epoch of Nov 04 2010 01:42:54 UTC in
// milliseconds
#define EPOCH 1288834974657

// NodeBits holds the number of bits to use for Node
#define NODEBITS 10

// StepBits holds the number of bits to use for Step
#define STEPBITS 12

int_64 time_re_gen(int_64);
int_64 time_gen();
int_64 next_id();

#endif