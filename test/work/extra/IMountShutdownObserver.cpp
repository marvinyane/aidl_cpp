/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMountShutdownObserver.aidl
 */
#define LOG_TAG "MountShutdownObserver"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <mountshutdownobserver/IMountShutdownObserver.h>

namespace android {

class BpMountShutdownObserver : public BpInterface<IMountShutdownObserver>
{
    public:
    BpMountShutdownObserver(const sp<IBinder>& impl)
        : BpInterface<IMountShutdownObserver>(impl) { }

virtual status_t onShutDownComplete(int statusCode)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountShutdownObserver::getInterfaceDescriptor());
    _data.writeInt32(statusCode);
    return remote()->transact(BnMountShutdownObserver::ON_SHUT_DOWN_COMPLETE, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(MountShutdownObserver, "android.os.IMountShutdownObserver");

status_t BnMountShutdownObserver::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case ON_SHUT_DOWN_COMPLETE: {
    CHECK_INTERFACE(IMountShutdownObserver, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    onShutDownComplete(_arg0);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
