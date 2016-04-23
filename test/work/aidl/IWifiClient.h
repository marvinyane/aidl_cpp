/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: aidl/IWifiClient.aidl
 */
#ifndef ANDROID_IWIFI_CLIENT_H
#define ANDROID_IWIFI_CLIENT_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IWifiClient : public IInterface
{
public:
    DECLARE_META_INTERFACE(WifiClient);
    virtual status_t State(int state) = 0;
    virtual status_t ScanResults(const sp<ScannedStation>& scandata) = 0;
    virtual status_t ConfiguredStations(const sp<ConfiguredStation>& configdata) = 0;
    virtual status_t Information(const sp<WifiInformation>& info) = 0;
    virtual status_t Rssi(int rssi) = 0;
    virtual status_t LinkSpeed(int link_speed) = 0;
};

class BnWifiClient : public BnInterface<IWifiClient>
{
public:
    enum {
        STATE = IBinder::FIRST_CALL_TRANSACTION,
        SCAN_RESULTS,
        CONFIGURED_STATIONS,
        INFORMATION,
        RSSI,
        LINK_SPEED,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IWIFI_CLIENT_H
