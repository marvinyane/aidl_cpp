/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IEffectClient.aidl
 */
#ifndef ANDROID_IEFFECT_CLIENT_H
#define ANDROID_IEFFECT_CLIENT_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IEffectClient : public IInterface
{
public:
    DECLARE_META_INTERFACE(EffectClient);
    virtual status_t controlStatusChanged(bool controlGranted) = 0;
    virtual status_t enableStatusChanged(bool enabled) = 0;
    virtual status_t commandExecuted(int cmdCode, int cmdSize, const sp<void>& pCmdData, int replySize, const sp<void>& pReplyData) = 0;
};

class BnEffectClient : public BnInterface<IEffectClient>
{
public:
    enum {
        CONTROL_STATUS_CHANGED = IBinder::FIRST_CALL_TRANSACTION,
        ENABLE_STATUS_CHANGED,
        COMMAND_EXECUTED,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IEFFECT_CLIENT_H
