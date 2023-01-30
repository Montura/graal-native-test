#include <api/DxFeed.h>
#include <api/Connection.h>

namespace dxfeed {
  static JNIEnv* JNI;

  DxFeed& dxfeed::DxFeed::getInstance(JNIEnv_* env) {
    JNI = env;
    static DxFeed instance{};
    return instance;
  }

  DxFeed::DxFeed() :
    env_{JNI},
    timeAndSalesMapper_{env_, onClose},
    listMapper_{env_, onClose} {
  }

  TimeAndSaleMapper& DxFeed::getTimeAndSaleMapper() {
    return timeAndSalesMapper_;
  }

  ListMapper& DxFeed::getListMapper() {
    return listMapper_;
  }

  void DxFeed::onClose(jobject clazz) {
    JNI->DeleteGlobalRef(clazz);
  }
}
