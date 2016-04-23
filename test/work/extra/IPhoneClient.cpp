/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IPhoneClient.aidl
 */
#define LOG_TAG "PhoneClient"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <phoneclient/IPhoneClient.h>

namespace android {

class BpPhoneClient : public BpInterface<IPhoneClient>
{
    public:
    BpPhoneClient(const sp<IBinder>& impl)
        : BpInterface<IPhoneClient>(impl) { }

virtual status_t Response(int token, int message, int result, int ivalue, const sp<zParcel>& extra)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPhoneClient::getInterfaceDescriptor());
    _data.writeInt32(token);
    _data.writeInt32(message);
    _data.writeInt32(result);
    _data.writeInt32(ivalue);
    return remote()->transact(BnPhoneClient::RESPONSE, _data, &reply);
}

virtual status_t Unsolicited(int message, int ivalue, const String16& svalue)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPhoneClient::getInterfaceDescriptor());
    _data.writeInt32(message);
    _data.writeInt32(ivalue);
    _data.writeString16(svalue);
    return remote()->transact(BnPhoneClient::UNSOLICITED, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(PhoneClient, "android.os.IPhoneClient");

status_t BnPhoneClient::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case RESPONSE: {
    CHECK_INTERFACE(IPhoneClient, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int _arg3;
    _arg3 = data.readInt32();
    const sp<zParcel>& _arg4;
    Response(_arg0, _arg1, _arg2, _arg3, _arg4);
data.%s.writeToParcel(&_data);
(extra);
    return NO_ERROR;
    }
case UNSOLICITED: {
    CHECK_INTERFACE(IPhoneClient, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    String16 _arg2;
    _arg2 = data.readString16();
    Unsolicited(_arg0, _arg1, _arg2);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
