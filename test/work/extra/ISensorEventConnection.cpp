/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ISensorEventConnection.aidl
 */
#define LOG_TAG "SensorEventConnection"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <sensoreventconnection/ISensorEventConnection.h>

namespace android {

class BpSensorEventConnection : public BpInterface<ISensorEventConnection>
{
    public:
    BpSensorEventConnection(const sp<IBinder>& impl)
        : BpInterface<ISensorEventConnection>(impl) { }

virtual const sp<BitTube>& getSensorChannel()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISensorEventConnection::getInterfaceDescriptor());
    remote()->transact(BnSensorEventConnection::GET_SENSOR_CHANNEL, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& enableDisable(int handle, bool enabled)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISensorEventConnection::getInterfaceDescriptor());
    _data.writeInt32(handle);
    _data.writeInt32((int)enabled);
    remote()->transact(BnSensorEventConnection::ENABLE_DISABLE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setEventRate(int handle, long ns)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISensorEventConnection::getInterfaceDescriptor());
    _data.writeInt32(handle);
    _data.writeInt64(ns);
    remote()->transact(BnSensorEventConnection::SET_EVENT_RATE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(SensorEventConnection, "android.os.ISensorEventConnection");

status_t BnSensorEventConnection::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case GET_SENSOR_CHANNEL: {
    CHECK_INTERFACE(ISensorEventConnection, data, reply);
    int res = getSensorChannel();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case ENABLE_DISABLE: {
    CHECK_INTERFACE(ISensorEventConnection, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    bool _arg1;
    _arg1 = data.readInt32();
    int res = enableDisable(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_EVENT_RATE: {
    CHECK_INTERFACE(ISensorEventConnection, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    long _arg1;
    _arg1 = data.readInt64();
    int res = setEventRate(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
