#include <cstdio>
#include <ctime>

#include "graal_isolate.h"

void testLib();
extern "C" void test(graal_isolatethread_t*);
extern "C" int testC();


int main() {
    graal_isolate_t* isolate;
    graal_isolatethread_t* thread;
    graal_create_isolate(nullptr, &isolate, &thread);
    testLib();
    test(thread);

    int n = 10000000;
    for (int i = 0; i < n; i++) {
        testC();
    }
    timespec time1;
    timespec_get(&time1, TIME_UTC);
    for (int i = 0; i < n; i++) {
        testC();
    }
    timespec time2;
    timespec_get(&time2, TIME_UTC);
    printf("native time = %ld\n", ((time2.tv_sec - time1.tv_sec) * 1000000000 + (time2.tv_nsec - time1.tv_nsec)) / n);
}