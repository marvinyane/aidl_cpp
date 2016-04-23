/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: aidl/android/os/ISchedulingPolicyService.aidl
 */
#ifndef ANDROID_ISCHEDULING_POLICY_SERVICE_H
#define ANDROID_ISCHEDULING_POLICY_SERVICE_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class ISchedulingPolicyService : public IInterface
{
public:
    DECLARE_META_INTERFACE(SchedulingPolicyService);
    virtual int requestPriority(int pid, int tid, int prio) = 0;
};

class BnSchedulingPolicyService : public BnInterface<ISchedulingPolicyService>
{
public:
    enum {
        REQUEST_PRIORITY = IBinder::FIRST_CALL_TRANSACTION,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ISCHEDULING_POLICY_SERVICE_H
