/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMediaPlayerClient.aidl
 */
#define LOG_TAG "MediaPlayerClient"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <mediaplayerclient/IMediaPlayerClient.h>

namespace android {

class BpMediaPlayerClient : public BpInterface<IMediaPlayerClient>
{
    public:
    BpMediaPlayerClient(const sp<IBinder>& impl)
        : BpInterface<IMediaPlayerClient>(impl) { }

virtual status_t notify(int msg, int ext1, int ext2, const sp<zParcel>& obj)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayerClient::getInterfaceDescriptor());
    _data.writeInt32(msg);
    _data.writeInt32(ext1);
    _data.writeInt32(ext2);
    obj.writeToParcel(&_data);
    return remote()->transact(BnMediaPlayerClient::NOTIFY, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(MediaPlayerClient, "android.os.IMediaPlayerClient");

status_t BnMediaPlayerClient::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case NOTIFY: {
    CHECK_INTERFACE(IMediaPlayerClient, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    const sp<zParcel>& _arg3;
    _arg3 = data.readStrongzParcel();
    notify(_arg0, _arg1, _arg2, _arg3);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
