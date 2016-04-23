/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IAudioPolicyService.aidl
 */
#define LOG_TAG "AudioPolicyService"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <audiopolicyservice/IAudioPolicyService.h>

namespace android {

class BpAudioPolicyService : public BpInterface<IAudioPolicyService>
{
    public:
    BpAudioPolicyService(const sp<IBinder>& impl)
        : BpInterface<IAudioPolicyService>(impl) { }

virtual const sp<status_t>& setDeviceConnectionState(int device, int state, const CString& device_address)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(device);
    _data.writeInt32(state);
    _data.writeCString(device_address);
    remote()->transact(BnAudioPolicyService::SET_DEVICE_CONNECTION_STATE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int getDeviceConnectionState(int device, const CString& device_address)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(device);
    _data.writeCString(device_address);
    remote()->transact(BnAudioPolicyService::GET_DEVICE_CONNECTION_STATE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setPhoneState(int state)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(state);
    remote()->transact(BnAudioPolicyService::SET_PHONE_STATE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setRingerMode_unused()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    remote()->transact(BnAudioPolicyService::SET_RINGER_MODE_UNUSED, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setForceUse(int usage, int config)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(usage);
    _data.writeInt32(config);
    remote()->transact(BnAudioPolicyService::SET_FORCE_USE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int getForceUse(int usage)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(usage);
    remote()->transact(BnAudioPolicyService::GET_FORCE_USE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int getOutput(int stream, int samplingRate, int format, int channels, int flags)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(stream);
    _data.writeInt32(samplingRate);
    _data.writeInt32(format);
    _data.writeInt32(channels);
    _data.writeInt32(flags);
    remote()->transact(BnAudioPolicyService::GET_OUTPUT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& startOutput(int output, int stream, int session)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(output);
    _data.writeInt32(stream);
    _data.writeInt32(session);
    remote()->transact(BnAudioPolicyService::START_OUTPUT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& stopOutput(int output, int stream, int session)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(output);
    _data.writeInt32(stream);
    _data.writeInt32(session);
    remote()->transact(BnAudioPolicyService::STOP_OUTPUT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& releaseOutput(int output)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(output);
    remote()->transact(BnAudioPolicyService::RELEASE_OUTPUT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int getInput(int inputSource, int samplingRate, int format, int channels, int acoustics, int audioSession)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(inputSource);
    _data.writeInt32(samplingRate);
    _data.writeInt32(format);
    _data.writeInt32(channels);
    _data.writeInt32(acoustics);
    _data.writeInt32(audioSession);
    remote()->transact(BnAudioPolicyService::GET_INPUT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& startInput(int input)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(input);
    remote()->transact(BnAudioPolicyService::START_INPUT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& stopInput(int input)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(input);
    remote()->transact(BnAudioPolicyService::STOP_INPUT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& releaseInput(int input)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(input);
    remote()->transact(BnAudioPolicyService::RELEASE_INPUT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& initStreamVolume(int stream, int indexMin, int indexMax)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(stream);
    _data.writeInt32(indexMin);
    _data.writeInt32(indexMax);
    remote()->transact(BnAudioPolicyService::INIT_STREAM_VOLUME, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setStreamVolumeIndex(int stream, int index, int device)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(stream);
    _data.writeInt32(index);
    _data.writeInt32(device);
    remote()->transact(BnAudioPolicyService::SET_STREAM_VOLUME_INDEX, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getStreamVolumeIndex(int stream, int index, int device)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(stream);
    _data.writeInt32(device);
    remote()->transact(BnAudioPolicyService::GET_STREAM_VOLUME_INDEX, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int getStrategyForStream(int stream)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(stream);
    remote()->transact(BnAudioPolicyService::GET_STRATEGY_FOR_STREAM, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int getOutputForEffect(const sp<effect_descriptor_t>& desc)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    desc.writeToParcel(&_data);
    remote()->transact(BnAudioPolicyService::GET_OUTPUT_FOR_EFFECT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& registerEffect(const sp<effect_descriptor_t>& desc, int io, int strategy, int session, int id)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    desc.writeToParcel(&_data);
    _data.writeInt32(io);
    _data.writeInt32(strategy);
    _data.writeInt32(session);
    _data.writeInt32(id);
    remote()->transact(BnAudioPolicyService::REGISTER_EFFECT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& unregisterEffect(int id)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(id);
    remote()->transact(BnAudioPolicyService::UNREGISTER_EFFECT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual bool isStreamActive(int stream, int inPastMs)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(stream);
    _data.writeInt32(inPastMs);
    remote()->transact(BnAudioPolicyService::IS_STREAM_ACTIVE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int getDevicesForStream(int stream)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(stream);
    remote()->transact(BnAudioPolicyService::GET_DEVICES_FOR_STREAM, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& queryDefaultPreProcessing(int audioSession, const sp<effect_descriptor_t>& descriptors, int count)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(audioSession);
    remote()->transact(BnAudioPolicyService::QUERY_DEFAULT_PRE_PROCESSING, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setEffectEnabled(int id, bool enabled)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioPolicyService::getInterfaceDescriptor());
    _data.writeInt32(id);
    _data.writeInt32((int)enabled);
    remote()->transact(BnAudioPolicyService::SET_EFFECT_ENABLED, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(AudioPolicyService, "android.os.IAudioPolicyService");

status_t BnAudioPolicyService::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case SET_DEVICE_CONNECTION_STATE: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    CString _arg2;
    _arg2 = data.readCString();
    int res = setDeviceConnectionState(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_DEVICE_CONNECTION_STATE: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    CString _arg1;
    _arg1 = data.readCString();
    int res = getDeviceConnectionState(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_PHONE_STATE: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = setPhoneState(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_RINGER_MODE_UNUSED: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int res = setRingerMode_unused();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_FORCE_USE: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int res = setForceUse(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_FORCE_USE: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = getForceUse(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_OUTPUT: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
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
    int res = getOutput(_arg0, _arg1, _arg2, _arg3, _arg4);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case START_OUTPUT: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int res = startOutput(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case STOP_OUTPUT: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int res = stopOutput(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case RELEASE_OUTPUT: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = releaseOutput(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_INPUT: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
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
    int res = getInput(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case START_INPUT: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = startInput(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case STOP_INPUT: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = stopInput(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case RELEASE_INPUT: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = releaseInput(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case INIT_STREAM_VOLUME: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int res = initStreamVolume(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_STREAM_VOLUME_INDEX: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int res = setStreamVolumeIndex(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_STREAM_VOLUME_INDEX: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    int _arg2;
    _arg2 = data.readInt32();
    int res = getStreamVolumeIndex(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(index);
    return NO_ERROR;
    }
case GET_STRATEGY_FOR_STREAM: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = getStrategyForStream(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_OUTPUT_FOR_EFFECT: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    const sp<effect_descriptor_t>& _arg0;
    _arg0 = data.readStrongeffect_descriptor_t();
    int res = getOutputForEffect(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case REGISTER_EFFECT: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    const sp<effect_descriptor_t>& _arg0;
    _arg0 = data.readStrongeffect_descriptor_t();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int _arg3;
    _arg3 = data.readInt32();
    int _arg4;
    _arg4 = data.readInt32();
    int res = registerEffect(_arg0, _arg1, _arg2, _arg3, _arg4);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case UNREGISTER_EFFECT: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = unregisterEffect(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case IS_STREAM_ACTIVE: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int res = isStreamActive(_arg0, _arg1)? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_DEVICES_FOR_STREAM: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = getDevicesForStream(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case QUERY_DEFAULT_PRE_PROCESSING: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<effect_descriptor_t>& _arg1;
    int _arg2;
    int res = queryDefaultPreProcessing(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(descriptors);
data._data.writeInt32(%s);
(count);
    return NO_ERROR;
    }
case SET_EFFECT_ENABLED: {
    CHECK_INTERFACE(IAudioPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    bool _arg1;
    _arg1 = data.readInt32();
    int res = setEffectEnabled(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
