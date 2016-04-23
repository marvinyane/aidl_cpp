/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ICommonClock.aidl
 */
#define LOG_TAG "CommonClock"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <commonclock/ICommonClock.h>

namespace android {

class BpCommonClock : public BpInterface<ICommonClock>
{
    public:
    BpCommonClock(const sp<IBinder>& impl)
        : BpInterface<ICommonClock>(impl) { }

virtual const sp<status_t>& isCommonTimeValid(bool valid, int timelineID)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonClock::getInterfaceDescriptor());
    remote()->transact(BnCommonClock::IS_COMMON_TIME_VALID, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& commonTimeToLocalTime(long commonTime, long localTime)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonClock::getInterfaceDescriptor());
    _data.writeInt64(commonTime);
    remote()->transact(BnCommonClock::COMMON_TIME_TO_LOCAL_TIME, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& localTimeToCommonTime(long localTime, long commonTime)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonClock::getInterfaceDescriptor());
    _data.writeInt64(localTime);
    remote()->transact(BnCommonClock::LOCAL_TIME_TO_COMMON_TIME, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getCommonTime(long commonTime)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonClock::getInterfaceDescriptor());
    remote()->transact(BnCommonClock::GET_COMMON_TIME, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getCommonFreq(long freq)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonClock::getInterfaceDescriptor());
    remote()->transact(BnCommonClock::GET_COMMON_FREQ, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getLocalTime(long localTime)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonClock::getInterfaceDescriptor());
    remote()->transact(BnCommonClock::GET_LOCAL_TIME, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getLocalFreq(long freq)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonClock::getInterfaceDescriptor());
    remote()->transact(BnCommonClock::GET_LOCAL_FREQ, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getEstimatedError(int estimate)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonClock::getInterfaceDescriptor());
    remote()->transact(BnCommonClock::GET_ESTIMATED_ERROR, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getTimelineID(long id)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonClock::getInterfaceDescriptor());
    remote()->transact(BnCommonClock::GET_TIMELINE_ID, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getState(const sp<State>& state)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonClock::getInterfaceDescriptor());
    remote()->transact(BnCommonClock::GET_STATE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getMasterAddr(const sp<sockaddr_storage>& addr)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonClock::getInterfaceDescriptor());
    remote()->transact(BnCommonClock::GET_MASTER_ADDR, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& registerListener(const sp<ICommonClockListener>& listener)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonClock::getInterfaceDescriptor());
    listener.writeToParcel(&_data);
    remote()->transact(BnCommonClock::REGISTER_LISTENER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& unregisterListener(const sp<ICommonClockListener>& listener)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonClock::getInterfaceDescriptor());
    listener.writeToParcel(&_data);
    remote()->transact(BnCommonClock::UNREGISTER_LISTENER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(CommonClock, "android.os.ICommonClock");

status_t BnCommonClock::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case IS_COMMON_TIME_VALID: {
    CHECK_INTERFACE(ICommonClock, data, reply);
    bool _arg0;
    int _arg1;
    int res = isCommonTimeValid(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32((int)%s);
(valid);
data._data.writeInt32(%s);
(timelineID);
    return NO_ERROR;
    }
case COMMON_TIME_TO_LOCAL_TIME: {
    CHECK_INTERFACE(ICommonClock, data, reply);
    long _arg0;
    _arg0 = data.readInt64();
    long _arg1;
    int res = commonTimeToLocalTime(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt64(%s);
(localTime);
    return NO_ERROR;
    }
case LOCAL_TIME_TO_COMMON_TIME: {
    CHECK_INTERFACE(ICommonClock, data, reply);
    long _arg0;
    _arg0 = data.readInt64();
    long _arg1;
    int res = localTimeToCommonTime(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt64(%s);
(commonTime);
    return NO_ERROR;
    }
case GET_COMMON_TIME: {
    CHECK_INTERFACE(ICommonClock, data, reply);
    long _arg0;
    int res = getCommonTime(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt64(%s);
(commonTime);
    return NO_ERROR;
    }
case GET_COMMON_FREQ: {
    CHECK_INTERFACE(ICommonClock, data, reply);
    long _arg0;
    int res = getCommonFreq(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt64(%s);
(freq);
    return NO_ERROR;
    }
case GET_LOCAL_TIME: {
    CHECK_INTERFACE(ICommonClock, data, reply);
    long _arg0;
    int res = getLocalTime(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt64(%s);
(localTime);
    return NO_ERROR;
    }
case GET_LOCAL_FREQ: {
    CHECK_INTERFACE(ICommonClock, data, reply);
    long _arg0;
    int res = getLocalFreq(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt64(%s);
(freq);
    return NO_ERROR;
    }
case GET_ESTIMATED_ERROR: {
    CHECK_INTERFACE(ICommonClock, data, reply);
    int _arg0;
    int res = getEstimatedError(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(estimate);
    return NO_ERROR;
    }
case GET_TIMELINE_ID: {
    CHECK_INTERFACE(ICommonClock, data, reply);
    long _arg0;
    int res = getTimelineID(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt64(%s);
(id);
    return NO_ERROR;
    }
case GET_STATE: {
    CHECK_INTERFACE(ICommonClock, data, reply);
    const sp<State>& _arg0;
    int res = getState(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(state);
    return NO_ERROR;
    }
case GET_MASTER_ADDR: {
    CHECK_INTERFACE(ICommonClock, data, reply);
    const sp<sockaddr_storage>& _arg0;
    int res = getMasterAddr(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(addr);
    return NO_ERROR;
    }
case REGISTER_LISTENER: {
    CHECK_INTERFACE(ICommonClock, data, reply);
    const sp<ICommonClockListener>& _arg0;
    _arg0 = data.readStrongICommonClockListener();
    int res = registerListener(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case UNREGISTER_LISTENER: {
    CHECK_INTERFACE(ICommonClock, data, reply);
    const sp<ICommonClockListener>& _arg0;
    _arg0 = data.readStrongICommonClockListener();
    int res = unregisterListener(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
