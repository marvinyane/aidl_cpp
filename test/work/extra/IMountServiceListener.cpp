/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMountServiceListener.aidl
 */
#define LOG_TAG "MountServiceListener"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <mountservicelistener/IMountServiceListener.h>

namespace android {

class BpMountServiceListener : public BpInterface<IMountServiceListener>
{
    public:
    BpMountServiceListener(const sp<IBinder>& impl)
        : BpInterface<IMountServiceListener>(impl) { }

virtual status_t onUsbMassStorageConnectionChanged(bool connected)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountServiceListener::getInterfaceDescriptor());
    _data.writeInt32((int)connected);
    return remote()->transact(BnMountServiceListener::ON_USB_MASS_STORAGE_CONNECTION_CHANGED, _data, &reply);
}

virtual status_t onStorageStateChanged(const String16& path, const String16& oldState, const String16& newState)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountServiceListener::getInterfaceDescriptor());
    _data.writeString16(path);
    _data.writeString16(oldState);
    _data.writeString16(newState);
    return remote()->transact(BnMountServiceListener::ON_STORAGE_STATE_CHANGED, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(MountServiceListener, "android.os.IMountServiceListener");

status_t BnMountServiceListener::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case ON_USB_MASS_STORAGE_CONNECTION_CHANGED: {
    CHECK_INTERFACE(IMountServiceListener, data, reply);
    bool _arg0;
    _arg0 = data.readInt32();
    onUsbMassStorageConnectionChanged(_arg0);
    return NO_ERROR;
    }
case ON_STORAGE_STATE_CHANGED: {
    CHECK_INTERFACE(IMountServiceListener, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    String16 _arg1;
    _arg1 = data.readString16();
    String16 _arg2;
    _arg2 = data.readString16();
    onStorageStateChanged(_arg0, _arg1, _arg2);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
