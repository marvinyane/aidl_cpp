/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: aidl/android/os/IPermissionController.aidl
 */
#define LOG_TAG "PermissionController"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <permissioncontroller/IPermissionController.h>

namespace android {

class BpPermissionController : public BpInterface<IPermissionController>
{
    public:
    BpPermissionController(const sp<IBinder>& impl)
        : BpInterface<IPermissionController>(impl) { }

virtual bool checkPermission(const String16& permission, int pid, int uid)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPermissionController::getInterfaceDescriptor());
    _data.writeString16(permission);
    _data.writeInt32(pid);
    _data.writeInt32(uid);
    remote()->transact(BnPermissionController::CHECK_PERMISSION, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(PermissionController, "android.os.IPermissionController");

status_t BnPermissionController::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case CHECK_PERMISSION: {
    CHECK_INTERFACE(IPermissionController, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int res = checkPermission(_arg0, _arg1, _arg2)? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
