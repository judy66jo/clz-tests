#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "clz_function.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0

int main(int argc, char const *argv[])
{

    struct timespec start = {0, 0};
    struct timespec end = {0, 0};

    if (argc < 2) return -1;

    uint32_t x = atoi(argv[1]);
    int i, loop = 10000;

    //printf("recursive     %i\n",clz_recursive(x));
    //printf("iteration     %i\n",clz_iteration(x));
    //printf("binary search %i\n",clz_binary_search(x));
    //printf("byte-shift    %i\n",clz_byte_shift(x));
    //printf("harley        %i\n",clz_harley(x));

    //recursive
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < loop; i++) {
        clz_recursive(x);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf,", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);

    //iteration
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < loop; i++) {
        clz_iteration(x);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf,", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);

    //binary search
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < loop; i++) {
        clz_binary_search(x);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf,", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);

    //byte-shift
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < loop; i++) {
        clz_byte_shift(x);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf\n", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);

    //harley
    /*clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < loop; i++) {
        clz_harley(x);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf\n", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);*/

    return 0;
}
