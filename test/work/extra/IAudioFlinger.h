/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IAudioFlinger.aidl
 */
#ifndef ANDROID_IAUDIO_FLINGER_H
#define ANDROID_IAUDIO_FLINGER_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IAudioFlinger : public IInterface
{
public:
    DECLARE_META_INTERFACE(AudioFlinger);
    virtual const sp<IAudioTrack>& createTrack(int pid, int streamType, int sampleRate, int format, int channelMask, int frameCount, int flags, const sp<IMemory>& sharedBuffer, int output, int tid, int sessionId, const sp<status_t>& status) = 0;
    virtual const sp<IAudioRecord>& openRecord(int pid, int input, int sampleRate, int format, int channelMask, int frameCount, int flags, int sessionId, const sp<void>& status) = 0;
    virtual int sampleRate(int output) = 0;
    virtual int channelCount(int output) = 0;
    virtual int format(int output) = 0;
    virtual long frameCount(int output) = 0;
    virtual int latency(int output) = 0;
    virtual const sp<status_t>& setMasterVolume(float value) = 0;
    virtual const sp<status_t>& setMasterMute(bool muted) = 0;
    virtual float masterVolume() = 0;
    virtual bool masterMute() = 0;
    virtual const sp<status_t>& setStreamVolume(int stream, float value, int output) = 0;
    virtual const sp<status_t>& setStreamMute(int stream, bool muted) = 0;
    virtual float streamVolume(int stream, int output) = 0;
    virtual bool streamMute(int stream) = 0;
    virtual const sp<status_t>& setMode(int mode) = 0;
    virtual const sp<status_t>& setMicMute(bool state) = 0;
    virtual bool getMicMute() = 0;
    virtual const sp<status_t>& setParameters(int ioHandle, const String8& keyValuePairs) = 0;
    virtual String8 getParameters(int ioHandle, const String8& keys) = 0;
    virtual const sp<status_t>& registerClient(const sp<IAudioFlingerClient>& client) = 0;
    virtual int getInputBufferSize(int sampleRate, int format, int channelCount) = 0;
    virtual int openOutput(int module, int pDevices, int pSamplingRate, int pFormat, int pChannelMask, int pLatencyMs, int flags) = 0;
    virtual int openDuplicateOutput(int output1, int output2) = 0;
    virtual const sp<status_t>& closeOutput(int output) = 0;
    virtual const sp<status_t>& suspendOutput(int output) = 0;
    virtual const sp<status_t>& restoreOutput(int output) = 0;
    virtual int openInput(int module, int pDevices, int pSamplingRate, int pFormat, int pChannelMask) = 0;
    virtual const sp<status_t>& closeInput(int input) = 0;
    virtual const sp<status_t>& setStreamOutput(int stream, int output) = 0;
    virtual const sp<status_t>& setVoiceVolume(float volume) = 0;
    virtual status_t getRenderPosition(int halFrames, int dspFrames, int output) = 0;
    virtual int getInputFramesLost(int ioHandle) = 0;
    virtual int newAudioSessionId() = 0;
    virtual const sp<status_t>& acquireAudioSessionId(int audioSession) = 0;
    virtual const sp<status_t>& releaseAudioSessionId(int audioSession) = 0;
    virtual const sp<status_t>& queryNumberEffects(int numEffects) = 0;
    virtual const sp<status_t>& queryEffect(int index, const sp<effect_descriptor_t>& pDescriptor) = 0;
    virtual const sp<status_t>& getEffectDescriptor(const sp<effect_uuid_t>& pEffectUUID, const sp<effect_descriptor_t>& pDescriptor) = 0;
    virtual const sp<IEffect>& createEffect(int pid, const sp<effect_descriptor_t>& pDesc, const sp<IEffectClient>& client, int priority, int output, int sessionId, const sp<status_t>& status, int id, int enabled) = 0;
    virtual const sp<status_t>& moveEffects(int session, int srcOutput, int dstOutput) = 0;
    virtual int loadHwModule(const CString& name) = 0;
};

class BnAudioFlinger : public BnInterface<IAudioFlinger>
{
public:
    enum {
        CREATE_TRACK = IBinder::FIRST_CALL_TRANSACTION,
        OPEN_RECORD,
        SAMPLE_RATE,
        CHANNEL_COUNT,
        FORMAT,
        FRAME_COUNT,
        LATENCY,
        SET_MASTER_VOLUME,
        SET_MASTER_MUTE,
        MASTER_VOLUME,
        MASTER_MUTE,
        SET_STREAM_VOLUME,
        SET_STREAM_MUTE,
        STREAM_VOLUME,
        STREAM_MUTE,
        SET_MODE,
        SET_MIC_MUTE,
        GET_MIC_MUTE,
        SET_PARAMETERS,
        GET_PARAMETERS,
        REGISTER_CLIENT,
        GET_INPUT_BUFFER_SIZE,
        OPEN_OUTPUT,
        OPEN_DUPLICATE_OUTPUT,
        CLOSE_OUTPUT,
        SUSPEND_OUTPUT,
        RESTORE_OUTPUT,
        OPEN_INPUT,
        CLOSE_INPUT,
        SET_STREAM_OUTPUT,
        SET_VOICE_VOLUME,
        GET_RENDER_POSITION,
        GET_INPUT_FRAMES_LOST,
        NEW_AUDIO_SESSION_ID,
        ACQUIRE_AUDIO_SESSION_ID,
        RELEASE_AUDIO_SESSION_ID,
        QUERY_NUMBER_EFFECTS,
        QUERY_EFFECT,
        GET_EFFECT_DESCRIPTOR,
        CREATE_EFFECT,
        MOVE_EFFECTS,
        LOAD_HW_MODULE,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IAUDIO_FLINGER_H
