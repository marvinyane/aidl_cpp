/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ICameraRecordingProxyListener.aidl
 */
#define LOG_TAG "CameraRecordingProxyListener"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <camerarecordingproxylistener/ICameraRecordingProxyListener.h>

namespace android {

class BpCameraRecordingProxyListener : public BpInterface<ICameraRecordingProxyListener>
{
    public:
    BpCameraRecordingProxyListener(const sp<IBinder>& impl)
        : BpInterface<ICameraRecordingProxyListener>(impl) { }

virtual status_t dataCallbackTimestamp(long timestamp, int msgType, const sp<IMemory>& data)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICameraRecordingProxyListener::getInterfaceDescriptor());
    _data.writeInt64(timestamp);
    _data.writeInt32(msgType);
    data.writeToParcel(&_data);
    return remote()->transact(BnCameraRecordingProxyListener::DATA_CALLBACK_TIMESTAMP, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(CameraRecordingProxyListener, "android.os.ICameraRecordingProxyListener");

status_t BnCameraRecordingProxyListener::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case DATA_CALLBACK_TIMESTAMP: {
    CHECK_INTERFACE(ICameraRecordingProxyListener, data, reply);
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
