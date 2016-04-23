/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IAudioFlinger.aidl
 */
#define LOG_TAG "AudioFlinger"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <audioflinger/IAudioFlinger.h>

namespace android {

class BpAudioFlinger : public BpInterface<IAudioFlinger>
{
    public:
    BpAudioFlinger(const sp<IBinder>& impl)
        : BpInterface<IAudioFlinger>(impl) { }

virtual const sp<IAudioTrack>& createTrack(int pid, int streamType, int sampleRate, int format, int channelMask, int frameCount, int flags, const sp<IMemory>& sharedBuffer, int output, int tid, int sessionId, const sp<status_t>& status)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(pid);
    _data.writeInt32(streamType);
    _data.writeInt32(sampleRate);
    _data.writeInt32(format);
    _data.writeInt32(channelMask);
    _data.writeInt32(frameCount);
    _data.writeInt32(flags);
    sharedBuffer.writeToParcel(&_data);
    _data.writeInt32(output);
    _data.writeInt32(tid);
    _data.writeInt32(sessionId);
    remote()->transact(BnAudioFlinger::CREATE_TRACK, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<IAudioRecord>& openRecord(int pid, int input, int sampleRate, int format, int channelMask, int frameCount, int flags, int sessionId, const sp<void>& status)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(pid);
    _data.writeInt32(input);
    _data.writeInt32(sampleRate);
    _data.writeInt32(format);
    _data.writeInt32(channelMask);
    _data.writeInt32(frameCount);
    _data.writeInt32(flags);
    _data.writeInt32(sessionId);
    remote()->transact(BnAudioFlinger::OPEN_RECORD, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int sampleRate(int output)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(output);
    remote()->transact(BnAudioFlinger::SAMPLE_RATE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int channelCount(int output)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(output);
    remote()->transact(BnAudioFlinger::CHANNEL_COUNT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int format(int output)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(output);
    remote()->transact(BnAudioFlinger::FORMAT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual long frameCount(int output)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(output);
    remote()->transact(BnAudioFlinger::FRAME_COUNT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int latency(int output)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(output);
    remote()->transact(BnAudioFlinger::LATENCY, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setMasterVolume(float value)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeFloat(value);
    remote()->transact(BnAudioFlinger::SET_MASTER_VOLUME, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setMasterMute(bool muted)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32((int)muted);
    remote()->transact(BnAudioFlinger::SET_MASTER_MUTE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual float masterVolume()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    remote()->transact(BnAudioFlinger::MASTER_VOLUME, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual bool masterMute()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    remote()->transact(BnAudioFlinger::MASTER_MUTE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setStreamVolume(int stream, float value, int output)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(stream);
    _data.writeFloat(value);
    _data.writeInt32(output);
    remote()->transact(BnAudioFlinger::SET_STREAM_VOLUME, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setStreamMute(int stream, bool muted)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(stream);
    _data.writeInt32((int)muted);
    remote()->transact(BnAudioFlinger::SET_STREAM_MUTE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual float streamVolume(int stream, int output)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(stream);
    _data.writeInt32(output);
    remote()->transact(BnAudioFlinger::STREAM_VOLUME, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual bool streamMute(int stream)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(stream);
    remote()->transact(BnAudioFlinger::STREAM_MUTE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setMode(int mode)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(mode);
    remote()->transact(BnAudioFlinger::SET_MODE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setMicMute(bool state)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32((int)state);
    remote()->transact(BnAudioFlinger::SET_MIC_MUTE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual bool getMicMute()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    remote()->transact(BnAudioFlinger::GET_MIC_MUTE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setParameters(int ioHandle, const String8& keyValuePairs)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(ioHandle);
    _data.writeString8(keyValuePairs);
    remote()->transact(BnAudioFlinger::SET_PARAMETERS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual String8 getParameters(int ioHandle, const String8& keys)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(ioHandle);
    _data.writeString8(keys);
    remote()->transact(BnAudioFlinger::GET_PARAMETERS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& registerClient(const sp<IAudioFlingerClient>& client)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    client.writeToParcel(&_data);
    remote()->transact(BnAudioFlinger::REGISTER_CLIENT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int getInputBufferSize(int sampleRate, int format, int channelCount)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(sampleRate);
    _data.writeInt32(format);
    _data.writeInt32(channelCount);
    remote()->transact(BnAudioFlinger::GET_INPUT_BUFFER_SIZE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int openOutput(int module, int pDevices, int pSamplingRate, int pFormat, int pChannelMask, int pLatencyMs, int flags)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(module);
    _data.writeInt32(pDevices);
    _data.writeInt32(pSamplingRate);
    _data.writeInt32(pFormat);
    _data.writeInt32(pChannelMask);
    _data.writeInt32(pLatencyMs);
    _data.writeInt32(flags);
    remote()->transact(BnAudioFlinger::OPEN_OUTPUT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int openDuplicateOutput(int output1, int output2)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(output1);
    _data.writeInt32(output2);
    remote()->transact(BnAudioFlinger::OPEN_DUPLICATE_OUTPUT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& closeOutput(int output)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(output);
    remote()->transact(BnAudioFlinger::CLOSE_OUTPUT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& suspendOutput(int output)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(output);
    remote()->transact(BnAudioFlinger::SUSPEND_OUTPUT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& restoreOutput(int output)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(output);
    remote()->transact(BnAudioFlinger::RESTORE_OUTPUT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int openInput(int module, int pDevices, int pSamplingRate, int pFormat, int pChannelMask)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(module);
    _data.writeInt32(pDevices);
    _data.writeInt32(pSamplingRate);
    _data.writeInt32(pFormat);
    _data.writeInt32(pChannelMask);
    remote()->transact(BnAudioFlinger::OPEN_INPUT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& closeInput(int input)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(input);
    remote()->transact(BnAudioFlinger::CLOSE_INPUT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setStreamOutput(int stream, int output)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(stream);
    _data.writeInt32(output);
    remote()->transact(BnAudioFlinger::SET_STREAM_OUTPUT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setVoiceVolume(float volume)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeFloat(volume);
    remote()->transact(BnAudioFlinger::SET_VOICE_VOLUME, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t getRenderPosition(int halFrames, int dspFrames, int output)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(output);
    return remote()->transact(BnAudioFlinger::GET_RENDER_POSITION, _data, &reply);
}

virtual int getInputFramesLost(int ioHandle)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(ioHandle);
    remote()->transact(BnAudioFlinger::GET_INPUT_FRAMES_LOST, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int newAudioSessionId()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    remote()->transact(BnAudioFlinger::NEW_AUDIO_SESSION_ID, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& acquireAudioSessionId(int audioSession)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(audioSession);
    remote()->transact(BnAudioFlinger::ACQUIRE_AUDIO_SESSION_ID, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& releaseAudioSessionId(int audioSession)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(audioSession);
    remote()->transact(BnAudioFlinger::RELEASE_AUDIO_SESSION_ID, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& queryNumberEffects(int numEffects)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    remote()->transact(BnAudioFlinger::QUERY_NUMBER_EFFECTS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& queryEffect(int index, const sp<effect_descriptor_t>& pDescriptor)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(index);
    remote()->transact(BnAudioFlinger::QUERY_EFFECT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getEffectDescriptor(const sp<effect_uuid_t>& pEffectUUID, const sp<effect_descriptor_t>& pDescriptor)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    pEffectUUID.writeToParcel(&_data);
    remote()->transact(BnAudioFlinger::GET_EFFECT_DESCRIPTOR, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
// createEffect: response has pDesc data last!

virtual const sp<IEffect>& createEffect(int pid, const sp<effect_descriptor_t>& pDesc, const sp<IEffectClient>& client, int priority, int output, int sessionId, const sp<status_t>& status, int id, int enabled)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(pid);
    pDesc.writeToParcel(&_data);
    client.writeToParcel(&_data);
    _data.writeInt32(priority);
    _data.writeInt32(output);
    _data.writeInt32(sessionId);
    remote()->transact(BnAudioFlinger::CREATE_EFFECT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& moveEffects(int session, int srcOutput, int dstOutput)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeInt32(session);
    _data.writeInt32(srcOutput);
    _data.writeInt32(dstOutput);
    remote()->transact(BnAudioFlinger::MOVE_EFFECTS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int loadHwModule(const CString& name)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioFlinger::getInterfaceDescriptor());
    _data.writeCString(name);
    remote()->transact(BnAudioFlinger::LOAD_HW_MODULE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(AudioFlinger, "android.os.IAudioFlinger");

status_t BnAudioFlinger::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case CREATE_TRACK: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int _arg3;
    _arg3 = data.readInt32();
    int _arg4;
    _arg4 = data.readInt32();
    int _arg5;
    _arg5 = data.readInt32();
    int _arg6;
    _arg6 = data.readInt32();
    const sp<IMemory>& _arg7;
    _arg7 = data.readStrongIMemory();
    int _arg8;
    _arg8 = data.readInt32();
    int _arg9;
    _arg9 = data.readInt32();
    int _arg10;
    _arg10 = data.readInt32();
    const sp<status_t>& _arg11;
    int res = createTrack(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(sessionId);
data.%s.writeToParcel(&_data);
(status);
    return NO_ERROR;
    }
case OPEN_RECORD: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int _arg3;
    _arg3 = data.readInt32();
    int _arg4;
    _arg4 = data.readInt32();
    int _arg5;
    _arg5 = data.readInt32();
    int _arg6;
    _arg6 = data.readInt32();
    int _arg7;
    _arg7 = data.readInt32();
    const sp<void>& _arg8;
    int res = openRecord(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(sessionId);
data.%s.writeToParcel(&_data);
(status);
    return NO_ERROR;
    }
case SAMPLE_RATE: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = sampleRate(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CHANNEL_COUNT: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = channelCount(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case FORMAT: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = format(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case FRAME_COUNT: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = frameCount(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case LATENCY: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = latency(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_MASTER_VOLUME: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    float _arg0;
    _arg0 = data.readFloat();
    int res = setMasterVolume(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_MASTER_MUTE: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    bool _arg0;
    _arg0 = data.readInt32();
    int res = setMasterMute(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case MASTER_VOLUME: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int res = masterVolume();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case MASTER_MUTE: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int res = masterMute()? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_STREAM_VOLUME: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    float _arg1;
    _arg1 = data.readFloat();
    int _arg2;
    _arg2 = data.readInt32();
    int res = setStreamVolume(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_STREAM_MUTE: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    bool _arg1;
    _arg1 = data.readInt32();
    int res = setStreamMute(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case STREAM_VOLUME: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int res = streamVolume(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case STREAM_MUTE: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = streamMute(_arg0)? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_MODE: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = setMode(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_MIC_MUTE: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    bool _arg0;
    _arg0 = data.readInt32();
    int res = setMicMute(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_MIC_MUTE: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int res = getMicMute()? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_PARAMETERS: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    String8 _arg1;
    _arg1 = data.readString8();
    int res = setParameters(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_PARAMETERS: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    String8 _arg1;
    _arg1 = data.readString8();
    int res = getParameters(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case REGISTER_CLIENT: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    const sp<IAudioFlingerClient>& _arg0;
    _arg0 = data.readStrongIAudioFlingerClient();
    int res = registerClient(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_INPUT_BUFFER_SIZE: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int res = getInputBufferSize(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case OPEN_OUTPUT: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int _arg3;
    _arg3 = data.readInt32();
    int _arg4;
    _arg4 = data.readInt32();
    int _arg5;
    _arg5 = data.readInt32();
    int _arg6;
    _arg6 = data.readInt32();
    int res = openOutput(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(pDevices);
data._data.writeInt32(%s);
(pSamplingRate);
data._data.writeInt32(%s);
(pFormat);
data._data.writeInt32(%s);
(pChannelMask);
data._data.writeInt32(%s);
(pLatencyMs);
    return NO_ERROR;
    }
case OPEN_DUPLICATE_OUTPUT: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int res = openDuplicateOutput(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CLOSE_OUTPUT: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = closeOutput(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SUSPEND_OUTPUT: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = suspendOutput(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case RESTORE_OUTPUT: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = restoreOutput(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case OPEN_INPUT: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int _arg3;
    _arg3 = data.readInt32();
    int _arg4;
    _arg4 = data.readInt32();
    int res = openInput(_arg0, _arg1, _arg2, _arg3, _arg4);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(pDevices);
data._data.writeInt32(%s);
(pSamplingRate);
data._data.writeInt32(%s);
(pFormat);
data._data.writeInt32(%s);
(pChannelMask);
    return NO_ERROR;
    }
case CLOSE_INPUT: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = closeInput(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_STREAM_OUTPUT: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int res = setStreamOutput(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_VOICE_VOLUME: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    float _arg0;
    _arg0 = data.readFloat();
    int res = setVoiceVolume(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_RENDER_POSITION: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    int _arg1;
    int _arg2;
    _arg2 = data.readInt32();
    getRenderPosition(_arg0, _arg1, _arg2);
data._data.writeInt32(%s);
(halFrames);
data._data.writeInt32(%s);
(dspFrames);
    return NO_ERROR;
    }
case GET_INPUT_FRAMES_LOST: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = getInputFramesLost(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case NEW_AUDIO_SESSION_ID: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int res = newAudioSessionId();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case ACQUIRE_AUDIO_SESSION_ID: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = acquireAudioSessionId(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case RELEASE_AUDIO_SESSION_ID: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = releaseAudioSessionId(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case QUERY_NUMBER_EFFECTS: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    int res = queryNumberEffects(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(numEffects);
    return NO_ERROR;
    }
case QUERY_EFFECT: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<effect_descriptor_t>& _arg1;
    int res = queryEffect(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(pDescriptor);
    return NO_ERROR;
    }
case GET_EFFECT_DESCRIPTOR: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    const sp<effect_uuid_t>& _arg0;
    _arg0 = data.readStrongeffect_uuid_t();
    const sp<effect_descriptor_t>& _arg1;
    int res = getEffectDescriptor(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(pDescriptor);
    return NO_ERROR;
    }
case CREATE_EFFECT: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<effect_descriptor_t>& _arg1;
    _arg1 = data.readStrongeffect_descriptor_t();
    const sp<IEffectClient>& _arg2;
    _arg2 = data.readStrongIEffectClient();
    int _arg3;
    _arg3 = data.readInt32();
    int _arg4;
    _arg4 = data.readInt32();
    int _arg5;
    _arg5 = data.readInt32();
    const sp<status_t>& _arg6;
    int _arg7;
    int _arg8;
    int res = createEffect(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(pDesc);
data.%s.writeToParcel(&_data);
(status);
data._data.writeInt32(%s);
(id);
data._data.writeInt32(%s);
(enabled);
    return NO_ERROR;
    }
case MOVE_EFFECTS: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int res = moveEffects(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case LOAD_HW_MODULE: {
    CHECK_INTERFACE(IAudioFlinger, data, reply);
    CString _arg0;
    _arg0 = data.readCString();
    int res = loadHwModule(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
