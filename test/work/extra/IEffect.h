/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IEffect.aidl
 */
#ifndef ANDROID_IEFFECT_H
#define ANDROID_IEFFECT_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IEffect : public IInterface
{
public:
    DECLARE_META_INTERFACE(Effect);
    virtual const sp<status_t>& enable() = 0;
    virtual const sp<status_t>& disable() = 0;
    virtual const sp<status_t>& command(int cmdCode, int cmdSize, const sp<void>& pCmdData, int pReplySize, const sp<void>& pReplyData) = 0;
    virtual status_t disconnect() = 0;
    virtual const sp<IMemory>& getCblk() = 0;
};

class BnEffect : public BnInterface<IEffect>
{
public:
    enum {
        ENABLE = IBinder::FIRST_CALL_TRANSACTION,
        DISABLE,
        COMMAND,
        DISCONNECT,
        GET_CBLK,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IEFFECT_H
