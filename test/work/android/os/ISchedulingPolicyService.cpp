/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: aidl/android/os/ISchedulingPolicyService.aidl
 */
#define LOG_TAG "SchedulingPolicyService"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <schedulingpolicyservice/ISchedulingPolicyService.h>

namespace android {

class BpSchedulingPolicyService : public BpInterface<ISchedulingPolicyService>
{
    public:
    BpSchedulingPolicyService(const sp<IBinder>& impl)
        : BpInterface<ISchedulingPolicyService>(impl) { }
/**
     * Move thread tid into appropriate cgroup and assign it priority prio.
     * The thread group leader of tid must be pid.
     * There may be restrictions on who can call this.
     */
virtual int requestPriority(int pid, int tid, int prio)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISchedulingPolicyService::getInterfaceDescriptor());
    _data.writeInt32(pid);
    _data.writeInt32(tid);
    _data.writeInt32(prio);
    remote()->transact(BnSchedulingPolicyService::REQUEST_PRIORITY, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(SchedulingPolicyService, "android.os.ISchedulingPolicyService");

status_t BnSchedulingPolicyService::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case REQUEST_PRIORITY: {
    CHECK_INTERFACE(ISchedulingPolicyService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int res = requestPriority(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
