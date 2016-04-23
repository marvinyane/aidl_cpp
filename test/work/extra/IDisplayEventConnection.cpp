/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IDisplayEventConnection.aidl
 */
#define LOG_TAG "DisplayEventConnection"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <displayeventconnection/IDisplayEventConnection.h>

namespace android {

class BpDisplayEventConnection : public BpInterface<IDisplayEventConnection>
{
    public:
    BpDisplayEventConnection(const sp<IBinder>& impl)
        : BpInterface<IDisplayEventConnection>(impl) { }

virtual const sp<BitTube>& getDataChannel()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDisplayEventConnection::getInterfaceDescriptor());
    remote()->transact(BnDisplayEventConnection::GET_DATA_CHANNEL, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t setVsyncRate(int count)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDisplayEventConnection::getInterfaceDescriptor());
    _data.writeInt32(count);
    return remote()->transact(BnDisplayEventConnection::SET_VSYNC_RATE, _data, &reply);
}

virtual status_t requestNextVsync()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDisplayEventConnection::getInterfaceDescriptor());
    return remote()->transact(BnDisplayEventConnection::REQUEST_NEXT_VSYNC, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(DisplayEventConnection, "android.os.IDisplayEventConnection");

status_t BnDisplayEventConnection::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case GET_DATA_CHANNEL: {
    CHECK_INTERFACE(IDisplayEventConnection, data, reply);
    int res = getDataChannel();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_VSYNC_RATE: {
    CHECK_INTERFACE(IDisplayEventConnection, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    setVsyncRate(_arg0);
    return NO_ERROR;
    }
case REQUEST_NEXT_VSYNC: {
    CHECK_INTERFACE(IDisplayEventConnection, data, reply);
    requestNextVsync();
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
