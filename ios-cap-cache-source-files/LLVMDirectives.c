#include <stdio.h>
#include <stddef.h>
#include <memory.h>

#include <unwind.h>

int LLVMDirectives() {
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_UA_CLEANUP_PHASE:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_UA_CLEANUP_PHASE)));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_UA_CLEANUP_PHASE:PropertyInfo:signedness=$%s$\n", ((_UA_CLEANUP_PHASE>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_UA_CLEANUP_PHASE:PropertyInfo:value=%lX\n", ((unsigned long)_UA_CLEANUP_PHASE));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_UA_END_OF_STACK:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_UA_END_OF_STACK)));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_UA_END_OF_STACK:PropertyInfo:signedness=$%s$\n", ((_UA_END_OF_STACK>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_UA_END_OF_STACK:PropertyInfo:value=%lX\n", ((unsigned long)_UA_END_OF_STACK));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_UA_FORCE_UNWIND:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_UA_FORCE_UNWIND)));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_UA_FORCE_UNWIND:PropertyInfo:signedness=$%s$\n", ((_UA_FORCE_UNWIND>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_UA_FORCE_UNWIND:PropertyInfo:value=%lX\n", ((unsigned long)_UA_FORCE_UNWIND));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_UA_HANDLER_FRAME:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_UA_HANDLER_FRAME)));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_UA_HANDLER_FRAME:PropertyInfo:signedness=$%s$\n", ((_UA_HANDLER_FRAME>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_UA_HANDLER_FRAME:PropertyInfo:value=%lX\n", ((unsigned long)_UA_HANDLER_FRAME));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_UA_SEARCH_PHASE:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_UA_SEARCH_PHASE)));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_UA_SEARCH_PHASE:PropertyInfo:signedness=$%s$\n", ((_UA_SEARCH_PHASE>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_UA_SEARCH_PHASE:PropertyInfo:value=%lX\n", ((unsigned long)_UA_SEARCH_PHASE));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_CONTINUE_UNWIND:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_URC_CONTINUE_UNWIND)));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_CONTINUE_UNWIND:PropertyInfo:signedness=$%s$\n", ((_URC_CONTINUE_UNWIND>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_CONTINUE_UNWIND:PropertyInfo:value=%lX\n", ((unsigned long)_URC_CONTINUE_UNWIND));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_END_OF_STACK:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_URC_END_OF_STACK)));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_END_OF_STACK:PropertyInfo:signedness=$%s$\n", ((_URC_END_OF_STACK>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_END_OF_STACK:PropertyInfo:value=%lX\n", ((unsigned long)_URC_END_OF_STACK));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_FATAL_PHASE1_ERROR:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_URC_FATAL_PHASE1_ERROR)));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_FATAL_PHASE1_ERROR:PropertyInfo:signedness=$%s$\n", ((_URC_FATAL_PHASE1_ERROR>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_FATAL_PHASE1_ERROR:PropertyInfo:value=%lX\n", ((unsigned long)_URC_FATAL_PHASE1_ERROR));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_FATAL_PHASE2_ERROR:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_URC_FATAL_PHASE2_ERROR)));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_FATAL_PHASE2_ERROR:PropertyInfo:signedness=$%s$\n", ((_URC_FATAL_PHASE2_ERROR>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_FATAL_PHASE2_ERROR:PropertyInfo:value=%lX\n", ((unsigned long)_URC_FATAL_PHASE2_ERROR));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_FOREIGN_EXCEPTION_CAUGHT:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_URC_FOREIGN_EXCEPTION_CAUGHT)));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_FOREIGN_EXCEPTION_CAUGHT:PropertyInfo:signedness=$%s$\n", ((_URC_FOREIGN_EXCEPTION_CAUGHT>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_FOREIGN_EXCEPTION_CAUGHT:PropertyInfo:value=%lX\n", ((unsigned long)_URC_FOREIGN_EXCEPTION_CAUGHT));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_HANDLER_FOUND:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_URC_HANDLER_FOUND)));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_HANDLER_FOUND:PropertyInfo:signedness=$%s$\n", ((_URC_HANDLER_FOUND>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_HANDLER_FOUND:PropertyInfo:value=%lX\n", ((unsigned long)_URC_HANDLER_FOUND));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_INSTALL_CONTEXT:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_URC_INSTALL_CONTEXT)));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_INSTALL_CONTEXT:PropertyInfo:signedness=$%s$\n", ((_URC_INSTALL_CONTEXT>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_INSTALL_CONTEXT:PropertyInfo:value=%lX\n", ((unsigned long)_URC_INSTALL_CONTEXT));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_NORMAL_STOP:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_URC_NORMAL_STOP)));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_NORMAL_STOP:PropertyInfo:signedness=$%s$\n", ((_URC_NORMAL_STOP>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_NORMAL_STOP:PropertyInfo:value=%lX\n", ((unsigned long)_URC_NORMAL_STOP));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_NO_REASON:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(_URC_NO_REASON)));
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_NO_REASON:PropertyInfo:signedness=$%s$\n", ((_URC_NO_REASON>=0 ? 1 : 0)) ? "UNSIGNED" : "SIGNED");
    printf("NativeCodeInfo:LLVMDirectives:ConstantInfo:_URC_NO_REASON:PropertyInfo:value=%lX\n", ((unsigned long)_URC_NO_REASON));
    printf("NativeCodeInfo:LLVMDirectives:StructInfo:struct__Unwind_Exception:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(struct _Unwind_Exception)));
    printf("NativeCodeInfo:LLVMDirectives:StructInfo:struct__Unwind_Exception:StructFieldInfo:exception_class:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct _Unwind_Exception *) 0)->exception_class)));
    printf("NativeCodeInfo:LLVMDirectives:StructInfo:struct__Unwind_Exception:StructFieldInfo:exception_class:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct _Unwind_Exception, exception_class)));
    printf("NativeCodeInfo:LLVMDirectives:StructInfo:struct__Unwind_Exception:StructFieldInfo:exception_cleanup:PropertyInfo:size=%lu\n", ((unsigned long)sizeof(((struct _Unwind_Exception *) 0)->exception_cleanup)));
    printf("NativeCodeInfo:LLVMDirectives:StructInfo:struct__Unwind_Exception:StructFieldInfo:exception_cleanup:PropertyInfo:offset=%lu\n", ((unsigned long)offsetof(struct _Unwind_Exception, exception_cleanup)));
    return 0;
}

int main(void) {
    return LLVMDirectives();
}
