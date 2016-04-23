/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMemoryHeap.aidl
 */
#ifndef ANDROID_IMEMORY_HEAP_H
#define ANDROID_IMEMORY_HEAP_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IMemoryHeap : public IInterface
{
public:
    DECLARE_META_INTERFACE(MemoryHeap);
    virtual const sp<status_t>& getHeapID(int fd, const sp<ssize_t>& size, int flags, int offset) = 0;
};

class BnMemoryHeap : public BnInterface<IMemoryHeap>
{
public:
    enum {
        GET_HEAP_ID = IBinder::FIRST_CALL_TRANSACTION,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IMEMORY_HEAP_H
