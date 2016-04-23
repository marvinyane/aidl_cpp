/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IAudioPolicyService.aidl
 */
#ifndef ANDROID_IAUDIO_POLICY_SERVICE_H
#define ANDROID_IAUDIO_POLICY_SERVICE_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IAudioPolicyService : public IInterface
{
public:
    DECLARE_META_INTERFACE(AudioPolicyService);
    virtual const sp<status_t>& setDeviceConnectionState(int device, int state, const CString& device_address) = 0;
    virtual int getDeviceConnectionState(int device, const CString& device_address) = 0;
    virtual const sp<status_t>& setPhoneState(int state) = 0;
    virtual const sp<status_t>& setRingerMode_unused() = 0;
    virtual const sp<status_t>& setForceUse(int usage, int config) = 0;
    virtual int getForceUse(int usage) = 0;
    virtual int getOutput(int stream, int samplingRate, int format, int channels, int flags) = 0;
    virtual const sp<status_t>& startOutput(int output, int stream, int session) = 0;
    virtual const sp<status_t>& stopOutput(int output, int stream, int session) = 0;
    virtual const sp<status_t>& releaseOutput(int output) = 0;
    virtual int getInput(int inputSource, int samplingRate, int format, int channels, int acoustics, int audioSession) = 0;
    virtual const sp<status_t>& startInput(int input) = 0;
    virtual const sp<status_t>& stopInput(int input) = 0;
    virtual const sp<status_t>& releaseInput(int input) = 0;
    virtual const sp<status_t>& initStreamVolume(int stream, int indexMin, int indexMax) = 0;
    virtual const sp<status_t>& setStreamVolumeIndex(int stream, int index, int device) = 0;
    virtual const sp<status_t>& getStreamVolumeIndex(int stream, int index, int device) = 0;
    virtual int getStrategyForStream(int stream) = 0;
    virtual int getOutputForEffect(const sp<effect_descriptor_t>& desc) = 0;
    virtual const sp<status_t>& registerEffect(const sp<effect_descriptor_t>& desc, int io, int strategy, int session, int id) = 0;
    virtual const sp<status_t>& unregisterEffect(int id) = 0;
    virtual bool isStreamActive(int stream, int inPastMs) = 0;
    virtual int getDevicesForStream(int stream) = 0;
    virtual const sp<status_t>& queryDefaultPreProcessing(int audioSession, const sp<effect_descriptor_t>& descriptors, int count) = 0;
    virtual const sp<status_t>& setEffectEnabled(int id, bool enabled) = 0;
};

class BnAudioPolicyService : public BnInterface<IAudioPolicyService>
{
public:
    enum {
        SET_DEVICE_CONNECTION_STATE = IBinder::FIRST_CALL_TRANSACTION,
        GET_DEVICE_CONNECTION_STATE,
        SET_PHONE_STATE,
        SET_RINGER_MODE_UNUSED,
        SET_FORCE_USE,
        GET_FORCE_USE,
        GET_OUTPUT,
        START_OUTPUT,
        STOP_OUTPUT,
        RELEASE_OUTPUT,
        GET_INPUT,
        START_INPUT,
        STOP_INPUT,
        RELEASE_INPUT,
        INIT_STREAM_VOLUME,
        SET_STREAM_VOLUME_INDEX,
        GET_STREAM_VOLUME_INDEX,
        GET_STRATEGY_FOR_STREAM,
        GET_OUTPUT_FOR_EFFECT,
        REGISTER_EFFECT,
        UNREGISTER_EFFECT,
        IS_STREAM_ACTIVE,
        GET_DEVICES_FOR_STREAM,
        QUERY_DEFAULT_PRE_PROCESSING,
        SET_EFFECT_ENABLED,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IAUDIO_POLICY_SERVICE_H
