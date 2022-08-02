#include "graal/c_api.h"
#include "system_properties.h"

// how to run: ./native -Ddxfeed.address=172.13.14.15
int main(int argc, char** argv) {
    graal_isolatethread_t* thread = NativeTestMain_createIsolate();
    if (thread && argc == 2) {
        testSystemProperties(argc, argv, thread);
        graal_tear_down_isolate(thread);
    }
}