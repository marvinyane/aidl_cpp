/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMemory.aidl
 */
#define LOG_TAG "Memory"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <memory/IMemory.h>

namespace android {

class BpMemory : public BpInterface<IMemory>
{
    public:
    BpMemory(const sp<IBinder>& impl)
        : BpInterface<IMemory>(impl) { }

virtual const sp<IMemoryHeap>& getMemory(const sp<ssize_t>& offset, const sp<size_t>& size)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMemory::getInterfaceDescriptor());
    remote()->transact(BnMemory::GET_MEMORY, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(Memory, "android.os.IMemory");

status_t BnMemory::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case GET_MEMORY: {
    CHECK_INTERFACE(IMemory, data, reply);
    const sp<ssize_t>& _arg0;
    const sp<size_t>& _arg1;
    int res = getMemory(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(offset);
data.%s.writeToParcel(&_data);
(size);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
