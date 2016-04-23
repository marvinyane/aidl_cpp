/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IEffect.aidl
 */
#define LOG_TAG "Effect"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <effect/IEffect.h>

namespace android {

class BpEffect : public BpInterface<IEffect>
{
    public:
    BpEffect(const sp<IBinder>& impl)
        : BpInterface<IEffect>(impl) { }

virtual const sp<status_t>& enable()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IEffect::getInterfaceDescriptor());
    remote()->transact(BnEffect::ENABLE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& disable()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IEffect::getInterfaceDescriptor());
    remote()->transact(BnEffect::DISABLE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& command(int cmdCode, int cmdSize, const sp<void>& pCmdData, int pReplySize, const sp<void>& pReplyData)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IEffect::getInterfaceDescriptor());
    _data.writeInt32(cmdCode);
    _data.writeInt32(cmdSize);
    pCmdData.writeToParcel(&_data);
    _data.writeInt32(pReplySize);
    remote()->transact(BnEffect::COMMAND, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t disconnect()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IEffect::getInterfaceDescriptor());
    return remote()->transact(BnEffect::DISCONNECT, _data, &reply);
}

virtual const sp<IMemory>& getCblk()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IEffect::getInterfaceDescriptor());
    remote()->transact(BnEffect::GET_CBLK, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(Effect, "android.os.IEffect");

status_t BnEffect::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case ENABLE: {
    CHECK_INTERFACE(IEffect, data, reply);
    int res = enable();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case DISABLE: {
    CHECK_INTERFACE(IEffect, data, reply);
    int res = disable();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case COMMAND: {
    CHECK_INTERFACE(IEffect, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    const sp<void>& _arg2;
    _arg2 = data.readStrongvoid();
    int _arg3;
    _arg3 = data.readInt32();
    const sp<void>& _arg4;
    int res = command(_arg0, _arg1, _arg2, _arg3, _arg4);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(pReplySize);
data.%s.writeToParcel(&_data);
(pReplyData);
    return NO_ERROR;
    }
case DISCONNECT: {
    CHECK_INTERFACE(IEffect, data, reply);
    disconnect();
    return NO_ERROR;
    }
case GET_CBLK: {
    CHECK_INTERFACE(IEffect, data, reply);
    int res = getCblk();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
