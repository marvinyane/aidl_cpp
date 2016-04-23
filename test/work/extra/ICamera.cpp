/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ICamera.aidl
 */
#define LOG_TAG "Camera"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <camera/ICamera.h>

namespace android {

class BpCamera : public BpInterface<ICamera>
{
    public:
    BpCamera(const sp<IBinder>& impl)
        : BpInterface<ICamera>(impl) { }

virtual status_t disconnect()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    return remote()->transact(BnCamera::DISCONNECT, _data, &reply);
}

virtual const sp<status_t>& setPreviewDisplay(const sp<Surface>& surface)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    surface.writeToParcel(&_data);
    remote()->transact(BnCamera::SET_PREVIEW_DISPLAY, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setPreviewTexture(const sp<ISurfaceTexture>& surfaceTexture)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    surfaceTexture.writeToParcel(&_data);
    remote()->transact(BnCamera::SET_PREVIEW_TEXTURE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t setPreviewCallbackFlag(int flag)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    _data.writeInt32(flag);
    return remote()->transact(BnCamera::SET_PREVIEW_CALLBACK_FLAG, _data, &reply);
}

virtual const sp<status_t>& startPreview()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    remote()->transact(BnCamera::START_PREVIEW, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& stopPreview()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    remote()->transact(BnCamera::STOP_PREVIEW, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& autoFocus()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    remote()->transact(BnCamera::AUTO_FOCUS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& cancelAutoFocus()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    remote()->transact(BnCamera::CANCEL_AUTO_FOCUS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& takePicture(int msgType)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    _data.writeInt32(msgType);
    remote()->transact(BnCamera::TAKE_PICTURE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setParameters(const String8& params)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    _data.writeString8(params);
    remote()->transact(BnCamera::SET_PARAMETERS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual String8 getParameters()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    remote()->transact(BnCamera::GET_PARAMETERS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& sendCommand(int cmd, int arg1, int arg2)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    _data.writeInt32(cmd);
    _data.writeInt32(arg1);
    _data.writeInt32(arg2);
    remote()->transact(BnCamera::SEND_COMMAND, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& connect(const sp<ICameraClient>& client)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    client.writeToParcel(&_data);
    remote()->transact(BnCamera::CONNECT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& lock()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    remote()->transact(BnCamera::LOCK, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& unlock()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    remote()->transact(BnCamera::UNLOCK, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual bool previewEnabled()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    remote()->transact(BnCamera::PREVIEW_ENABLED, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& startRecording()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    remote()->transact(BnCamera::START_RECORDING, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t stopRecording()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    return remote()->transact(BnCamera::STOP_RECORDING, _data, &reply);
}

virtual bool recordingEnabled()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    remote()->transact(BnCamera::RECORDING_ENABLED, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t releaseRecordingFrame(const sp<IMemory>& mem)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    mem.writeToParcel(&_data);
    return remote()->transact(BnCamera::RELEASE_RECORDING_FRAME, _data, &reply);
}

virtual const sp<status_t>& storeMetaDataInBuffers(bool enabled)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICamera::getInterfaceDescriptor());
    _data.writeInt32((int)enabled);
    remote()->transact(BnCamera::STORE_META_DATA_IN_BUFFERS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(Camera, "android.os.ICamera");

status_t BnCamera::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case DISCONNECT: {
    CHECK_INTERFACE(ICamera, data, reply);
    disconnect();
    return NO_ERROR;
    }
case SET_PREVIEW_DISPLAY: {
    CHECK_INTERFACE(ICamera, data, reply);
    const sp<Surface>& _arg0;
    _arg0 = data.readStrongSurface();
    int res = setPreviewDisplay(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_PREVIEW_TEXTURE: {
    CHECK_INTERFACE(ICamera, data, reply);
    const sp<ISurfaceTexture>& _arg0;
    _arg0 = data.readStrongISurfaceTexture();
    int res = setPreviewTexture(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_PREVIEW_CALLBACK_FLAG: {
    CHECK_INTERFACE(ICamera, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    setPreviewCallbackFlag(_arg0);
    return NO_ERROR;
    }
case START_PREVIEW: {
    CHECK_INTERFACE(ICamera, data, reply);
    int res = startPreview();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case STOP_PREVIEW: {
    CHECK_INTERFACE(ICamera, data, reply);
    int res = stopPreview();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case AUTO_FOCUS: {
    CHECK_INTERFACE(ICamera, data, reply);
    int res = autoFocus();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CANCEL_AUTO_FOCUS: {
    CHECK_INTERFACE(ICamera, data, reply);
    int res = cancelAutoFocus();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case TAKE_PICTURE: {
    CHECK_INTERFACE(ICamera, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = takePicture(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_PARAMETERS: {
    CHECK_INTERFACE(ICamera, data, reply);
    String8 _arg0;
    _arg0 = data.readString8();
    int res = setParameters(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_PARAMETERS: {
    CHECK_INTERFACE(ICamera, data, reply);
    int res = getParameters();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SEND_COMMAND: {
    CHECK_INTERFACE(ICamera, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int res = sendCommand(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CONNECT: {
    CHECK_INTERFACE(ICamera, data, reply);
    const sp<ICameraClient>& _arg0;
    _arg0 = data.readStrongICameraClient();
    int res = connect(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case LOCK: {
    CHECK_INTERFACE(ICamera, data, reply);
    int res = lock();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case UNLOCK: {
    CHECK_INTERFACE(ICamera, data, reply);
    int res = unlock();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case PREVIEW_ENABLED: {
    CHECK_INTERFACE(ICamera, data, reply);
    int res = previewEnabled()? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case START_RECORDING: {
    CHECK_INTERFACE(ICamera, data, reply);
    int res = startRecording();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case STOP_RECORDING: {
    CHECK_INTERFACE(ICamera, data, reply);
    stopRecording();
    return NO_ERROR;
    }
case RECORDING_ENABLED: {
    CHECK_INTERFACE(ICamera, data, reply);
    int res = recordingEnabled()? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case RELEASE_RECORDING_FRAME: {
    CHECK_INTERFACE(ICamera, data, reply);
    const sp<IMemory>& _arg0;
    _arg0 = data.readStrongIMemory();
    releaseRecordingFrame(_arg0);
    return NO_ERROR;
    }
case STORE_META_DATA_IN_BUFFERS: {
    CHECK_INTERFACE(ICamera, data, reply);
    bool _arg0;
    _arg0 = data.readInt32();
    int res = storeMetaDataInBuffers(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
