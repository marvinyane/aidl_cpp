/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ICommonClock.aidl
 */
#ifndef ANDROID_ICOMMON_CLOCK_H
#define ANDROID_ICOMMON_CLOCK_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class ICommonClock : public IInterface
{
public:
    DECLARE_META_INTERFACE(CommonClock);
    virtual const sp<status_t>& isCommonTimeValid(bool valid, int timelineID) = 0;
    virtual const sp<status_t>& commonTimeToLocalTime(long commonTime, long localTime) = 0;
    virtual const sp<status_t>& localTimeToCommonTime(long localTime, long commonTime) = 0;
    virtual const sp<status_t>& getCommonTime(long commonTime) = 0;
    virtual const sp<status_t>& getCommonFreq(long freq) = 0;
    virtual const sp<status_t>& getLocalTime(long localTime) = 0;
    virtual const sp<status_t>& getLocalFreq(long freq) = 0;
    virtual const sp<status_t>& getEstimatedError(int estimate) = 0;
    virtual const sp<status_t>& getTimelineID(long id) = 0;
    virtual const sp<status_t>& getState(const sp<State>& state) = 0;
    virtual const sp<status_t>& getMasterAddr(const sp<sockaddr_storage>& addr) = 0;
    virtual const sp<status_t>& registerListener(const sp<ICommonClockListener>& listener) = 0;
    virtual const sp<status_t>& unregisterListener(const sp<ICommonClockListener>& listener) = 0;
};

class BnCommonClock : public BnInterface<ICommonClock>
{
public:
    enum {
        IS_COMMON_TIME_VALID = IBinder::FIRST_CALL_TRANSACTION,
        COMMON_TIME_TO_LOCAL_TIME,
        LOCAL_TIME_TO_COMMON_TIME,
        GET_COMMON_TIME,
        GET_COMMON_FREQ,
        GET_LOCAL_TIME,
        GET_LOCAL_FREQ,
        GET_ESTIMATED_ERROR,
        GET_TIMELINE_ID,
        GET_STATE,
        GET_MASTER_ADDR,
        REGISTER_LISTENER,
        UNREGISTER_LISTENER,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ICOMMON_CLOCK_H
