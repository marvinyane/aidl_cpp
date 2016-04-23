/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IAudioFlingerClient.aidl
 */
#define LOG_TAG "AudioFlingerClient"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <audioflingerclient/IAudioFlingerClient.h>

namespace android {

class BpAudioFlingerClient : public BpInterface<IAudioFlingerClient>
{
    public:
    BpAudioFlingerClient(const sp<IBinder>& impl)
        : BpInterface<IAudioFlingerClient>(impl) { }
// param2 is either "uint32_t" or "AudioSystem::OutputDescriptor",
// depending on event!

virtual status_t ioConfigChanged(int event, int ioHandle, int param2)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlingerClient::getInterfaceDescriptor());
    _data.writeInt32(event);
    _data.writeInt32(ioHandle);
    _data.writeInt32(param2);
    return remote()->transact(BnAudioFlingerClient::IO_CONFIG_CHANGED, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(AudioFlingerClient, "android.os.IAudioFlingerClient");

status_t BnAudioFlingerClient::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case IO_CONFIG_CHANGED: {
    CHECK_INTERFACE(IAudioFlingerClient, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    ioConfigChanged(_arg0, _arg1, _arg2);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
