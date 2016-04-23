/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ICamera.aidl
 */
#ifndef ANDROID_ICAMERA_H
#define ANDROID_ICAMERA_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class ICamera : public IInterface
{
public:
    DECLARE_META_INTERFACE(Camera);
    virtual status_t disconnect() = 0;
    virtual const sp<status_t>& setPreviewDisplay(const sp<Surface>& surface) = 0;
    virtual const sp<status_t>& setPreviewTexture(const sp<ISurfaceTexture>& surfaceTexture) = 0;
    virtual status_t setPreviewCallbackFlag(int flag) = 0;
    virtual const sp<status_t>& startPreview() = 0;
    virtual const sp<status_t>& stopPreview() = 0;
    virtual const sp<status_t>& autoFocus() = 0;
    virtual const sp<status_t>& cancelAutoFocus() = 0;
    virtual const sp<status_t>& takePicture(int msgType) = 0;
    virtual const sp<status_t>& setParameters(const String8& params) = 0;
    virtual String8 getParameters() = 0;
    virtual const sp<status_t>& sendCommand(int cmd, int arg1, int arg2) = 0;
    virtual const sp<status_t>& connect(const sp<ICameraClient>& client) = 0;
    virtual const sp<status_t>& lock() = 0;
    virtual const sp<status_t>& unlock() = 0;
    virtual bool previewEnabled() = 0;
    virtual const sp<status_t>& startRecording() = 0;
    virtual status_t stopRecording() = 0;
    virtual bool recordingEnabled() = 0;
    virtual status_t releaseRecordingFrame(const sp<IMemory>& mem) = 0;
    virtual const sp<status_t>& storeMetaDataInBuffers(bool enabled) = 0;
};

class BnCamera : public BnInterface<ICamera>
{
public:
    enum {
        DISCONNECT = IBinder::FIRST_CALL_TRANSACTION,
        SET_PREVIEW_DISPLAY,
        SET_PREVIEW_TEXTURE,
        SET_PREVIEW_CALLBACK_FLAG,
        START_PREVIEW,
        STOP_PREVIEW,
        AUTO_FOCUS,
        CANCEL_AUTO_FOCUS,
        TAKE_PICTURE,
        SET_PARAMETERS,
        GET_PARAMETERS,
        SEND_COMMAND,
        CONNECT,
        LOCK,
        UNLOCK,
        PREVIEW_ENABLED,
        START_RECORDING,
        STOP_RECORDING,
        RECORDING_ENABLED,
        RELEASE_RECORDING_FRAME,
        STORE_META_DATA_IN_BUFFERS,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ICAMERA_H
