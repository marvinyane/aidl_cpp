/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMediaRecorder.aidl
 */
#define LOG_TAG "MediaRecorder"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <mediarecorder/IMediaRecorder.h>

namespace android {

class BpMediaRecorder : public BpInterface<IMediaRecorder>
{
    public:
    BpMediaRecorder(const sp<IBinder>& impl)
        : BpInterface<IMediaRecorder>(impl) { }

virtual const sp<status_t>& release()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    remote()->transact(BnMediaRecorder::RELEASE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& init()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    remote()->transact(BnMediaRecorder::INIT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& close()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    remote()->transact(BnMediaRecorder::CLOSE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<ISurfaceTexture>& querySurfaceMediaSource()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    remote()->transact(BnMediaRecorder::QUERY_SURFACE_MEDIA_SOURCE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& reset()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    remote()->transact(BnMediaRecorder::RESET, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& stop()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    remote()->transact(BnMediaRecorder::STOP, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& start()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    remote()->transact(BnMediaRecorder::START, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& prepare()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    remote()->transact(BnMediaRecorder::PREPARE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getMaxAmplitude(int max)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    remote()->transact(BnMediaRecorder::GET_MAX_AMPLITUDE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setVideoSource(int vs)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    _data.writeInt32(vs);
    remote()->transact(BnMediaRecorder::SET_VIDEO_SOURCE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setAudioSource(int as)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    _data.writeInt32(as);
    remote()->transact(BnMediaRecorder::SET_AUDIO_SOURCE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setOutputFormat(int of)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    _data.writeInt32(of);
    remote()->transact(BnMediaRecorder::SET_OUTPUT_FORMAT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setVideoEncoder(int ve)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    _data.writeInt32(ve);
    remote()->transact(BnMediaRecorder::SET_VIDEO_ENCODER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setAudioEncoder(int ae)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    _data.writeInt32(ae);
    remote()->transact(BnMediaRecorder::SET_AUDIO_ENCODER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setOutputFilePath(const CString& path)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    _data.writeCString(path);
    remote()->transact(BnMediaRecorder::SET_OUTPUT_FILE_PATH, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setOutputFileFd(int fd, long offset, long length)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    _data.writeInt32(fd);
    _data.writeInt64(offset);
    _data.writeInt64(length);
    remote()->transact(BnMediaRecorder::SET_OUTPUT_FILE_FD, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setVideoSize(int width, int height)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    _data.writeInt32(width);
    _data.writeInt32(height);
    remote()->transact(BnMediaRecorder::SET_VIDEO_SIZE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setVideoFrameRate(int frames_per_second)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    _data.writeInt32(frames_per_second);
    remote()->transact(BnMediaRecorder::SET_VIDEO_FRAME_RATE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setParameters(const String8& params)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    _data.writeString8(params);
    remote()->transact(BnMediaRecorder::SET_PARAMETERS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setPreviewSurface(const sp<Surface>& surface)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    surface.writeToParcel(&_data);
    remote()->transact(BnMediaRecorder::SET_PREVIEW_SURFACE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setCamera(const sp<ICamera>& camera, const sp<ICameraRecordingProxy>& proxy)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    camera.writeToParcel(&_data);
    proxy.writeToParcel(&_data);
    remote()->transact(BnMediaRecorder::SET_CAMERA, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setListener(const sp<IMediaRecorderClient>& listener)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaRecorder::getInterfaceDescriptor());
    listener.writeToParcel(&_data);
    remote()->transact(BnMediaRecorder::SET_LISTENER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(MediaRecorder, "android.os.IMediaRecorder");

status_t BnMediaRecorder::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case RELEASE: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    int res = release();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case INIT: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    int res = init();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CLOSE: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    int res = close();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case QUERY_SURFACE_MEDIA_SOURCE: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    int res = querySurfaceMediaSource();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case RESET: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    int res = reset();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case STOP: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    int res = stop();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case START: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    int res = start();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case PREPARE: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    int res = prepare();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_MAX_AMPLITUDE: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    int _arg0;
    int res = getMaxAmplitude(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(max);
    return NO_ERROR;
    }
case SET_VIDEO_SOURCE: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = setVideoSource(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_AUDIO_SOURCE: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = setAudioSource(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_OUTPUT_FORMAT: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = setOutputFormat(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_VIDEO_ENCODER: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = setVideoEncoder(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_AUDIO_ENCODER: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = setAudioEncoder(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_OUTPUT_FILE_PATH: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    CString _arg0;
    _arg0 = data.readCString();
    int res = setOutputFilePath(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_OUTPUT_FILE_FD: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    long _arg1;
    _arg1 = data.readInt64();
    long _arg2;
    _arg2 = data.readInt64();
    int res = setOutputFileFd(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_VIDEO_SIZE: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int res = setVideoSize(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_VIDEO_FRAME_RATE: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = setVideoFrameRate(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_PARAMETERS: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    String8 _arg0;
    _arg0 = data.readString8();
    int res = setParameters(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_PREVIEW_SURFACE: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    const sp<Surface>& _arg0;
    _arg0 = data.readStrongSurface();
    int res = setPreviewSurface(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_CAMERA: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    const sp<ICamera>& _arg0;
    _arg0 = data.readStrongICamera();
    const sp<ICameraRecordingProxy>& _arg1;
    _arg1 = data.readStrongICameraRecordingProxy();
    int res = setCamera(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_LISTENER: {
    CHECK_INTERFACE(IMediaRecorder, data, reply);
    const sp<IMediaRecorderClient>& _arg0;
    _arg0 = data.readStrongIMediaRecorderClient();
    int res = setListener(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
