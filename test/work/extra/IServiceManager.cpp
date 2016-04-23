/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IServiceManager.aidl
 */
#define LOG_TAG "ServiceManager"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <servicemanager/IServiceManager.h>

namespace android {

class BpServiceManager : public BpInterface<IServiceManager>
{
    public:
    BpServiceManager(const sp<IBinder>& impl)
        : BpInterface<IServiceManager>(impl) { }

virtual sp<IBinder> getService(const String16& name)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IServiceManager::getInterfaceDescriptor());
    _data.writeString16(name);
    remote()->transact(BnServiceManager::GET_SERVICE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual sp<IBinder> checkService(const String16& name)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IServiceManager::getInterfaceDescriptor());
    _data.writeString16(name);
    remote()->transact(BnServiceManager::CHECK_SERVICE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t addService(const String16& name, const sp<IBinder>& service, bool allowIsolated)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IServiceManager::getInterfaceDescriptor());
    _data.writeString16(name);
    _data.writeStrongBinder(service);
    _data.writeInt32((int)allowIsolated);
    return remote()->transact(BnServiceManager::ADD_SERVICE, _data, &reply);
}

virtual String16 listServices()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IServiceManager::getInterfaceDescriptor());
    remote()->transact(BnServiceManager::LIST_SERVICES, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(ServiceManager, "android.os.IServiceManager");

status_t BnServiceManager::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case GET_SERVICE: {
    CHECK_INTERFACE(IServiceManager, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    int res = getService(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CHECK_SERVICE: {
    CHECK_INTERFACE(IServiceManager, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    int res = checkService(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case ADD_SERVICE: {
    CHECK_INTERFACE(IServiceManager, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    sp<IBinder> _arg1;
    _arg1 = data.readStrongBinder();
    bool _arg2;
    _arg2 = data.readInt32();
    addService(_arg0, _arg1, _arg2);
    return NO_ERROR;
    }
case LIST_SERVICES: {
    CHECK_INTERFACE(IServiceManager, data, reply);
    int res = listServices();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
