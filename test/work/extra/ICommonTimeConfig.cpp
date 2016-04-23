/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ICommonTimeConfig.aidl
 */
#define LOG_TAG "CommonTimeConfig"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <commontimeconfig/ICommonTimeConfig.h>

namespace android {

class BpCommonTimeConfig : public BpInterface<ICommonTimeConfig>
{
    public:
    BpCommonTimeConfig(const sp<IBinder>& impl)
        : BpInterface<ICommonTimeConfig>(impl) { }

virtual const sp<status_t>& getMasterElectionPriority(int priority)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonTimeConfig::getInterfaceDescriptor());
    remote()->transact(BnCommonTimeConfig::GET_MASTER_ELECTION_PRIORITY, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setMasterElectionPriority(int priority)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonTimeConfig::getInterfaceDescriptor());
    _data.writeInt32(priority);
    remote()->transact(BnCommonTimeConfig::SET_MASTER_ELECTION_PRIORITY, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getMasterElectionEndpoint(const sp<sockaddr_storage>& addr)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonTimeConfig::getInterfaceDescriptor());
    remote()->transact(BnCommonTimeConfig::GET_MASTER_ELECTION_ENDPOINT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setMasterElectionEndpoint(const sp<sockaddr_storage>& addr)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonTimeConfig::getInterfaceDescriptor());
    addr.writeToParcel(&_data);
    remote()->transact(BnCommonTimeConfig::SET_MASTER_ELECTION_ENDPOINT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getMasterElectionGroupId(long id)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonTimeConfig::getInterfaceDescriptor());
    remote()->transact(BnCommonTimeConfig::GET_MASTER_ELECTION_GROUP_ID, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setMasterElectionGroupId(long id)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonTimeConfig::getInterfaceDescriptor());
    _data.writeInt64(id);
    remote()->transact(BnCommonTimeConfig::SET_MASTER_ELECTION_GROUP_ID, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getInterfaceBinding(const String16& ifaceName)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonTimeConfig::getInterfaceDescriptor());
    _data.writeString16(ifaceName);
    remote()->transact(BnCommonTimeConfig::GET_INTERFACE_BINDING, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setInterfaceBinding(const String16& ifaceName)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonTimeConfig::getInterfaceDescriptor());
    _data.writeString16(ifaceName);
    remote()->transact(BnCommonTimeConfig::SET_INTERFACE_BINDING, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getMasterAnnounceInterval(int interval)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonTimeConfig::getInterfaceDescriptor());
    remote()->transact(BnCommonTimeConfig::GET_MASTER_ANNOUNCE_INTERVAL, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setMasterAnnounceInterval(int interval)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonTimeConfig::getInterfaceDescriptor());
    _data.writeInt32(interval);
    remote()->transact(BnCommonTimeConfig::SET_MASTER_ANNOUNCE_INTERVAL, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getClientSyncInterval(int interval)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonTimeConfig::getInterfaceDescriptor());
    remote()->transact(BnCommonTimeConfig::GET_CLIENT_SYNC_INTERVAL, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setClientSyncInterval(int interval)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonTimeConfig::getInterfaceDescriptor());
    _data.writeInt32(interval);
    remote()->transact(BnCommonTimeConfig::SET_CLIENT_SYNC_INTERVAL, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getPanicThreshold(int threshold)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonTimeConfig::getInterfaceDescriptor());
    remote()->transact(BnCommonTimeConfig::GET_PANIC_THRESHOLD, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setPanicThreshold(int threshold)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonTimeConfig::getInterfaceDescriptor());
    _data.writeInt32(threshold);
    remote()->transact(BnCommonTimeConfig::SET_PANIC_THRESHOLD, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getAutoDisable(bool autoDisable)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonTimeConfig::getInterfaceDescriptor());
    remote()->transact(BnCommonTimeConfig::GET_AUTO_DISABLE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setAutoDisable(bool autoDisable)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonTimeConfig::getInterfaceDescriptor());
    _data.writeInt32((int)autoDisable);
    remote()->transact(BnCommonTimeConfig::SET_AUTO_DISABLE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& forceNetworklessMasterMode()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonTimeConfig::getInterfaceDescriptor());
    remote()->transact(BnCommonTimeConfig::FORCE_NETWORKLESS_MASTER_MODE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(CommonTimeConfig, "android.os.ICommonTimeConfig");

status_t BnCommonTimeConfig::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case GET_MASTER_ELECTION_PRIORITY: {
    CHECK_INTERFACE(ICommonTimeConfig, data, reply);
    int _arg0;
    int res = getMasterElectionPriority(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(priority);
    return NO_ERROR;
    }
case SET_MASTER_ELECTION_PRIORITY: {
    CHECK_INTERFACE(ICommonTimeConfig, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = setMasterElectionPriority(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_MASTER_ELECTION_ENDPOINT: {
    CHECK_INTERFACE(ICommonTimeConfig, data, reply);
    const sp<sockaddr_storage>& _arg0;
    int res = getMasterElectionEndpoint(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(addr);
    return NO_ERROR;
    }
case SET_MASTER_ELECTION_ENDPOINT: {
    CHECK_INTERFACE(ICommonTimeConfig, data, reply);
    const sp<sockaddr_storage>& _arg0;
    _arg0 = data.readStrongsockaddr_storage();
    int res = setMasterElectionEndpoint(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_MASTER_ELECTION_GROUP_ID: {
    CHECK_INTERFACE(ICommonTimeConfig, data, reply);
    long _arg0;
    int res = getMasterElectionGroupId(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt64(%s);
(id);
    return NO_ERROR;
    }
case SET_MASTER_ELECTION_GROUP_ID: {
    CHECK_INTERFACE(ICommonTimeConfig, data, reply);
    long _arg0;
    _arg0 = data.readInt64();
    int res = setMasterElectionGroupId(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_INTERFACE_BINDING: {
    CHECK_INTERFACE(ICommonTimeConfig, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    int res = getInterfaceBinding(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_INTERFACE_BINDING: {
    CHECK_INTERFACE(ICommonTimeConfig, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    int res = setInterfaceBinding(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_MASTER_ANNOUNCE_INTERVAL: {
    CHECK_INTERFACE(ICommonTimeConfig, data, reply);
    int _arg0;
    int res = getMasterAnnounceInterval(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(interval);
    return NO_ERROR;
    }
case SET_MASTER_ANNOUNCE_INTERVAL: {
    CHECK_INTERFACE(ICommonTimeConfig, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = setMasterAnnounceInterval(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_CLIENT_SYNC_INTERVAL: {
    CHECK_INTERFACE(ICommonTimeConfig, data, reply);
    int _arg0;
    int res = getClientSyncInterval(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(interval);
    return NO_ERROR;
    }
case SET_CLIENT_SYNC_INTERVAL: {
    CHECK_INTERFACE(ICommonTimeConfig, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = setClientSyncInterval(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_PANIC_THRESHOLD: {
    CHECK_INTERFACE(ICommonTimeConfig, data, reply);
    int _arg0;
    int res = getPanicThreshold(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(threshold);
    return NO_ERROR;
    }
case SET_PANIC_THRESHOLD: {
    CHECK_INTERFACE(ICommonTimeConfig, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = setPanicThreshold(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_AUTO_DISABLE: {
    CHECK_INTERFACE(ICommonTimeConfig, data, reply);
    bool _arg0;
    int res = getAutoDisable(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32((int)%s);
(autoDisable);
    return NO_ERROR;
    }
case SET_AUTO_DISABLE: {
    CHECK_INTERFACE(ICommonTimeConfig, data, reply);
    bool _arg0;
    _arg0 = data.readInt32();
    int res = setAutoDisable(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case FORCE_NETWORKLESS_MASTER_MODE: {
    CHECK_INTERFACE(ICommonTimeConfig, data, reply);
    int res = forceNetworklessMasterMode();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
