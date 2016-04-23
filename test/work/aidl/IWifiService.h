/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: aidl/IWifiService.aidl
 */
#ifndef ANDROID_IWIFI_SERVICE_H
#define ANDROID_IWIFI_SERVICE_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IWifiService : public IInterface
{
public:
    DECLARE_META_INTERFACE(WifiService);
    virtual status_t Register(const sp<IWifiClient>& client, int flags) = 0;
    virtual status_t SetEnabled(bool enabled) = 0;
    virtual status_t SendCommand(int command, int arg1, int arg2) = 0;
    virtual status_t AddOrUpdateNetwork(const sp<ConfiguredStation>& cs) = 0;
};

class BnWifiService : public BnInterface<IWifiService>
{
public:
    enum {
        REGISTER = IBinder::FIRST_CALL_TRANSACTION,
        SET_ENABLED,
        SEND_COMMAND,
        ADD_OR_UPDATE_NETWORK,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IWIFI_SERVICE_H
