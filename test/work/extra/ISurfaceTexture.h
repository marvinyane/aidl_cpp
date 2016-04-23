/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ISurfaceTexture.aidl
 */
#ifndef ANDROID_ISURFACE_TEXTURE_H
#define ANDROID_ISURFACE_TEXTURE_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class ISurfaceTexture : public IInterface
{
public:
    DECLARE_META_INTERFACE(SurfaceTexture);
    virtual const sp<status_t>& requestBuffer(int slot, const sp<GraphicBuffer>& buf) = 0;
    virtual const sp<status_t>& setBufferCount(int bufferCount) = 0;
    virtual const sp<status_t>& dequeueBuffer(int buf, int w, int h, int format, int usage) = 0;
    virtual const sp<status_t>& queueBuffer(int buf, const sp<QueueBufferInput>& input, const sp<QueueBufferOutput>& output) = 0;
    virtual const sp<status_t>& cancelBuffer(int buf) = 0;
    virtual int query(int what, int value) = 0;
    virtual const sp<status_t>& setSynchronousMode(bool enabled) = 0;
    virtual const sp<status_t>& connect(int api, const sp<QueueBufferOutput>& output) = 0;
    virtual const sp<status_t>& disconnect(int api) = 0;
};

class BnSurfaceTexture : public BnInterface<ISurfaceTexture>
{
public:
    enum {
        REQUEST_BUFFER = IBinder::FIRST_CALL_TRANSACTION,
        SET_BUFFER_COUNT,
        DEQUEUE_BUFFER,
        QUEUE_BUFFER,
        CANCEL_BUFFER,
        QUERY,
        SET_SYNCHRONOUS_MODE,
        CONNECT,
        DISCONNECT,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ISURFACE_TEXTURE_H
