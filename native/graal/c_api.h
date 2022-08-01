#ifndef __GRAALSAMPLE_H
#define __GRAALSAMPLE_H

typedef struct __graal_isolatethread_t graal_isolatethread_t;

#if defined(__cplusplus)
extern "C" {
#endif

void CInterfaceTutorial__printingInJava__293dc3e9345967e0e8fbc12bcab4dd94dd553304(graal_isolatethread_t*, char*);

void java_entry_point(graal_isolatethread_t*, my_data*);

void java_release_data(graal_isolatethread_t*, my_data*);

void java_print_day(graal_isolatethread_t*, day_of_the_week_t);

void java_entry_point2(graal_isolatethread_t*, subdata_t*, subdata_t*);

void java_entry_point3(graal_isolatethread_t*, du_t*, du_t*, d1_t*, d2_t*);

long long int getUB1_raw_value(graal_isolatethread_t*, sudata_t*);

long long int getUB1_masked_raw_value(graal_isolatethread_t*, sudata_t*);

long long int getUB1_as_Unsigned_raw_value(graal_isolatethread_t*, sudata_t*);

void java_entry_point4(graal_isolatethread_t*, sudata_t*);

int run_main(int argc, char** argv);

void vmLocatorSymbol(graal_isolatethread_t* thread);

#if defined(__cplusplus)
}
#endif
#endif
