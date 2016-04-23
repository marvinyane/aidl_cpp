/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ICameraClient.aidl
 */
#define LOG_TAG "CameraClient"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <cameraclient/ICameraClient.h>

namespace android {

class BpCameraClient : public BpInterface<ICameraClient>
{
    public:
    BpCameraClient(const sp<IBinder>& impl)
        : BpInterface<ICameraClient>(impl) { }

virtual status_t notifyCallback(int msgType, int ext1, int ext2)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICameraClient::getInterfaceDescriptor());
    _data.writeInt32(msgType);
    _data.writeInt32(ext1);
    _data.writeInt32(ext2);
    return remote()->transact(BnCameraClient::NOTIFY_CALLBACK, _data, &reply);
}

virtual status_t dataCallback(int msgType, const sp<IMemory>& data, const sp<camera_frame_metadata_t>& metadata)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICameraClient::getInterfaceDescriptor());
    _data.writeInt32(msgType);
    data.writeToParcel(&_data);
    return remote()->transact(BnCameraClient::DATA_CALLBACK, _data, &reply);
}

virtual status_t dataCallbackTimestamp(long timestamp, int msgType, const sp<IMemory>& data)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICameraClient::getInterfaceDescriptor());
    _data.writeInt64(timestamp);
    _data.writeInt32(msgType);
    data.writeToParcel(&_data);
    return remote()->transact(BnCameraClient::DATA_CALLBACK_TIMESTAMP, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(CameraClient, "android.os.ICameraClient");

status_t BnCameraClient::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case NOTIFY_CALLBACK: {
    CHECK_INTERFACE(ICameraClient, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    notifyCallback(_arg0, _arg1, _arg2);
    return NO_ERROR;
    }
case DATA_CALLBACK: {
    CHECK_INTERFACE(ICameraClient, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<IMemory>& _arg1;
    _arg1 = data.readStrongIMemory();
    const sp<camera_frame_metadata_t>& _arg2;
    dataCallback(_arg0, _arg1, _arg2);
data.%s.writeToParcel(&_data);
(metadata);
    return NO_ERROR;
    }
case DATA_CALLBACK_TIMESTAMP: {
    CHECK_INTERFACE(ICameraClient, data, reply);
    long _arg0;
    _arg0 = data.readInt64();
    int _arg1;
    _arg1 = data.readInt32();
    const sp<IMemory>& _arg2;
    _arg2 = data.readStrongIMemory();
    dataCallbackTimestamp(_arg0, _arg1, _arg2);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
