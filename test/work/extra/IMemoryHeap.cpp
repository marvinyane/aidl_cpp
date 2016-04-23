/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMemoryHeap.aidl
 */
#define LOG_TAG "MemoryHeap"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <memoryheap/IMemoryHeap.h>

namespace android {

class BpMemoryHeap : public BpInterface<IMemoryHeap>
{
    public:
    BpMemoryHeap(const sp<IBinder>& impl)
        : BpInterface<IMemoryHeap>(impl) { }

virtual const sp<status_t>& getHeapID(int fd, const sp<ssize_t>& size, int flags, int offset)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMemoryHeap::getInterfaceDescriptor());
    remote()->transact(BnMemoryHeap::GET_HEAP_ID, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(MemoryHeap, "android.os.IMemoryHeap");

status_t BnMemoryHeap::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case GET_HEAP_ID: {
    CHECK_INTERFACE(IMemoryHeap, data, reply);
    int _arg0;
    const sp<ssize_t>& _arg1;
    int _arg2;
    int _arg3;
    int res = getHeapID(_arg0, _arg1, _arg2, _arg3);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(fd);
data.%s.writeToParcel(&_data);
(size);
data._data.writeInt32(%s);
(flags);
data._data.writeInt32(%s);
(offset);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
