/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMediaPlayer.aidl
 */
#define LOG_TAG "MediaPlayer"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <mediaplayer/IMediaPlayer.h>

namespace android {

class BpMediaPlayer : public BpInterface<IMediaPlayer>
{
    public:
    BpMediaPlayer(const sp<IBinder>& impl)
        : BpInterface<IMediaPlayer>(impl) { }

virtual status_t disconnect()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    return remote()->transact(BnMediaPlayer::DISCONNECT, _data, &reply);
}

virtual const sp<status_t>& setDataSourceUrl(const CString& url, const String16& headers)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    _data.writeCString(url);
    _data.writeString16(headers);
    remote()->transact(BnMediaPlayer::SET_DATA_SOURCE_URL, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setDataSourceFd(int fd, long offset, long length)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    _data.writeInt32(fd);
    _data.writeInt64(offset);
    _data.writeInt64(length);
    remote()->transact(BnMediaPlayer::SET_DATA_SOURCE_FD, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setDataSourceStream(const sp<IStreamSource>& source)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    source.writeToParcel(&_data);
    remote()->transact(BnMediaPlayer::SET_DATA_SOURCE_STREAM, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& prepareAsync()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    remote()->transact(BnMediaPlayer::PREPARE_ASYNC, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& start()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    remote()->transact(BnMediaPlayer::START, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& stop()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    remote()->transact(BnMediaPlayer::STOP, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& isPlaying(bool state)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    remote()->transact(BnMediaPlayer::IS_PLAYING, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& pause()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    remote()->transact(BnMediaPlayer::PAUSE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& seekTo(int msec)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    _data.writeInt32(msec);
    remote()->transact(BnMediaPlayer::SEEK_TO, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getCurrentPosition(int msec)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    remote()->transact(BnMediaPlayer::GET_CURRENT_POSITION, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getDuration(int msec)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    remote()->transact(BnMediaPlayer::GET_DURATION, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& reset()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    remote()->transact(BnMediaPlayer::RESET, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setAudioStreamType(int type)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    _data.writeInt32(type);
    remote()->transact(BnMediaPlayer::SET_AUDIO_STREAM_TYPE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setLooping(int loop)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    _data.writeInt32(loop);
    remote()->transact(BnMediaPlayer::SET_LOOPING, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setVolume(float leftVolume, float rightVolume)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    _data.writeFloat(leftVolume);
    _data.writeFloat(rightVolume);
    remote()->transact(BnMediaPlayer::SET_VOLUME, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& invoke(const sp<zParcel>& request, const sp<zParcel>& reply)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    request.writeToParcel(&_data);
    remote()->transact(BnMediaPlayer::INVOKE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setMetadataFilter(const sp<zParcel>& filter)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    filter.writeToParcel(&_data);
    remote()->transact(BnMediaPlayer::SET_METADATA_FILTER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getMetadata(bool update_only, bool apply_filter, const sp<zParcel>& metadata)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    _data.writeInt32((int)update_only);
    _data.writeInt32((int)apply_filter);
    remote()->transact(BnMediaPlayer::GET_METADATA, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setAuxEffectSendLevel(float level)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    _data.writeFloat(level);
    remote()->transact(BnMediaPlayer::SET_AUX_EFFECT_SEND_LEVEL, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& attachAuxEffect(int effectId)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    _data.writeInt32(effectId);
    remote()->transact(BnMediaPlayer::ATTACH_AUX_EFFECT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setVideoSurfaceTexture(const sp<ISurfaceTexture>& surfaceTexture)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    surfaceTexture.writeToParcel(&_data);
    remote()->transact(BnMediaPlayer::SET_VIDEO_SURFACE_TEXTURE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setParameter(int key, const sp<zParcel>& request)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    _data.writeInt32(key);
    request.writeToParcel(&_data);
    remote()->transact(BnMediaPlayer::SET_PARAMETER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getParameter(int key, const sp<zParcel>& reply)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    _data.writeInt32(key);
    remote()->transact(BnMediaPlayer::GET_PARAMETER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setRetransmitEndpoint(const sp<sockaddr_in>& endpoint)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    endpoint.writeToParcel(&_data);
    remote()->transact(BnMediaPlayer::SET_RETRANSMIT_ENDPOINT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setNextPlayer(const sp<IMediaPlayer>& next)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayer::getInterfaceDescriptor());
    next.writeToParcel(&_data);
    remote()->transact(BnMediaPlayer::SET_NEXT_PLAYER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(MediaPlayer, "android.os.IMediaPlayer");

status_t BnMediaPlayer::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case DISCONNECT: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    disconnect();
    return NO_ERROR;
    }
case SET_DATA_SOURCE_URL: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    CString _arg0;
    _arg0 = data.readCString();
    String16 _arg1;
    _arg1 = data.readString16();
    int res = setDataSourceUrl(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_DATA_SOURCE_FD: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    long _arg1;
    _arg1 = data.readInt64();
    long _arg2;
    _arg2 = data.readInt64();
    int res = setDataSourceFd(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_DATA_SOURCE_STREAM: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    const sp<IStreamSource>& _arg0;
    _arg0 = data.readStrongIStreamSource();
    int res = setDataSourceStream(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case PREPARE_ASYNC: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    int res = prepareAsync();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case START: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    int res = start();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case STOP: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    int res = stop();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case IS_PLAYING: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    bool _arg0;
    int res = isPlaying(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32((int)%s);
(state);
    return NO_ERROR;
    }
case PAUSE: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    int res = pause();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SEEK_TO: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = seekTo(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_CURRENT_POSITION: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    int _arg0;
    int res = getCurrentPosition(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(msec);
    return NO_ERROR;
    }
case GET_DURATION: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    int _arg0;
    int res = getDuration(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(msec);
    return NO_ERROR;
    }
case RESET: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    int res = reset();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_AUDIO_STREAM_TYPE: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = setAudioStreamType(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_LOOPING: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = setLooping(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_VOLUME: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    float _arg0;
    _arg0 = data.readFloat();
    float _arg1;
    _arg1 = data.readFloat();
    int res = setVolume(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case INVOKE: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    const sp<zParcel>& _arg0;
    _arg0 = data.readStrongzParcel();
    const sp<zParcel>& _arg1;
    int res = invoke(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(reply);
    return NO_ERROR;
    }
case SET_METADATA_FILTER: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    const sp<zParcel>& _arg0;
    _arg0 = data.readStrongzParcel();
    int res = setMetadataFilter(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_METADATA: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    bool _arg0;
    _arg0 = data.readInt32();
    bool _arg1;
    _arg1 = data.readInt32();
    const sp<zParcel>& _arg2;
    int res = getMetadata(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(metadata);
    return NO_ERROR;
    }
case SET_AUX_EFFECT_SEND_LEVEL: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    float _arg0;
    _arg0 = data.readFloat();
    int res = setAuxEffectSendLevel(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case ATTACH_AUX_EFFECT: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = attachAuxEffect(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_VIDEO_SURFACE_TEXTURE: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    const sp<ISurfaceTexture>& _arg0;
    _arg0 = data.readStrongISurfaceTexture();
    int res = setVideoSurfaceTexture(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_PARAMETER: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<zParcel>& _arg1;
    _arg1 = data.readStrongzParcel();
    int res = setParameter(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_PARAMETER: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<zParcel>& _arg1;
    int res = getParameter(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(reply);
    return NO_ERROR;
    }
case SET_RETRANSMIT_ENDPOINT: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    const sp<sockaddr_in>& _arg0;
    _arg0 = data.readStrongsockaddr_in();
    int res = setRetransmitEndpoint(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_NEXT_PLAYER: {
    CHECK_INTERFACE(IMediaPlayer, data, reply);
    const sp<IMediaPlayer>& _arg0;
    _arg0 = data.readStrongIMediaPlayer();
    int res = setNextPlayer(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
