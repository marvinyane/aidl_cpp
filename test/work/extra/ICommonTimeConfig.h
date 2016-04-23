/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ICommonTimeConfig.aidl
 */
#ifndef ANDROID_ICOMMON_TIME_CONFIG_H
#define ANDROID_ICOMMON_TIME_CONFIG_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class ICommonTimeConfig : public IInterface
{
public:
    DECLARE_META_INTERFACE(CommonTimeConfig);
    virtual const sp<status_t>& getMasterElectionPriority(int priority) = 0;
    virtual const sp<status_t>& setMasterElectionPriority(int priority) = 0;
    virtual const sp<status_t>& getMasterElectionEndpoint(const sp<sockaddr_storage>& addr) = 0;
    virtual const sp<status_t>& setMasterElectionEndpoint(const sp<sockaddr_storage>& addr) = 0;
    virtual const sp<status_t>& getMasterElectionGroupId(long id) = 0;
    virtual const sp<status_t>& setMasterElectionGroupId(long id) = 0;
    virtual const sp<status_t>& getInterfaceBinding(const String16& ifaceName) = 0;
    virtual const sp<status_t>& setInterfaceBinding(const String16& ifaceName) = 0;
    virtual const sp<status_t>& getMasterAnnounceInterval(int interval) = 0;
    virtual const sp<status_t>& setMasterAnnounceInterval(int interval) = 0;
    virtual const sp<status_t>& getClientSyncInterval(int interval) = 0;
    virtual const sp<status_t>& setClientSyncInterval(int interval) = 0;
    virtual const sp<status_t>& getPanicThreshold(int threshold) = 0;
    virtual const sp<status_t>& setPanicThreshold(int threshold) = 0;
    virtual const sp<status_t>& getAutoDisable(bool autoDisable) = 0;
    virtual const sp<status_t>& setAutoDisable(bool autoDisable) = 0;
    virtual const sp<status_t>& forceNetworklessMasterMode() = 0;
};

class BnCommonTimeConfig : public BnInterface<ICommonTimeConfig>
{
public:
    enum {
        GET_MASTER_ELECTION_PRIORITY = IBinder::FIRST_CALL_TRANSACTION,
        SET_MASTER_ELECTION_PRIORITY,
        GET_MASTER_ELECTION_ENDPOINT,
        SET_MASTER_ELECTION_ENDPOINT,
        GET_MASTER_ELECTION_GROUP_ID,
        SET_MASTER_ELECTION_GROUP_ID,
        GET_INTERFACE_BINDING,
        SET_INTERFACE_BINDING,
        GET_MASTER_ANNOUNCE_INTERVAL,
        SET_MASTER_ANNOUNCE_INTERVAL,
        GET_CLIENT_SYNC_INTERVAL,
        SET_CLIENT_SYNC_INTERVAL,
        GET_PANIC_THRESHOLD,
        SET_PANIC_THRESHOLD,
        GET_AUTO_DISABLE,
        SET_AUTO_DISABLE,
        FORCE_NETWORKLESS_MASTER_MODE,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ICOMMON_TIME_CONFIG_H
