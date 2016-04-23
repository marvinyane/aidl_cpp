/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: aidl/IWifiService.aidl
 */
#define LOG_TAG "WifiService"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <wifiservice/IWifiService.h>

namespace android {

class BpWifiService : public BpInterface<IWifiService>
{
    public:
        BpWifiService(const sp<IBinder>& impl)
            : BpInterface<IWifiService>(impl) { }

        virtual status_t Register(const sp<IWifiClient>& client, int flags)
        {
            Parcel _data, reply;
            _data.writeInterfaceToken(IWifiService::getInterfaceDescriptor());
            client.writeToParcel(&_data);
            _data.writeInt32(flags);
            return remote()->transact(BnWifiService::REGISTER, _data, &reply);
        }

        virtual status_t SetEnabled(bool enabled)
        {
            Parcel _data, reply;
            _data.writeInterfaceToken(IWifiService::getInterfaceDescriptor());
            _data.writeInt32((int)enabled);
            return remote()->transact(BnWifiService::SET_ENABLED, _data, &reply);
        }

        virtual status_t SendCommand(int command, int arg1, int arg2)
        {
            Parcel _data, reply;
            _data.writeInterfaceToken(IWifiService::getInterfaceDescriptor());
            _data.writeInt32(command);
            _data.writeInt32(arg1);
            _data.writeInt32(arg2);
            return remote()->transact(BnWifiService::SEND_COMMAND, _data, &reply);
        }

        virtual status_t AddOrUpdateNetwork(const sp<ConfiguredStation>& cs)
        {
            Parcel _data, reply;
            _data.writeInterfaceToken(IWifiService::getInterfaceDescriptor());
            cs.writeToParcel(&_data);
            return remote()->transact(BnWifiService::ADD_OR_UPDATE_NETWORK, _data, &reply);
        }
};

    IMPLEMENT_META_INTERFACE(WifiService, "android.os.IWifiService");

    status_t BnWifiService::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
    {
        switch (code) {
            case REGISTER: {
                               CHECK_INTERFACE(IWifiService, data, reply);
                               const sp<IWifiClient>& _arg0;
                               _arg0 = data.readStrongIWifiClient();
                               int _arg1;
                               _arg1 = data.readInt32();
                               Register(_arg0, _arg1);
                               return NO_ERROR;
                           }
            case SET_ENABLED: {
                                  CHECK_INTERFACE(IWifiService, data, reply);
                                  bool _arg0;
                                  _arg0 = data.readInt32();
                                  SetEnabled(_arg0);
                                  return NO_ERROR;
                              }
            case SEND_COMMAND: {
                                   CHECK_INTERFACE(IWifiService, data, reply);
                                   int _arg0;
                                   _arg0 = data.readInt32();
                                   int _arg1;
                                   _arg1 = data.readInt32();
                                   int _arg2;
                                   _arg2 = data.readInt32();
                                   SendCommand(_arg0, _arg1, _arg2);
                                   return NO_ERROR;
                               }
            case ADD_OR_UPDATE_NETWORK: {
                                            CHECK_INTERFACE(IWifiService, data, reply);
                                            const sp<ConfiguredStation>& _arg0;
                                            _arg0 = data.readStrongConfiguredStation();
                                            AddOrUpdateNetwork(_arg0);
                                            return NO_ERROR;
                                        }
        }
        return BBinder::onTransact(code, data, reply, flags);
    }

}; // namespace android
