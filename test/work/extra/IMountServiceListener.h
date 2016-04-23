/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMountServiceListener.aidl
 */
#ifndef ANDROID_IMOUNT_SERVICE_LISTENER_H
#define ANDROID_IMOUNT_SERVICE_LISTENER_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IMountServiceListener : public IInterface
{
public:
    DECLARE_META_INTERFACE(MountServiceListener);
    virtual status_t onUsbMassStorageConnectionChanged(bool connected) = 0;
    virtual status_t onStorageStateChanged(const String16& path, const String16& oldState, const String16& newState) = 0;
};

class BnMountServiceListener : public BnInterface<IMountServiceListener>
{
public:
    enum {
        ON_USB_MASS_STORAGE_CONNECTION_CHANGED = IBinder::FIRST_CALL_TRANSACTION,
        ON_STORAGE_STATE_CHANGED,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IMOUNT_SERVICE_LISTENER_H
