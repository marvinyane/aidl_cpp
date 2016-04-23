/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IAudioRecord.aidl
 */
#ifndef ANDROID_IAUDIO_RECORD_H
#define ANDROID_IAUDIO_RECORD_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IAudioRecord : public IInterface
{
public:
    DECLARE_META_INTERFACE(AudioRecord);
    virtual const sp<IMemory>& getCblk() = 0;
    virtual const sp<status_t>& start(int event, int triggerSession) = 0;
    virtual status_t stop() = 0;
};

class BnAudioRecord : public BnInterface<IAudioRecord>
{
public:
    enum {
        GET_CBLK = IBinder::FIRST_CALL_TRANSACTION,
        START,
        STOP,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IAUDIO_RECORD_H
