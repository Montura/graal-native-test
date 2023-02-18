#include "api/DxFeed.h"
#include "api/Connection.h"

namespace dxfeed {
  jobject createDxEndpoint(JNIEnv* env) {
    jclass dxEndpointClass = env->FindClass("Lcom/dxfeed/api/DXEndpoint;");
    jmethodID newBuilderMethodId = env->GetStaticMethodID(dxEndpointClass, "newBuilder", "()Lcom/dxfeed/api/DXEndpoint$Builder;");
    jobject dxEndpointBuilder = env->CallStaticObjectMethod(dxEndpointClass, newBuilderMethodId);

    jclass dxEndpointBuilderClass = env->GetObjectClass(dxEndpointBuilder);
    jmethodID buildId = env->GetMethodID(dxEndpointBuilderClass, "build", "()Lcom/dxfeed/api/DXEndpoint;");
    return env->CallObjectMethod(dxEndpointBuilder, buildId);
  }

  jobject createDxFeedConnect(JNIEnv* env, jobject dxEndpoint, const char* address) {
    jclass dxEndpointClass = env->GetObjectClass(dxEndpoint);
    jmethodID connectMethodId = env->GetMethodID(dxEndpointClass, "connect", "(Ljava/lang/String;)Lcom/dxfeed/api/DXEndpoint;");
    jstring addr = env->NewStringUTF(address);
    jobject dxEndpointConnected = env->CallObjectMethod(dxEndpoint, connectMethodId, addr);
    jmethodID getFeedId = env->GetMethodID(dxEndpointClass, "getFeed", "()Lcom/dxfeed/api/DXFeed;");
    return env->CallObjectMethod(dxEndpointConnected, getFeedId);
  }

  Connection::Connection(JNIEnv* env, const std::string& address, dxfeed::OnCloseHandler onClose) :
    env_{env},
    endpoint_(env->NewGlobalRef(createDxEndpoint(env))),
    onClose_(onClose),
    connection_(env->NewGlobalRef(createDxFeedConnect(env, endpoint_, address.c_str())))
  {}

  Subscription* Connection::createSubscription(EventType eventType) {
    return new Subscription(env_, connection_, eventType);
  }

  Connection::~Connection() {
    onClose_(endpoint_);
    onClose_(connection_);
  }
}