#include "shared/snowflake.h"

#include <sys/time.h>

// wait until the next millisecond, regenerate the timestamp
int_64 time_re_gen(int_64 last) {
    int_64 new_time;
    struct timeval tv;
    do {
        gettimeofday(&tv, NULL);
        new_time = (int_64) tv.tv_sec * 1000 + (int_64) tv.tv_usec / 1000;
    } while (new_time <= last);

    return new_time;
}

// get the current timestamp
int_64 time_gen() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (int_64) tv.tv_sec * 1000 + (int_64) tv.tv_usec / 1000;
}

int_64 next_id() {
    static id_worker iw = {0, 0, 0};

    int_64 ts, id;
    ts = time_gen();

    // multiple IDs generated in the same millisecond
    if (ts == (iw.last_time_stamp)) {
        iw.sequence = (iw.sequence + 1) & MASK_SEQUENCE;

        // The serial number in the same millisecond is used up, waiting until the
        // next millisecond
        if (iw.sequence == 0) {
            ts = time_re_gen(ts);
        }
    } else {
        iw.last_time_stamp = ts;
    }

    //当前时间戳比上一次时间还小，说明出错了
    if (ts < (iw.last_time_stamp)) {
        id = 0;
    } else {
        id = (ts - EPOCH) << (NODEBITS + STEPBITS) | iw.worker_id << STEPBITS |
             iw.sequence;
    }

    return id;
}