/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMediaRecorderClient.aidl
 */
#define LOG_TAG "MediaRecorderClient"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <mediarecorderclient/IMediaRecorderClient.h>

namespace android {

class BpMediaRecorderClient : public BpInterface<IMediaRecorderClient>
{
    public:
    BpMediaRecorderClient(const sp<IBinder>& impl)
        : BpInterface<IMediaRecorderClient>(impl) { }

virtual status_t notify(int msg, int ext1, int ext2)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorderClient::getInterfaceDescriptor());
    _data.writeInt32(msg);
    _data.writeInt32(ext1);
    _data.writeInt32(ext2);
    return remote()->transact(BnMediaRecorderClient::NOTIFY, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(MediaRecorderClient, "android.os.IMediaRecorderClient");

status_t BnMediaRecorderClient::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case NOTIFY: {
    CHECK_INTERFACE(IMediaRecorderClient, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    notify(_arg0, _arg1, _arg2);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
