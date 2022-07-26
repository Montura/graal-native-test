#include <iostream>

#include <stdio.h>
#include <time.h>
#include "graal/graal_isolate.h"



extern "C" void test(graal_isolatethread_t*);
extern "C" int testC() {
    return 17;
}

int main() {
    graal_isolate_t* isolate;
    graal_isolatethread_t* thread;
    graal_create_isolate(0, &isolate, &thread);
    test(thread);

    int n = 10000000;
    for (int i = 0; i < n; i++) {
        testC();
    }
    struct timespec time1;
        for (int i = 0; i < n; i++) {
        testC();
    }
    struct timespec time2;
    printf("native time = %d\n", ((time2.tv_sec - time1.tv_sec) * 1000000000 + (time2.tv_nsec - time1.tv_nsec)) / n);
}