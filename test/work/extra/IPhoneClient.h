/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IPhoneClient.aidl
 */
#ifndef ANDROID_IPHONE_CLIENT_H
#define ANDROID_IPHONE_CLIENT_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IPhoneClient : public IInterface
{
public:
    DECLARE_META_INTERFACE(PhoneClient);
    virtual status_t Response(int token, int message, int result, int ivalue, const sp<zParcel>& extra) = 0;
    virtual status_t Unsolicited(int message, int ivalue, const String16& svalue) = 0;
};

class BnPhoneClient : public BnInterface<IPhoneClient>
{
public:
    enum {
        RESPONSE = IBinder::FIRST_CALL_TRANSACTION,
        UNSOLICITED,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IPHONE_CLIENT_H
