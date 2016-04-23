/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ICameraRecordingProxy.aidl
 */
#define LOG_TAG "CameraRecordingProxy"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <camerarecordingproxy/ICameraRecordingProxy.h>

namespace android {

class BpCameraRecordingProxy : public BpInterface<ICameraRecordingProxy>
{
    public:
    BpCameraRecordingProxy(const sp<IBinder>& impl)
        : BpInterface<ICameraRecordingProxy>(impl) { }

virtual const sp<status_t>& startRecording(const sp<ICameraRecordingProxyListener>& listener)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICameraRecordingProxy::getInterfaceDescriptor());
    listener.writeToParcel(&_data);
    remote()->transact(BnCameraRecordingProxy::START_RECORDING, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t stopRecording()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICameraRecordingProxy::getInterfaceDescriptor());
    return remote()->transact(BnCameraRecordingProxy::STOP_RECORDING, _data, &reply);
}

virtual status_t releaseRecordingFrame(const sp<IMemory>& mem)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICameraRecordingProxy::getInterfaceDescriptor());
    mem.writeToParcel(&_data);
    return remote()->transact(BnCameraRecordingProxy::RELEASE_RECORDING_FRAME, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(CameraRecordingProxy, "android.os.ICameraRecordingProxy");

status_t BnCameraRecordingProxy::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case START_RECORDING: {
    CHECK_INTERFACE(ICameraRecordingProxy, data, reply);
    const sp<ICameraRecordingProxyListener>& _arg0;
    _arg0 = data.readStrongICameraRecordingProxyListener();
    int res = startRecording(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case STOP_RECORDING: {
    CHECK_INTERFACE(ICameraRecordingProxy, data, reply);
    stopRecording();
    return NO_ERROR;
    }
case RELEASE_RECORDING_FRAME: {
    CHECK_INTERFACE(ICameraRecordingProxy, data, reply);
    const sp<IMemory>& _arg0;
    _arg0 = data.readStrongIMemory();
    releaseRecordingFrame(_arg0);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
