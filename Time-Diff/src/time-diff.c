#ifndef __TIME_DIFF__
#define __TIME_DIFF__

#include "time-diff.h"

/**
 * Return 1 if the difference is negative, otherwise 0.  
 * Saves the Difference of t1 and t2 in result
 */
int timeval_subtract(struct timeval *result, 
                     struct timeval *t2, 
                     struct timeval *t1) {

    long int diff =   (t2->tv_usec + 1000000 * t2->tv_sec) 
                    - (t1->tv_usec + 1000000 * t1->tv_sec);

    result->tv_sec = diff / 1000000;
    result->tv_usec = diff % 1000000;

    return (diff < 0);
}

/**
 * Prints a Timevall struct
 */
void timeval_print(struct timeval *tv) {

    char buffer[30];
    time_t curtime;

    printf("%ld.%06ld", tv->tv_sec, tv->tv_usec);
    curtime = tv->tv_sec;
    strftime(buffer, 30, "%m-%d-%Y  %T", localtime(&curtime));
    printf(" = %s.%06ld\n", buffer, tv->tv_usec);
}

#endif // __TIME_DIFF__
