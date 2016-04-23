/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ICameraRecordingProxy.aidl
 */
#ifndef ANDROID_ICAMERA_RECORDING_PROXY_H
#define ANDROID_ICAMERA_RECORDING_PROXY_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class ICameraRecordingProxy : public IInterface
{
public:
    DECLARE_META_INTERFACE(CameraRecordingProxy);
    virtual const sp<status_t>& startRecording(const sp<ICameraRecordingProxyListener>& listener) = 0;
    virtual status_t stopRecording() = 0;
    virtual status_t releaseRecordingFrame(const sp<IMemory>& mem) = 0;
};

class BnCameraRecordingProxy : public BnInterface<ICameraRecordingProxy>
{
public:
    enum {
        START_RECORDING = IBinder::FIRST_CALL_TRANSACTION,
        STOP_RECORDING,
        RELEASE_RECORDING_FRAME,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ICAMERA_RECORDING_PROXY_H
