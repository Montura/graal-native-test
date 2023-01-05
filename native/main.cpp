#include "graal/graal_isolate.h"

void testLib();
extern "C" void test(graal_isolatethread_t*);
extern "C" int testC();


int main() {
    graal_isolate_t* isolate;
    graal_isolatethread_t* thread;
    graal_create_isolate(nullptr, &isolate, &thread);
    testLib();
    test(thread);
}