/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IAudioFlingerClient.aidl
 */
#ifndef ANDROID_IAUDIO_FLINGER_CLIENT_H
#define ANDROID_IAUDIO_FLINGER_CLIENT_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IAudioFlingerClient : public IInterface
{
public:
    DECLARE_META_INTERFACE(AudioFlingerClient);
    virtual status_t ioConfigChanged(int event, int ioHandle, int param2) = 0;
};

class BnAudioFlingerClient : public BnInterface<IAudioFlingerClient>
{
public:
    enum {
        IO_CONFIG_CHANGED = IBinder::FIRST_CALL_TRANSACTION,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IAUDIO_FLINGER_CLIENT_H
