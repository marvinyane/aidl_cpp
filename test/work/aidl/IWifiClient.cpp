/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: aidl/IWifiClient.aidl
 */
#define LOG_TAG "WifiClient"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <wificlient/IWifiClient.h>

namespace android {

class BpWifiClient : public BpInterface<IWifiClient>
{
    public:
    BpWifiClient(const sp<IBinder>& impl)
        : BpInterface<IWifiClient>(impl) { }

virtual status_t State(int state)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IWifiClient::getInterfaceDescriptor());
    _data.writeInt32(state);
    return remote()->transact(BnWifiClient::STATE, _data, &reply);
}

virtual status_t ScanResults(const sp<ScannedStation>& scandata)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IWifiClient::getInterfaceDescriptor());
    scandata.writeToParcel(&_data);
    return remote()->transact(BnWifiClient::SCAN_RESULTS, _data, &reply);
}

virtual status_t ConfiguredStations(const sp<ConfiguredStation>& configdata)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IWifiClient::getInterfaceDescriptor());
    configdata.writeToParcel(&_data);
    return remote()->transact(BnWifiClient::CONFIGURED_STATIONS, _data, &reply);
}

virtual status_t Information(const sp<WifiInformation>& info)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IWifiClient::getInterfaceDescriptor());
    info.writeToParcel(&_data);
    return remote()->transact(BnWifiClient::INFORMATION, _data, &reply);
}

virtual status_t Rssi(int rssi)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IWifiClient::getInterfaceDescriptor());
    _data.writeInt32(rssi);
    return remote()->transact(BnWifiClient::RSSI, _data, &reply);
}

virtual status_t LinkSpeed(int link_speed)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IWifiClient::getInterfaceDescriptor());
    _data.writeInt32(link_speed);
    return remote()->transact(BnWifiClient::LINK_SPEED, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(WifiClient, "android.os.IWifiClient");

status_t BnWifiClient::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case STATE: {
    CHECK_INTERFACE(IWifiClient, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    State(_arg0);
    return NO_ERROR;
    }
case SCAN_RESULTS: {
    CHECK_INTERFACE(IWifiClient, data, reply);
    const sp<ScannedStation>& _arg0;
    _arg0 = data.readStrongScannedStation();
    ScanResults(_arg0);
    return NO_ERROR;
    }
case CONFIGURED_STATIONS: {
    CHECK_INTERFACE(IWifiClient, data, reply);
    const sp<ConfiguredStation>& _arg0;
    _arg0 = data.readStrongConfiguredStation();
    ConfiguredStations(_arg0);
    return NO_ERROR;
    }
case INFORMATION: {
    CHECK_INTERFACE(IWifiClient, data, reply);
    const sp<WifiInformation>& _arg0;
    _arg0 = data.readStrongWifiInformation();
    Information(_arg0);
    return NO_ERROR;
    }
case RSSI: {
    CHECK_INTERFACE(IWifiClient, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    Rssi(_arg0);
    return NO_ERROR;
    }
case LINK_SPEED: {
    CHECK_INTERFACE(IWifiClient, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    LinkSpeed(_arg0);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
