/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ICameraRecordingProxyListener.aidl
 */
#ifndef ANDROID_ICAMERA_RECORDING_PROXY_LISTENER_H
#define ANDROID_ICAMERA_RECORDING_PROXY_LISTENER_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class ICameraRecordingProxyListener : public IInterface
{
public:
    DECLARE_META_INTERFACE(CameraRecordingProxyListener);
    virtual status_t dataCallbackTimestamp(long timestamp, int msgType, const sp<IMemory>& data) = 0;
};

class BnCameraRecordingProxyListener : public BnInterface<ICameraRecordingProxyListener>
{
public:
    enum {
        DATA_CALLBACK_TIMESTAMP = IBinder::FIRST_CALL_TRANSACTION,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ICAMERA_RECORDING_PROXY_LISTENER_H
