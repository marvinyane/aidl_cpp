/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ICrypto.aidl
 */
#ifndef ANDROID_ICRYPTO_H
#define ANDROID_ICRYPTO_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class ICrypto : public IInterface
{
public:
    DECLARE_META_INTERFACE(Crypto);
    virtual const sp<status_t>& initCheck() = 0;
    virtual bool isCryptoSchemeSupported(const sp<uint8_t>& uuid) = 0;
    virtual const sp<status_t>& createPlugin(const sp<uint8_t>& uuid, const sp<void>& data, long size) = 0;
    virtual const sp<status_t>& destroyPlugin() = 0;
    virtual bool requiresSecureDecoderComponent(const CString& mime) = 0;
    virtual long decrypt(bool secure, const sp<uint8_t>& key, const sp<uint8_t>& iv, int mode, const sp<void>& srcPtr, const sp<SubSample>& subSamples, long numSubSamples, const sp<void>& dstPtr, const sp<AString>& errorDetailMsg) = 0;
};

class BnCrypto : public BnInterface<ICrypto>
{
public:
    enum {
        INIT_CHECK = IBinder::FIRST_CALL_TRANSACTION,
        IS_CRYPTO_SCHEME_SUPPORTED,
        CREATE_PLUGIN,
        DESTROY_PLUGIN,
        REQUIRES_SECURE_DECODER_COMPONENT,
        DECRYPT,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ICRYPTO_H
