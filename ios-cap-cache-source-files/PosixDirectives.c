#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#ifndef _LARGEFILE64_SOURCE
#define _LARGEFILE64_SOURCE
#endif
#ifndef _DARWIN_USE_64_BIT_INODE
#define _DARWIN_USE_64_BIT_INODE
#endif

#include <stdio.h>
#include <stddef.h>
#include <memory.h>

#include <dlfcn.h>
#include <fcntl.h>
#include <limits.h>
#include <locale.h>
#include <pthread.h>
#include <pwd.h>
#include <signal.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/utsname.h>
#include <time.h>
#include <unistd.h>
#include <Foundation/Foundation.h>
#include <mach/mach.h>
#include <mach/mach_time.h>
#include <mach-o/dyld.h>
#include <sys/sysctl.h>
#include <sys/syslimits.h>

int PosixDirectives() {
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:CTL_HW:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(CTL_HW)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:CTL_HW:PropertyInfo:signedness=$%s$\n", ((CTL_HW>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:CTL_HW:PropertyInfo:value=%lX\n", ((unsigned long)CTL_HW));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:CTL_KERN:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(CTL_KERN)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:CTL_KERN:PropertyInfo:signedness=$%s$\n", ((CTL_KERN>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:CTL_KERN:PropertyInfo:value=%lX\n", ((unsigned long)CTL_KERN));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:EBADF:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(EBADF)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:EBADF:PropertyInfo:signedness=$%s$\n", ((EBADF>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:EBADF:PropertyInfo:value=%lX\n", ((unsigned long)EBADF));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:EBUSY:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(EBUSY)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:EBUSY:PropertyInfo:signedness=$%s$\n", ((EBUSY>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:EBUSY:PropertyInfo:value=%lX\n", ((unsigned long)EBUSY));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:ECHILD:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(ECHILD)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:ECHILD:PropertyInfo:signedness=$%s$\n", ((ECHILD>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:ECHILD:PropertyInfo:value=%lX\n", ((unsigned long)ECHILD));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:EINTR:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(EINTR)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:EINTR:PropertyInfo:signedness=$%s$\n", ((EINTR>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:EINTR:PropertyInfo:value=%lX\n", ((unsigned long)EINTR));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:EPERM:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(EPERM)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:EPERM:PropertyInfo:signedness=$%s$\n", ((EPERM>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:EPERM:PropertyInfo:value=%lX\n", ((unsigned long)EPERM));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:ESRCH:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(ESRCH)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:ESRCH:PropertyInfo:signedness=$%s$\n", ((ESRCH>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:ESRCH:PropertyInfo:value=%lX\n", ((unsigned long)ESRCH));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:ETIMEDOUT:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(ETIMEDOUT)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:ETIMEDOUT:PropertyInfo:signedness=$%s$\n", ((ETIMEDOUT>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:ETIMEDOUT:PropertyInfo:value=%lX\n", ((unsigned long)ETIMEDOUT));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:HW_MEMSIZE:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(HW_MEMSIZE)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:HW_MEMSIZE:PropertyInfo:signedness=$%s$\n", ((HW_MEMSIZE>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:HW_MEMSIZE:PropertyInfo:value=%lX\n", ((unsigned long)HW_MEMSIZE));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:KERN_IPC:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(KERN_IPC)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:KERN_IPC:PropertyInfo:signedness=$%s$\n", ((KERN_IPC>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:KERN_IPC:PropertyInfo:value=%lX\n", ((unsigned long)KERN_IPC));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:KIPC_MAXSOCKBUF:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(KIPC_MAXSOCKBUF)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:KIPC_MAXSOCKBUF:PropertyInfo:signedness=$%s$\n", ((KIPC_MAXSOCKBUF>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:KIPC_MAXSOCKBUF:PropertyInfo:value=%lX\n", ((unsigned long)KIPC_MAXSOCKBUF));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_ALL:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(LC_ALL)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_ALL:PropertyInfo:signedness=$%s$\n", ((LC_ALL>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_ALL:PropertyInfo:value=%lX\n", ((unsigned long)LC_ALL));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_COLLATE:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(LC_COLLATE)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_COLLATE:PropertyInfo:signedness=$%s$\n", ((LC_COLLATE>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_COLLATE:PropertyInfo:value=%lX\n", ((unsigned long)LC_COLLATE));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_CTYPE:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(LC_CTYPE)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_CTYPE:PropertyInfo:signedness=$%s$\n", ((LC_CTYPE>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_CTYPE:PropertyInfo:value=%lX\n", ((unsigned long)LC_CTYPE));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_MESSAGES:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(LC_MESSAGES)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_MESSAGES:PropertyInfo:signedness=$%s$\n", ((LC_MESSAGES>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_MESSAGES:PropertyInfo:value=%lX\n", ((unsigned long)LC_MESSAGES));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_MONETARY:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(LC_MONETARY)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_MONETARY:PropertyInfo:signedness=$%s$\n", ((LC_MONETARY>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_MONETARY:PropertyInfo:value=%lX\n", ((unsigned long)LC_MONETARY));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_NUMERIC:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(LC_NUMERIC)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_NUMERIC:PropertyInfo:signedness=$%s$\n", ((LC_NUMERIC>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_NUMERIC:PropertyInfo:value=%lX\n", ((unsigned long)LC_NUMERIC));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_TIME:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(LC_TIME)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_TIME:PropertyInfo:signedness=$%s$\n", ((LC_TIME>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:LC_TIME:PropertyInfo:value=%lX\n", ((unsigned long)LC_TIME));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:MAP_ANON:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(MAP_ANON)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:MAP_ANON:PropertyInfo:signedness=$%s$\n", ((MAP_ANON>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:MAP_ANON:PropertyInfo:value=%lX\n", ((unsigned long)MAP_ANON));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:MAP_FAILED:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(MAP_FAILED)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:MAP_FAILED:PropertyInfo:value=%lX\n", ((unsigned long)MAP_FAILED));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:MAP_FIXED:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(MAP_FIXED)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:MAP_FIXED:PropertyInfo:signedness=$%s$\n", ((MAP_FIXED>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:MAP_FIXED:PropertyInfo:value=%lX\n", ((unsigned long)MAP_FIXED));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:MAP_NORESERVE:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(MAP_NORESERVE)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:MAP_NORESERVE:PropertyInfo:signedness=$%s$\n", ((MAP_NORESERVE>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:MAP_NORESERVE:PropertyInfo:value=%lX\n", ((unsigned long)MAP_NORESERVE));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:MAP_PRIVATE:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(MAP_PRIVATE)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:MAP_PRIVATE:PropertyInfo:signedness=$%s$\n", ((MAP_PRIVATE>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:MAP_PRIVATE:PropertyInfo:value=%lX\n", ((unsigned long)MAP_PRIVATE));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:MAP_SHARED:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(MAP_SHARED)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:MAP_SHARED:PropertyInfo:signedness=$%s$\n", ((MAP_SHARED>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:MAP_SHARED:PropertyInfo:value=%lX\n", ((unsigned long)MAP_SHARED));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:NAME_MAX:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(NAME_MAX)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:NAME_MAX:PropertyInfo:signedness=$%s$\n", ((NAME_MAX>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:NAME_MAX:PropertyInfo:value=%lX\n", ((unsigned long)NAME_MAX));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:OPEN_MAX:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(OPEN_MAX)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:OPEN_MAX:PropertyInfo:signedness=$%s$\n", ((OPEN_MAX>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:OPEN_MAX:PropertyInfo:value=%lX\n", ((unsigned long)OPEN_MAX));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:O_CREAT:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(O_CREAT)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:O_CREAT:PropertyInfo:signedness=$%s$\n", ((O_CREAT>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:O_CREAT:PropertyInfo:value=%lX\n", ((unsigned long)O_CREAT));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:O_RDONLY:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(O_RDONLY)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:O_RDONLY:PropertyInfo:signedness=$%s$\n", ((O_RDONLY>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:O_RDONLY:PropertyInfo:value=%lX\n", ((unsigned long)O_RDONLY));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:O_RDWR:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(O_RDWR)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:O_RDWR:PropertyInfo:signedness=$%s$\n", ((O_RDWR>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:O_RDWR:PropertyInfo:value=%lX\n", ((unsigned long)O_RDWR));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:O_WRONLY:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(O_WRONLY)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:O_WRONLY:PropertyInfo:signedness=$%s$\n", ((O_WRONLY>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:O_WRONLY:PropertyInfo:value=%lX\n", ((unsigned long)O_WRONLY));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PATH_MAX:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(PATH_MAX)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PATH_MAX:PropertyInfo:signedness=$%s$\n", ((PATH_MAX>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PATH_MAX:PropertyInfo:value=%lX\n", ((unsigned long)PATH_MAX));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PATH_MAX:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(PATH_MAX)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PATH_MAX:PropertyInfo:signedness=$%s$\n", ((PATH_MAX>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PATH_MAX:PropertyInfo:value=%lX\n", ((unsigned long)PATH_MAX));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PROT_EXEC:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(PROT_EXEC)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PROT_EXEC:PropertyInfo:signedness=$%s$\n", ((PROT_EXEC>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PROT_EXEC:PropertyInfo:value=%lX\n", ((unsigned long)PROT_EXEC));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PROT_NONE:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(PROT_NONE)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PROT_NONE:PropertyInfo:signedness=$%s$\n", ((PROT_NONE>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PROT_NONE:PropertyInfo:value=%lX\n", ((unsigned long)PROT_NONE));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PROT_READ:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(PROT_READ)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PROT_READ:PropertyInfo:signedness=$%s$\n", ((PROT_READ>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PROT_READ:PropertyInfo:value=%lX\n", ((unsigned long)PROT_READ));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PROT_WRITE:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(PROT_WRITE)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PROT_WRITE:PropertyInfo:signedness=$%s$\n", ((PROT_WRITE>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PROT_WRITE:PropertyInfo:value=%lX\n", ((unsigned long)PROT_WRITE));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PTHREAD_CREATE_JOINABLE:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(PTHREAD_CREATE_JOINABLE)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PTHREAD_CREATE_JOINABLE:PropertyInfo:signedness=$%s$\n", ((PTHREAD_CREATE_JOINABLE>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PTHREAD_CREATE_JOINABLE:PropertyInfo:value=%lX\n", ((unsigned long)PTHREAD_CREATE_JOINABLE));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PTHREAD_STACK_MIN:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(PTHREAD_STACK_MIN)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PTHREAD_STACK_MIN:PropertyInfo:signedness=$%s$\n", ((PTHREAD_STACK_MIN>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:PTHREAD_STACK_MIN:PropertyInfo:value=%lX\n", ((unsigned long)PTHREAD_STACK_MIN));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:RLIMIT_NOFILE:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(RLIMIT_NOFILE)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:RLIMIT_NOFILE:PropertyInfo:signedness=$%s$\n", ((RLIMIT_NOFILE>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:RLIMIT_NOFILE:PropertyInfo:value=%lX\n", ((unsigned long)RLIMIT_NOFILE));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:RTLD_DEFAULT:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(RTLD_DEFAULT)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:RTLD_DEFAULT:PropertyInfo:value=%lX\n", ((unsigned long)RTLD_DEFAULT));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:RTLD_GLOBAL:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(RTLD_GLOBAL)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:RTLD_GLOBAL:PropertyInfo:signedness=$%s$\n", ((RTLD_GLOBAL>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:RTLD_GLOBAL:PropertyInfo:value=%lX\n", ((unsigned long)RTLD_GLOBAL));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:RTLD_LAZY:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(RTLD_LAZY)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:RTLD_LAZY:PropertyInfo:signedness=$%s$\n", ((RTLD_LAZY>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:RTLD_LAZY:PropertyInfo:value=%lX\n", ((unsigned long)RTLD_LAZY));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:RTLD_LOCAL:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(RTLD_LOCAL)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:RTLD_LOCAL:PropertyInfo:signedness=$%s$\n", ((RTLD_LOCAL>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:RTLD_LOCAL:PropertyInfo:value=%lX\n", ((unsigned long)RTLD_LOCAL));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:RTLD_NOW:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(RTLD_NOW)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:RTLD_NOW:PropertyInfo:signedness=$%s$\n", ((RTLD_NOW>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:RTLD_NOW:PropertyInfo:value=%lX\n", ((unsigned long)RTLD_NOW));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SA_NODEFER:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SA_NODEFER)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SA_NODEFER:PropertyInfo:signedness=$%s$\n", ((SA_NODEFER>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SA_NODEFER:PropertyInfo:value=%lX\n", ((unsigned long)SA_NODEFER));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SA_RESTART:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SA_RESTART)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SA_RESTART:PropertyInfo:signedness=$%s$\n", ((SA_RESTART>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SA_RESTART:PropertyInfo:value=%lX\n", ((unsigned long)SA_RESTART));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SA_SIGINFO:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SA_SIGINFO)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SA_SIGINFO:PropertyInfo:signedness=$%s$\n", ((SA_SIGINFO>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SA_SIGINFO:PropertyInfo:value=%lX\n", ((unsigned long)SA_SIGINFO));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SEEK_CUR:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SEEK_CUR)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SEEK_CUR:PropertyInfo:signedness=$%s$\n", ((SEEK_CUR>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SEEK_CUR:PropertyInfo:value=%lX\n", ((unsigned long)SEEK_CUR));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SEEK_SET:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SEEK_SET)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SEEK_SET:PropertyInfo:signedness=$%s$\n", ((SEEK_SET>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SEEK_SET:PropertyInfo:value=%lX\n", ((unsigned long)SEEK_SET));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SIG_BLOCK:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIG_BLOCK)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SIG_BLOCK:PropertyInfo:signedness=$%s$\n", ((SIG_BLOCK>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SIG_BLOCK:PropertyInfo:value=%lX\n", ((unsigned long)SIG_BLOCK));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SIG_DFL:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIG_DFL)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SIG_DFL:PropertyInfo:value=%lX\n", ((unsigned long)SIG_DFL));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SIG_ERR:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIG_ERR)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SIG_ERR:PropertyInfo:value=%lX\n", ((unsigned long)SIG_ERR));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SIG_IGN:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIG_IGN)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SIG_IGN:PropertyInfo:value=%lX\n", ((unsigned long)SIG_IGN));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SIG_SETMASK:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIG_SETMASK)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SIG_SETMASK:PropertyInfo:signedness=$%s$\n", ((SIG_SETMASK>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SIG_SETMASK:PropertyInfo:value=%lX\n", ((unsigned long)SIG_SETMASK));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SIG_UNBLOCK:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIG_UNBLOCK)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SIG_UNBLOCK:PropertyInfo:signedness=$%s$\n", ((SIG_UNBLOCK>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:SIG_UNBLOCK:PropertyInfo:value=%lX\n", ((unsigned long)SIG_UNBLOCK));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:_CS_DARWIN_USER_TEMP_DIR:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_CS_DARWIN_USER_TEMP_DIR)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:_CS_DARWIN_USER_TEMP_DIR:PropertyInfo:signedness=$%s$\n", ((_CS_DARWIN_USER_TEMP_DIR>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:_CS_DARWIN_USER_TEMP_DIR:PropertyInfo:value=%lX\n", ((unsigned long)_CS_DARWIN_USER_TEMP_DIR));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:_SC_CLK_TCK:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_SC_CLK_TCK)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:_SC_CLK_TCK:PropertyInfo:signedness=$%s$\n", ((_SC_CLK_TCK>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:_SC_CLK_TCK:PropertyInfo:value=%lX\n", ((unsigned long)_SC_CLK_TCK));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:_SC_OPEN_MAX:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_SC_OPEN_MAX)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:_SC_OPEN_MAX:PropertyInfo:signedness=$%s$\n", ((_SC_OPEN_MAX>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:_SC_OPEN_MAX:PropertyInfo:value=%lX\n", ((unsigned long)_SC_OPEN_MAX));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:_SC_PAGESIZE:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_SC_PAGESIZE)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:_SC_PAGESIZE:PropertyInfo:signedness=$%s$\n", ((_SC_PAGESIZE>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:_SC_PAGESIZE:PropertyInfo:value=%lX\n", ((unsigned long)_SC_PAGESIZE));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:_SC_PAGE_SIZE:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_SC_PAGE_SIZE)));
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:_SC_PAGE_SIZE:PropertyInfo:signedness=$%s$\n", ((_SC_PAGE_SIZE>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:ConstantInfo:_SC_PAGE_SIZE:PropertyInfo:value=%lX\n", ((unsigned long)_SC_PAGE_SIZE));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGEMT:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGEMT)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGEMT:PropertyInfo:signedness=$%s$\n", ((SIGEMT>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGEMT:PropertyInfo:value=%lX\n", ((unsigned long)SIGEMT));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGINFO:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGINFO)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGINFO:PropertyInfo:signedness=$%s$\n", ((SIGINFO>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGINFO:PropertyInfo:value=%lX\n", ((unsigned long)SIGINFO));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGABRT:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGABRT)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGABRT:PropertyInfo:signedness=$%s$\n", ((SIGABRT>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGABRT:PropertyInfo:value=%lX\n", ((unsigned long)SIGABRT));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGALRM:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGALRM)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGALRM:PropertyInfo:signedness=$%s$\n", ((SIGALRM>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGALRM:PropertyInfo:value=%lX\n", ((unsigned long)SIGALRM));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGBUS:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGBUS)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGBUS:PropertyInfo:signedness=$%s$\n", ((SIGBUS>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGBUS:PropertyInfo:value=%lX\n", ((unsigned long)SIGBUS));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGCHLD:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGCHLD)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGCHLD:PropertyInfo:signedness=$%s$\n", ((SIGCHLD>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGCHLD:PropertyInfo:value=%lX\n", ((unsigned long)SIGCHLD));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGCONT:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGCONT)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGCONT:PropertyInfo:signedness=$%s$\n", ((SIGCONT>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGCONT:PropertyInfo:value=%lX\n", ((unsigned long)SIGCONT));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGFPE:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGFPE)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGFPE:PropertyInfo:signedness=$%s$\n", ((SIGFPE>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGFPE:PropertyInfo:value=%lX\n", ((unsigned long)SIGFPE));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGHUP:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGHUP)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGHUP:PropertyInfo:signedness=$%s$\n", ((SIGHUP>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGHUP:PropertyInfo:value=%lX\n", ((unsigned long)SIGHUP));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGILL:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGILL)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGILL:PropertyInfo:signedness=$%s$\n", ((SIGILL>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGILL:PropertyInfo:value=%lX\n", ((unsigned long)SIGILL));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGINT:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGINT)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGINT:PropertyInfo:signedness=$%s$\n", ((SIGINT>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGINT:PropertyInfo:value=%lX\n", ((unsigned long)SIGINT));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGIO:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGIO)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGIO:PropertyInfo:signedness=$%s$\n", ((SIGIO>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGIO:PropertyInfo:value=%lX\n", ((unsigned long)SIGIO));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGIOT:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGIOT)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGIOT:PropertyInfo:signedness=$%s$\n", ((SIGIOT>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGIOT:PropertyInfo:value=%lX\n", ((unsigned long)SIGIOT));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGKILL:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGKILL)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGKILL:PropertyInfo:signedness=$%s$\n", ((SIGKILL>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGKILL:PropertyInfo:value=%lX\n", ((unsigned long)SIGKILL));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGPIPE:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGPIPE)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGPIPE:PropertyInfo:signedness=$%s$\n", ((SIGPIPE>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGPIPE:PropertyInfo:value=%lX\n", ((unsigned long)SIGPIPE));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGPROF:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGPROF)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGPROF:PropertyInfo:signedness=$%s$\n", ((SIGPROF>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGPROF:PropertyInfo:value=%lX\n", ((unsigned long)SIGPROF));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGQUIT:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGQUIT)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGQUIT:PropertyInfo:signedness=$%s$\n", ((SIGQUIT>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGQUIT:PropertyInfo:value=%lX\n", ((unsigned long)SIGQUIT));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGSEGV:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGSEGV)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGSEGV:PropertyInfo:signedness=$%s$\n", ((SIGSEGV>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGSEGV:PropertyInfo:value=%lX\n", ((unsigned long)SIGSEGV));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGSTOP:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGSTOP)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGSTOP:PropertyInfo:signedness=$%s$\n", ((SIGSTOP>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGSTOP:PropertyInfo:value=%lX\n", ((unsigned long)SIGSTOP));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGSYS:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGSYS)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGSYS:PropertyInfo:signedness=$%s$\n", ((SIGSYS>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGSYS:PropertyInfo:value=%lX\n", ((unsigned long)SIGSYS));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGTERM:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGTERM)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGTERM:PropertyInfo:signedness=$%s$\n", ((SIGTERM>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGTERM:PropertyInfo:value=%lX\n", ((unsigned long)SIGTERM));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGTRAP:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGTRAP)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGTRAP:PropertyInfo:signedness=$%s$\n", ((SIGTRAP>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGTRAP:PropertyInfo:value=%lX\n", ((unsigned long)SIGTRAP));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGTSTP:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGTSTP)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGTSTP:PropertyInfo:signedness=$%s$\n", ((SIGTSTP>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGTSTP:PropertyInfo:value=%lX\n", ((unsigned long)SIGTSTP));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGTTIN:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGTTIN)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGTTIN:PropertyInfo:signedness=$%s$\n", ((SIGTTIN>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGTTIN:PropertyInfo:value=%lX\n", ((unsigned long)SIGTTIN));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGTTOU:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGTTOU)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGTTOU:PropertyInfo:signedness=$%s$\n", ((SIGTTOU>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGTTOU:PropertyInfo:value=%lX\n", ((unsigned long)SIGTTOU));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGURG:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGURG)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGURG:PropertyInfo:signedness=$%s$\n", ((SIGURG>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGURG:PropertyInfo:value=%lX\n", ((unsigned long)SIGURG));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGUSR1:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGUSR1)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGUSR1:PropertyInfo:signedness=$%s$\n", ((SIGUSR1>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGUSR1:PropertyInfo:value=%lX\n", ((unsigned long)SIGUSR1));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGUSR2:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGUSR2)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGUSR2:PropertyInfo:signedness=$%s$\n", ((SIGUSR2>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGUSR2:PropertyInfo:value=%lX\n", ((unsigned long)SIGUSR2));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGVTALRM:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGVTALRM)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGVTALRM:PropertyInfo:signedness=$%s$\n", ((SIGVTALRM>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGVTALRM:PropertyInfo:value=%lX\n", ((unsigned long)SIGVTALRM));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGWINCH:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGWINCH)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGWINCH:PropertyInfo:signedness=$%s$\n", ((SIGWINCH>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGWINCH:PropertyInfo:value=%lX\n", ((unsigned long)SIGWINCH));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGXCPU:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGXCPU)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGXCPU:PropertyInfo:signedness=$%s$\n", ((SIGXCPU>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGXCPU:PropertyInfo:value=%lX\n", ((unsigned long)SIGXCPU));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGXFSZ:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(SIGXFSZ)));
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGXFSZ:PropertyInfo:signedness=$%s$\n", ((SIGXFSZ>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:PosixDirectives:EnumInfo:int:EnumConstantInfo:SIGXFSZ:PropertyInfo:value=%lX\n", ((unsigned long)SIGXFSZ));
    printf("NativeCodeInfo:PosixDirectives:PointerToInfo:long_long_int:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(long long int)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        long long int fieldHolder = all_bits_set;
        is_unsigned = fieldHolder > 0;
        printf("NativeCodeInfo:PosixDirectives:PointerToInfo:long_long_int:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:PointerToInfo:pthread_t:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(pthread_t)));
    printf("NativeCodeInfo:PosixDirectives:PointerToInfo:sigset_t:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(sigset_t)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:Dl_info:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(Dl_info)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:Dl_info:StructFieldInfo:dli_fbase:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((Dl_info *) 0)->dli_fbase)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:Dl_info:StructFieldInfo:dli_fbase:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(Dl_info, dli_fbase)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:Dl_info:StructFieldInfo:dli_fname:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((Dl_info *) 0)->dli_fname)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:Dl_info:StructFieldInfo:dli_fname:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(Dl_info, dli_fname)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:Dl_info:StructFieldInfo:dli_saddr:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((Dl_info *) 0)->dli_saddr)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:Dl_info:StructFieldInfo:dli_saddr:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(Dl_info, dli_saddr)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:Dl_info:StructFieldInfo:dli_sname:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((Dl_info *) 0)->dli_sname)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:Dl_info:StructFieldInfo:dli_sname:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(Dl_info, dli_sname)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:NSOperatingSystemVersion:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(NSOperatingSystemVersion)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:NSOperatingSystemVersion:StructFieldInfo:majorVersion:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((NSOperatingSystemVersion *) 0)->majorVersion)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:NSOperatingSystemVersion:StructFieldInfo:majorVersion:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(NSOperatingSystemVersion, majorVersion)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        NSOperatingSystemVersion fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.majorVersion = all_bits_set;
        is_unsigned = fieldHolder.majorVersion > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:NSOperatingSystemVersion:StructFieldInfo:majorVersion:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:NSOperatingSystemVersion:StructFieldInfo:minorVersion:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((NSOperatingSystemVersion *) 0)->minorVersion)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:NSOperatingSystemVersion:StructFieldInfo:minorVersion:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(NSOperatingSystemVersion, minorVersion)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        NSOperatingSystemVersion fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.minorVersion = all_bits_set;
        is_unsigned = fieldHolder.minorVersion > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:NSOperatingSystemVersion:StructFieldInfo:minorVersion:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:NSOperatingSystemVersion:StructFieldInfo:patchVersion:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((NSOperatingSystemVersion *) 0)->patchVersion)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:NSOperatingSystemVersion:StructFieldInfo:patchVersion:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(NSOperatingSystemVersion, patchVersion)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        NSOperatingSystemVersion fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.patchVersion = all_bits_set;
        is_unsigned = fieldHolder.patchVersion > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:NSOperatingSystemVersion:StructFieldInfo:patchVersion:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:pthread_attr_t:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(pthread_attr_t)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:pthread_cond_t:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(pthread_cond_t)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:pthread_condattr_t:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(pthread_condattr_t)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:pthread_mutex_t:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(pthread_mutex_t)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:siginfo_t:StructFieldInfo:si_addr:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((siginfo_t *) 0)->si_addr)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:siginfo_t:StructFieldInfo:si_addr:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(siginfo_t, si_addr)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:siginfo_t:StructFieldInfo:si_code:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((siginfo_t *) 0)->si_code)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:siginfo_t:StructFieldInfo:si_code:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(siginfo_t, si_code)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        siginfo_t fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.si_code = all_bits_set;
        is_unsigned = fieldHolder.si_code > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:siginfo_t:StructFieldInfo:si_code:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:siginfo_t:StructFieldInfo:si_errno:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((siginfo_t *) 0)->si_errno)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:siginfo_t:StructFieldInfo:si_errno:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(siginfo_t, si_errno)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        siginfo_t fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.si_errno = all_bits_set;
        is_unsigned = fieldHolder.si_errno > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:siginfo_t:StructFieldInfo:si_errno:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:siginfo_t:StructFieldInfo:si_signo:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((siginfo_t *) 0)->si_signo)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:siginfo_t:StructFieldInfo:si_signo:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(siginfo_t, si_signo)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        siginfo_t fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.si_signo = all_bits_set;
        is_unsigned = fieldHolder.si_signo > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:siginfo_t:StructFieldInfo:si_signo:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct___darwin_mcontext64:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(struct __darwin_mcontext64)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct___darwin_mcontext64:StructFieldInfo:__ss___fp:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct __darwin_mcontext64 *) 0)->__ss.__fp)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct___darwin_mcontext64:StructFieldInfo:__ss___fp:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct __darwin_mcontext64, __ss.__fp)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        struct __darwin_mcontext64 fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.__ss.__fp = all_bits_set;
        is_unsigned = fieldHolder.__ss.__fp > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:struct___darwin_mcontext64:StructFieldInfo:__ss___fp:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct___darwin_mcontext64:StructFieldInfo:__ss___lr:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct __darwin_mcontext64 *) 0)->__ss.__lr)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct___darwin_mcontext64:StructFieldInfo:__ss___lr:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct __darwin_mcontext64, __ss.__lr)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        struct __darwin_mcontext64 fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.__ss.__lr = all_bits_set;
        is_unsigned = fieldHolder.__ss.__lr > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:struct___darwin_mcontext64:StructFieldInfo:__ss___lr:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct___darwin_mcontext64:StructFieldInfo:__ss___pc:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct __darwin_mcontext64 *) 0)->__ss.__pc)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct___darwin_mcontext64:StructFieldInfo:__ss___pc:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct __darwin_mcontext64, __ss.__pc)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        struct __darwin_mcontext64 fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.__ss.__pc = all_bits_set;
        is_unsigned = fieldHolder.__ss.__pc > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:struct___darwin_mcontext64:StructFieldInfo:__ss___pc:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct___darwin_mcontext64:StructFieldInfo:__ss___sp:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct __darwin_mcontext64 *) 0)->__ss.__sp)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct___darwin_mcontext64:StructFieldInfo:__ss___sp:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct __darwin_mcontext64, __ss.__sp)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        struct __darwin_mcontext64 fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.__ss.__sp = all_bits_set;
        is_unsigned = fieldHolder.__ss.__sp > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:struct___darwin_mcontext64:StructFieldInfo:__ss___sp:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct___darwin_mcontext64:StructFieldInfo:__ss___x:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct __darwin_mcontext64 *) 0)->__ss.__x)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct___darwin_mcontext64:StructFieldInfo:__ss___x:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct __darwin_mcontext64, __ss.__x)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_mach_timebase_info:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(struct mach_timebase_info)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_mach_timebase_info:StructFieldInfo:denom:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct mach_timebase_info *) 0)->denom)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_mach_timebase_info:StructFieldInfo:denom:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct mach_timebase_info, denom)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        struct mach_timebase_info fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.denom = all_bits_set;
        is_unsigned = fieldHolder.denom > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_mach_timebase_info:StructFieldInfo:denom:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_mach_timebase_info:StructFieldInfo:numer:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct mach_timebase_info *) 0)->numer)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_mach_timebase_info:StructFieldInfo:numer:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct mach_timebase_info, numer)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        struct mach_timebase_info fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.numer = all_bits_set;
        is_unsigned = fieldHolder.numer > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_mach_timebase_info:StructFieldInfo:numer:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_passwd:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(struct passwd)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_passwd:StructFieldInfo:pw_dir:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct passwd *) 0)->pw_dir)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_passwd:StructFieldInfo:pw_dir:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct passwd, pw_dir)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_passwd:StructFieldInfo:pw_name:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct passwd *) 0)->pw_name)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_passwd:StructFieldInfo:pw_name:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct passwd, pw_name)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_rlimit:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(struct rlimit)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_rlimit:StructFieldInfo:rlim_cur:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct rlimit *) 0)->rlim_cur)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_rlimit:StructFieldInfo:rlim_cur:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct rlimit, rlim_cur)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        struct rlimit fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.rlim_cur = all_bits_set;
        is_unsigned = fieldHolder.rlim_cur > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_rlimit:StructFieldInfo:rlim_cur:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_rlimit:StructFieldInfo:rlim_max:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct rlimit *) 0)->rlim_max)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_rlimit:StructFieldInfo:rlim_max:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct rlimit, rlim_max)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        struct rlimit fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.rlim_max = all_bits_set;
        is_unsigned = fieldHolder.rlim_max > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_rlimit:StructFieldInfo:rlim_max:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_sigaction:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(struct sigaction)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_sigaction:StructFieldInfo:sa_flags:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct sigaction *) 0)->sa_flags)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_sigaction:StructFieldInfo:sa_flags:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct sigaction, sa_flags)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        struct sigaction fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.sa_flags = all_bits_set;
        is_unsigned = fieldHolder.sa_flags > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_sigaction:StructFieldInfo:sa_flags:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_sigaction:StructFieldInfo:sa_handler:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct sigaction *) 0)->sa_handler)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_sigaction:StructFieldInfo:sa_handler:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct sigaction, sa_handler)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_sigaction:StructFieldInfo:sa_mask:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct sigaction *) 0)->sa_mask)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_sigaction:StructFieldInfo:sa_mask:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct sigaction, sa_mask)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_sigaction:StructFieldInfo:sa_sigaction:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct sigaction *) 0)->sa_sigaction)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_sigaction:StructFieldInfo:sa_sigaction:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct sigaction, sa_sigaction)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_stat:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(struct stat)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_stat:StructFieldInfo:st_size:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct stat *) 0)->st_size)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_stat:StructFieldInfo:st_size:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct stat, st_size)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        struct stat fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.st_size = all_bits_set;
        is_unsigned = fieldHolder.st_size > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_stat:StructFieldInfo:st_size:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_timespec:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(struct timespec)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_timespec:StructFieldInfo:tv_nsec:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct timespec *) 0)->tv_nsec)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_timespec:StructFieldInfo:tv_nsec:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct timespec, tv_nsec)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        struct timespec fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.tv_nsec = all_bits_set;
        is_unsigned = fieldHolder.tv_nsec > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_timespec:StructFieldInfo:tv_nsec:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_timespec:StructFieldInfo:tv_sec:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct timespec *) 0)->tv_sec)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_timespec:StructFieldInfo:tv_sec:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct timespec, tv_sec)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        struct timespec fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.tv_sec = all_bits_set;
        is_unsigned = fieldHolder.tv_sec > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_timespec:StructFieldInfo:tv_sec:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_timeval:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(struct timeval)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_timeval:StructFieldInfo:tv_sec:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct timeval *) 0)->tv_sec)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_timeval:StructFieldInfo:tv_sec:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct timeval, tv_sec)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        struct timeval fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.tv_sec = all_bits_set;
        is_unsigned = fieldHolder.tv_sec > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_timeval:StructFieldInfo:tv_sec:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_timeval:StructFieldInfo:tv_usec:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct timeval *) 0)->tv_usec)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_timeval:StructFieldInfo:tv_usec:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct timeval, tv_usec)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        struct timeval fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.tv_usec = all_bits_set;
        is_unsigned = fieldHolder.tv_usec > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_timeval:StructFieldInfo:tv_usec:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_tms:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(struct tms)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_tms:StructFieldInfo:tms_cstime:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct tms *) 0)->tms_cstime)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_tms:StructFieldInfo:tms_cstime:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct tms, tms_cstime)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        struct tms fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.tms_cstime = all_bits_set;
        is_unsigned = fieldHolder.tms_cstime > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_tms:StructFieldInfo:tms_cstime:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_tms:StructFieldInfo:tms_cutime:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct tms *) 0)->tms_cutime)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_tms:StructFieldInfo:tms_cutime:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct tms, tms_cutime)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        struct tms fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.tms_cutime = all_bits_set;
        is_unsigned = fieldHolder.tms_cutime > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_tms:StructFieldInfo:tms_cutime:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_tms:StructFieldInfo:tms_stime:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct tms *) 0)->tms_stime)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_tms:StructFieldInfo:tms_stime:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct tms, tms_stime)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        struct tms fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.tms_stime = all_bits_set;
        is_unsigned = fieldHolder.tms_stime > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_tms:StructFieldInfo:tms_stime:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_tms:StructFieldInfo:tms_utime:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct tms *) 0)->tms_utime)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_tms:StructFieldInfo:tms_utime:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct tms, tms_utime)));
    {
        int is_unsigned;
        unsigned long all_bits_set = -1;
        struct tms fieldHolder;
        memset(&fieldHolder, 0x0, sizeof(fieldHolder));
        fieldHolder.tms_utime = all_bits_set;
        is_unsigned = fieldHolder.tms_utime > 0;
        printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_tms:StructFieldInfo:tms_utime:PropertyInfo:signedness=$%s$\n", (is_unsigned) ? "UNSIGNED" : "SIGNED");
    }
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_utsname:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(struct utsname)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_utsname:StructFieldInfo:machine:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct utsname *) 0)->machine)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_utsname:StructFieldInfo:machine:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct utsname, machine)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_utsname:StructFieldInfo:nodename:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct utsname *) 0)->nodename)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_utsname:StructFieldInfo:nodename:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct utsname, nodename)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_utsname:StructFieldInfo:release:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct utsname *) 0)->release)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_utsname:StructFieldInfo:release:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct utsname, release)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_utsname:StructFieldInfo:sysname:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct utsname *) 0)->sysname)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_utsname:StructFieldInfo:sysname:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct utsname, sysname)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_utsname:StructFieldInfo:version:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct utsname *) 0)->version)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:struct_utsname:StructFieldInfo:version:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct utsname, version)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:ucontext_t:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(ucontext_t)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:ucontext_t:StructFieldInfo:uc_mcontext:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((ucontext_t *) 0)->uc_mcontext)));
    printf("NativeCodeInfo:PosixDirectives:StructInfo:ucontext_t:StructFieldInfo:uc_mcontext:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(ucontext_t, uc_mcontext)));
    return 0;
}

int main(void) {
    return PosixDirectives();
}
