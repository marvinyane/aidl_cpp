/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ICrypto.aidl
 */
#define LOG_TAG "Crypto"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <crypto/ICrypto.h>

namespace android {

class BpCrypto : public BpInterface<ICrypto>
{
    public:
    BpCrypto(const sp<IBinder>& impl)
        : BpInterface<ICrypto>(impl) { }

virtual const sp<status_t>& initCheck()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICrypto::getInterfaceDescriptor());
    remote()->transact(BnCrypto::INIT_CHECK, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual bool isCryptoSchemeSupported(const sp<uint8_t>& uuid)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICrypto::getInterfaceDescriptor());
    uuid.writeToParcel(&_data);
    remote()->transact(BnCrypto::IS_CRYPTO_SCHEME_SUPPORTED, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& createPlugin(const sp<uint8_t>& uuid, const sp<void>& data, long size)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICrypto::getInterfaceDescriptor());
    uuid.writeToParcel(&_data);
    data.writeToParcel(&_data);
    _data.writeInt64(size);
    remote()->transact(BnCrypto::CREATE_PLUGIN, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& destroyPlugin()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICrypto::getInterfaceDescriptor());
    remote()->transact(BnCrypto::DESTROY_PLUGIN, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual bool requiresSecureDecoderComponent(const CString& mime)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICrypto::getInterfaceDescriptor());
    _data.writeCString(mime);
    remote()->transact(BnCrypto::REQUIRES_SECURE_DECODER_COMPONENT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual long decrypt(bool secure, const sp<uint8_t>& key, const sp<uint8_t>& iv, int mode, const sp<void>& srcPtr, const sp<SubSample>& subSamples, long numSubSamples, const sp<void>& dstPtr, const sp<AString>& errorDetailMsg)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICrypto::getInterfaceDescriptor());
    _data.writeInt32((int)secure);
    key.writeToParcel(&_data);
    iv.writeToParcel(&_data);
    _data.writeInt32(mode);
    srcPtr.writeToParcel(&_data);
    subSamples.writeToParcel(&_data);
    _data.writeInt64(numSubSamples);
    remote()->transact(BnCrypto::DECRYPT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(Crypto, "android.os.ICrypto");

status_t BnCrypto::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case INIT_CHECK: {
    CHECK_INTERFACE(ICrypto, data, reply);
    int res = initCheck();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case IS_CRYPTO_SCHEME_SUPPORTED: {
    CHECK_INTERFACE(ICrypto, data, reply);
    const sp<uint8_t>& _arg0;
    _arg0 = data.readStronguint8_t();
    int res = isCryptoSchemeSupported(_arg0)? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CREATE_PLUGIN: {
    CHECK_INTERFACE(ICrypto, data, reply);
    const sp<uint8_t>& _arg0;
    _arg0 = data.readStronguint8_t();
    const sp<void>& _arg1;
    _arg1 = data.readStrongvoid();
    long _arg2;
    _arg2 = data.readInt64();
    int res = createPlugin(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case DESTROY_PLUGIN: {
    CHECK_INTERFACE(ICrypto, data, reply);
    int res = destroyPlugin();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case REQUIRES_SECURE_DECODER_COMPONENT: {
    CHECK_INTERFACE(ICrypto, data, reply);
    CString _arg0;
    _arg0 = data.readCString();
    int res = requiresSecureDecoderComponent(_arg0)? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case DECRYPT: {
    CHECK_INTERFACE(ICrypto, data, reply);
    bool _arg0;
    _arg0 = data.readInt32();
    const sp<uint8_t>& _arg1;
    _arg1 = data.readStronguint8_t();
    const sp<uint8_t>& _arg2;
    _arg2 = data.readStronguint8_t();
    int _arg3;
    _arg3 = data.readInt32();
    const sp<void>& _arg4;
    _arg4 = data.readStrongvoid();
    const sp<SubSample>& _arg5;
    _arg5 = data.readStrongSubSample();
    long _arg6;
    _arg6 = data.readInt64();
    const sp<void>& _arg7;
    const sp<AString>& _arg8;
    int res = decrypt(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(dstPtr);
data.%s.writeToParcel(&_data);
(errorDetailMsg);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
