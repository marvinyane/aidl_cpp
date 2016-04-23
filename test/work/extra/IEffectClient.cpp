/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IEffectClient.aidl
 */
#define LOG_TAG "EffectClient"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <effectclient/IEffectClient.h>

namespace android {

class BpEffectClient : public BpInterface<IEffectClient>
{
    public:
    BpEffectClient(const sp<IBinder>& impl)
        : BpInterface<IEffectClient>(impl) { }

virtual status_t controlStatusChanged(bool controlGranted)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IEffectClient::getInterfaceDescriptor());
    _data.writeInt32((int)controlGranted);
    return remote()->transact(BnEffectClient::CONTROL_STATUS_CHANGED, _data, &reply);
}

virtual status_t enableStatusChanged(bool enabled)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IEffectClient::getInterfaceDescriptor());
    _data.writeInt32((int)enabled);
    return remote()->transact(BnEffectClient::ENABLE_STATUS_CHANGED, _data, &reply);
}

virtual status_t commandExecuted(int cmdCode, int cmdSize, const sp<void>& pCmdData, int replySize, const sp<void>& pReplyData)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IEffectClient::getInterfaceDescriptor());
    _data.writeInt32(cmdCode);
    _data.writeInt32(cmdSize);
    pCmdData.writeToParcel(&_data);
    _data.writeInt32(replySize);
    return remote()->transact(BnEffectClient::COMMAND_EXECUTED, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(EffectClient, "android.os.IEffectClient");

status_t BnEffectClient::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case CONTROL_STATUS_CHANGED: {
    CHECK_INTERFACE(IEffectClient, data, reply);
    bool _arg0;
    _arg0 = data.readInt32();
    controlStatusChanged(_arg0);
    return NO_ERROR;
    }
case ENABLE_STATUS_CHANGED: {
    CHECK_INTERFACE(IEffectClient, data, reply);
    bool _arg0;
    _arg0 = data.readInt32();
    enableStatusChanged(_arg0);
    return NO_ERROR;
    }
case COMMAND_EXECUTED: {
    CHECK_INTERFACE(IEffectClient, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    const sp<void>& _arg2;
    _arg2 = data.readStrongvoid();
    int _arg3;
    _arg3 = data.readInt32();
    const sp<void>& _arg4;
    commandExecuted(_arg0, _arg1, _arg2, _arg3, _arg4);
data.%s.writeToParcel(&_data);
(pReplyData);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
