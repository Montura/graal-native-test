#ifndef __GRAALSAMPLE_H
#define __GRAALSAMPLE_H

#include "graal_isolate.h"

#if defined(__cplusplus)
extern "C" {
#endif

graal_isolatethread_t* NativeTestMain_createIsolate();

int run_main(int argc, char** argv);

void dumpSystemProperties(graal_isolatethread_t*);

#if defined(__cplusplus)
}
#endif
#endif
