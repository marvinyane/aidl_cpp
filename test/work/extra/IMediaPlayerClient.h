/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMediaPlayerClient.aidl
 */
#ifndef ANDROID_IMEDIA_PLAYER_CLIENT_H
#define ANDROID_IMEDIA_PLAYER_CLIENT_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IMediaPlayerClient : public IInterface
{
public:
    DECLARE_META_INTERFACE(MediaPlayerClient);
    virtual status_t notify(int msg, int ext1, int ext2, const sp<zParcel>& obj) = 0;
};

class BnMediaPlayerClient : public BnInterface<IMediaPlayerClient>
{
public:
    enum {
        NOTIFY = IBinder::FIRST_CALL_TRANSACTION,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IMEDIA_PLAYER_CLIENT_H