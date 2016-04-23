/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IPhoneService.aidl
 */
#ifndef ANDROID_IPHONE_SERVICE_H
#define ANDROID_IPHONE_SERVICE_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IPhoneService : public IInterface
{
public:
    DECLARE_META_INTERFACE(PhoneService);
    virtual status_t Register(const sp<IPhoneClient>& client, int flags) = 0;
    virtual status_t Request(const sp<IPhoneClient>& client, int token, int message, int ivalue, const String16& svalue) = 0;
};

class BnPhoneService : public BnInterface<IPhoneService>
{
public:
    enum {
        REGISTER = IBinder::FIRST_CALL_TRANSACTION,
        REQUEST,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IPHONE_SERVICE_H
