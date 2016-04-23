/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IAudioTrack.aidl
 */
#define LOG_TAG "AudioTrack"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <audiotrack/IAudioTrack.h>

namespace android {

class BpAudioTrack : public BpInterface<IAudioTrack>
{
    public:
    BpAudioTrack(const sp<IBinder>& impl)
        : BpInterface<IAudioTrack>(impl) { }

virtual const sp<IMemory>& getCblk()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioTrack::getInterfaceDescriptor());
    remote()->transact(BnAudioTrack::GET_CBLK, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& start()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioTrack::getInterfaceDescriptor());
    remote()->transact(BnAudioTrack::START, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t stop()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioTrack::getInterfaceDescriptor());
    return remote()->transact(BnAudioTrack::STOP, _data, &reply);
}

virtual status_t flush()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioTrack::getInterfaceDescriptor());
    return remote()->transact(BnAudioTrack::FLUSH, _data, &reply);
}

virtual status_t mute(bool e)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioTrack::getInterfaceDescriptor());
    _data.writeInt32((int)e);
    return remote()->transact(BnAudioTrack::MUTE, _data, &reply);
}

virtual status_t pause()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioTrack::getInterfaceDescriptor());
    return remote()->transact(BnAudioTrack::PAUSE, _data, &reply);
}

virtual const sp<status_t>& attachAuxEffect(int effectId)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioTrack::getInterfaceDescriptor());
    _data.writeInt32(effectId);
    remote()->transact(BnAudioTrack::ATTACH_AUX_EFFECT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& allocateTimedBuffer(int size, const sp<IMemory>& buffer)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioTrack::getInterfaceDescriptor());
    _data.writeInt32(size);
    remote()->transact(BnAudioTrack::ALLOCATE_TIMED_BUFFER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& queueTimedBuffer(const sp<IMemory>& buffer, long pts)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioTrack::getInterfaceDescriptor());
    buffer.writeToParcel(&_data);
    _data.writeInt64(pts);
    remote()->transact(BnAudioTrack::QUEUE_TIMED_BUFFER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setMediaTimeTransform(const sp<LinearTransform>& xform, int target)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioTrack::getInterfaceDescriptor());
    xform.writeToParcel(&_data);
    _data.writeInt32(target);
    remote()->transact(BnAudioTrack::SET_MEDIA_TIME_TRANSFORM, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(AudioTrack, "android.os.IAudioTrack");

status_t BnAudioTrack::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case GET_CBLK: {
    CHECK_INTERFACE(IAudioTrack, data, reply);
    int res = getCblk();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case START: {
    CHECK_INTERFACE(IAudioTrack, data, reply);
    int res = start();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case STOP: {
    CHECK_INTERFACE(IAudioTrack, data, reply);
    stop();
    return NO_ERROR;
    }
case FLUSH: {
    CHECK_INTERFACE(IAudioTrack, data, reply);
    flush();
    return NO_ERROR;
    }
case MUTE: {
    CHECK_INTERFACE(IAudioTrack, data, reply);
    bool _arg0;
    _arg0 = data.readInt32();
    mute(_arg0);
    return NO_ERROR;
    }
case PAUSE: {
    CHECK_INTERFACE(IAudioTrack, data, reply);
    pause();
    return NO_ERROR;
    }
case ATTACH_AUX_EFFECT: {
    CHECK_INTERFACE(IAudioTrack, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = attachAuxEffect(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case ALLOCATE_TIMED_BUFFER: {
    CHECK_INTERFACE(IAudioTrack, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<IMemory>& _arg1;
    int res = allocateTimedBuffer(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(buffer);
    return NO_ERROR;
    }
case QUEUE_TIMED_BUFFER: {
    CHECK_INTERFACE(IAudioTrack, data, reply);
    const sp<IMemory>& _arg0;
    _arg0 = data.readStrongIMemory();
    long _arg1;
    _arg1 = data.readInt64();
    int res = queueTimedBuffer(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_MEDIA_TIME_TRANSFORM: {
    CHECK_INTERFACE(IAudioTrack, data, reply);
    const sp<LinearTransform>& _arg0;
    _arg0 = data.readStrongLinearTransform();
    int _arg1;
    _arg1 = data.readInt32();
    int res = setMediaTimeTransform(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
