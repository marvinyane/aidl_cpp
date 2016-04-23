/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: ./aidl/IWifiService.aidl
 */
#define LOG_TAG "WifiService"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <wifiservice/IWifiService.h>

namespace goni {


virtual status_t WifiServiceProxy::SetEnabled(bool enabled)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IWifiService::getInterfaceDescriptor());
    _data.writeInt32((int)enabled);
    return sendSyncRequest(WifiService::SET_ENABLED, _data, &reply);
}

virtual status_t WifiServiceProxy::SendCommand(int command, int arg1, int arg2)
{
    Parcel _data, reply;
    _data.writeInterfaceToken(IWifiService::getInterfaceDescriptor());
    _data.writeInt32(command);
    _data.writeInt32(arg1);
    _data.writeInt32(arg2);
    return sendSyncRequest(WifiService::SEND_COMMAND, _data, &reply);
}
