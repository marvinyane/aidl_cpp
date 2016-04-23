/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ICameraClient.aidl
 */
#ifndef ANDROID_ICAMERA_CLIENT_H
#define ANDROID_ICAMERA_CLIENT_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class ICameraClient : public IInterface
{
public:
    DECLARE_META_INTERFACE(CameraClient);
    virtual status_t notifyCallback(int msgType, int ext1, int ext2) = 0;
    virtual status_t dataCallback(int msgType, const sp<IMemory>& data, const sp<camera_frame_metadata_t>& metadata) = 0;
    virtual status_t dataCallbackTimestamp(long timestamp, int msgType, const sp<IMemory>& data) = 0;
};

class BnCameraClient : public BnInterface<ICameraClient>
{
public:
    enum {
        NOTIFY_CALLBACK = IBinder::FIRST_CALL_TRANSACTION,
        DATA_CALLBACK,
        DATA_CALLBACK_TIMESTAMP,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ICAMERA_CLIENT_H
