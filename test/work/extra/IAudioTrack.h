/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IAudioTrack.aidl
 */
#ifndef ANDROID_IAUDIO_TRACK_H
#define ANDROID_IAUDIO_TRACK_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IAudioTrack : public IInterface
{
public:
    DECLARE_META_INTERFACE(AudioTrack);
    virtual const sp<IMemory>& getCblk() = 0;
    virtual const sp<status_t>& start() = 0;
    virtual status_t stop() = 0;
    virtual status_t flush() = 0;
    virtual status_t mute(bool e) = 0;
    virtual status_t pause() = 0;
    virtual const sp<status_t>& attachAuxEffect(int effectId) = 0;
    virtual const sp<status_t>& allocateTimedBuffer(int size, const sp<IMemory>& buffer) = 0;
    virtual const sp<status_t>& queueTimedBuffer(const sp<IMemory>& buffer, long pts) = 0;
    virtual const sp<status_t>& setMediaTimeTransform(const sp<LinearTransform>& xform, int target) = 0;
};

class BnAudioTrack : public BnInterface<IAudioTrack>
{
public:
    enum {
        GET_CBLK = IBinder::FIRST_CALL_TRANSACTION,
        START,
        STOP,
        FLUSH,
        MUTE,
        PAUSE,
        ATTACH_AUX_EFFECT,
        ALLOCATE_TIMED_BUFFER,
        QUEUE_TIMED_BUFFER,
        SET_MEDIA_TIME_TRANSFORM,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IAUDIO_TRACK_H
