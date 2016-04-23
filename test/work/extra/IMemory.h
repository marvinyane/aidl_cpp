/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMemory.aidl
 */
#ifndef ANDROID_IMEMORY_H
#define ANDROID_IMEMORY_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IMemory : public IInterface
{
public:
    DECLARE_META_INTERFACE(Memory);
    virtual const sp<IMemoryHeap>& getMemory(const sp<ssize_t>& offset, const sp<size_t>& size) = 0;
};

class BnMemory : public BnInterface<IMemory>
{
public:
    enum {
        GET_MEMORY = IBinder::FIRST_CALL_TRANSACTION,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IMEMORY_H
