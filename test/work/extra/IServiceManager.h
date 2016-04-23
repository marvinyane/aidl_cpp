/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IServiceManager.aidl
 */
#ifndef ANDROID_ISERVICE_MANAGER_H
#define ANDROID_ISERVICE_MANAGER_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IServiceManager : public IInterface
{
public:
    DECLARE_META_INTERFACE(ServiceManager);
    virtual sp<IBinder> getService(const String16& name) = 0;
    virtual sp<IBinder> checkService(const String16& name) = 0;
    virtual status_t addService(const String16& name, const sp<IBinder>& service, bool allowIsolated) = 0;
    virtual String16 listServices() = 0;
};

class BnServiceManager : public BnInterface<IServiceManager>
{
public:
    enum {
        GET_SERVICE = IBinder::FIRST_CALL_TRANSACTION,
        CHECK_SERVICE,
        ADD_SERVICE,
        LIST_SERVICES,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ISERVICE_MANAGER_H
