/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IStreamListener.aidl
 */
#ifndef ANDROID_ISTREAM_LISTENER_H
#define ANDROID_ISTREAM_LISTENER_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IStreamListener : public IInterface
{
public:
    DECLARE_META_INTERFACE(StreamListener);
    virtual status_t bogus_setListener() = 0;
    virtual status_t bogus_setBuffers() = 0;
    virtual status_t bogus_onBufferAvailable() = 0;
    virtual status_t queueBuffer(const sp<size_t>& index, const sp<size_t>& size) = 0;
    virtual status_t issueCommand(int cmd, bool synchronous, const sp<AMessage>& msg) = 0;
};

class BnStreamListener : public BnInterface<IStreamListener>
{
public:
    enum {
        BOGUS_SET_LISTENER = IBinder::FIRST_CALL_TRANSACTION,
        BOGUS_SET_BUFFERS,
        BOGUS_ON_BUFFER_AVAILABLE,
        QUEUE_BUFFER,
        ISSUE_COMMAND,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ISTREAM_LISTENER_H
