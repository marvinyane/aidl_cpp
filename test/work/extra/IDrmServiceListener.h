/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IDrmServiceListener.aidl
 */
#ifndef ANDROID_IDRM_SERVICE_LISTENER_H
#define ANDROID_IDRM_SERVICE_LISTENER_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IDrmServiceListener : public IInterface
{
public:
    DECLARE_META_INTERFACE(DrmServiceListener);
    virtual const sp<status_t>& notify(const sp<DrmInfoEvent>& event) = 0;
};

class BnDrmServiceListener : public BnInterface<IDrmServiceListener>
{
public:
    enum {
        NOTIFY = IBinder::FIRST_CALL_TRANSACTION,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IDRM_SERVICE_LISTENER_H
