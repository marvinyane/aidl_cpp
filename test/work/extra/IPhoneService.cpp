/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IPhoneService.aidl
 */
#define LOG_TAG "PhoneService"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <phoneservice/IPhoneService.h>

namespace android {

class BpPhoneService : public BpInterface<IPhoneService>
{
    public:
    BpPhoneService(const sp<IBinder>& impl)
        : BpInterface<IPhoneService>(impl) { }

virtual status_t Register(const sp<IPhoneClient>& client, int flags)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPhoneService::getInterfaceDescriptor());
    client.writeToParcel(&_data);
    _data.writeInt32(flags);
    return remote()->transact(BnPhoneService::REGISTER, _data, &reply);
}

virtual status_t Request(const sp<IPhoneClient>& client, int token, int message, int ivalue, const String16& svalue)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPhoneService::getInterfaceDescriptor());
    client.writeToParcel(&_data);
    _data.writeInt32(token);
    _data.writeInt32(message);
    _data.writeInt32(ivalue);
    _data.writeString16(svalue);
    return remote()->transact(BnPhoneService::REQUEST, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(PhoneService, "android.os.IPhoneService");

status_t BnPhoneService::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case REGISTER: {
    CHECK_INTERFACE(IPhoneService, data, reply);
    const sp<IPhoneClient>& _arg0;
    _arg0 = data.readStrongIPhoneClient();
    int _arg1;
    _arg1 = data.readInt32();
    Register(_arg0, _arg1);
    return NO_ERROR;
    }
case REQUEST: {
    CHECK_INTERFACE(IPhoneService, data, reply);
    const sp<IPhoneClient>& _arg0;
    _arg0 = data.readStrongIPhoneClient();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int _arg3;
    _arg3 = data.readInt32();
    String16 _arg4;
    _arg4 = data.readString16();
    Request(_arg0, _arg1, _arg2, _arg3, _arg4);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
