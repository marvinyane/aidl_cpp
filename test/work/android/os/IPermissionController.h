/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: aidl/android/os/IPermissionController.aidl
 */
#ifndef ANDROID_IPERMISSION_CONTROLLER_H
#define ANDROID_IPERMISSION_CONTROLLER_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IPermissionController : public IInterface
{
public:
    DECLARE_META_INTERFACE(PermissionController);
    virtual bool checkPermission(const String16& permission, int pid, int uid) = 0;
};

class BnPermissionController : public BnInterface<IPermissionController>
{
public:
    enum {
        CHECK_PERMISSION = IBinder::FIRST_CALL_TRANSACTION,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IPERMISSION_CONTROLLER_H
