/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IStreamSource.aidl
 */
#ifndef ANDROID_ISTREAM_SOURCE_H
#define ANDROID_ISTREAM_SOURCE_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IStreamSource : public IInterface
{
public:
    DECLARE_META_INTERFACE(StreamSource);
    virtual status_t setListener(const sp<IStreamListener>& listener) = 0;
    virtual status_t setBuffers(const sp<IMemory>& buffers) = 0;
    virtual status_t onBufferAvailable(const sp<size_t>& index) = 0;
    virtual status_t bogus_queueBuffer() = 0;
    virtual status_t bogus_issueCommand() = 0;
};

class BnStreamSource : public BnInterface<IStreamSource>
{
public:
    enum {
        SET_LISTENER = IBinder::FIRST_CALL_TRANSACTION,
        SET_BUFFERS,
        ON_BUFFER_AVAILABLE,
        BOGUS_QUEUE_BUFFER,
        BOGUS_ISSUE_COMMAND,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ISTREAM_SOURCE_H
