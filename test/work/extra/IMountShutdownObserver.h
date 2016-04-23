/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMountShutdownObserver.aidl
 */
#ifndef ANDROID_IMOUNT_SHUTDOWN_OBSERVER_H
#define ANDROID_IMOUNT_SHUTDOWN_OBSERVER_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IMountShutdownObserver : public IInterface
{
public:
    DECLARE_META_INTERFACE(MountShutdownObserver);
    virtual status_t onShutDownComplete(int statusCode) = 0;
};

class BnMountShutdownObserver : public BnInterface<IMountShutdownObserver>
{
public:
    enum {
        ON_SHUT_DOWN_COMPLETE = IBinder::FIRST_CALL_TRANSACTION,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IMOUNT_SHUTDOWN_OBSERVER_H
