/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ISensorServer.aidl
 */
#define LOG_TAG "SensorServer"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <sensorserver/ISensorServer.h>

namespace android {

class BpSensorServer : public BpInterface<ISensorServer>
{
    public:
    BpSensorServer(const sp<IBinder>& impl)
        : BpInterface<ISensorServer>(impl) { }

virtual const sp<Sensor>&[] getSensorList()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISensorServer::getInterfaceDescriptor());
    remote()->transact(BnSensorServer::GET_SENSOR_LIST, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<ISensorEventConnection>& createSensorEventConnection()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISensorServer::getInterfaceDescriptor());
    remote()->transact(BnSensorServer::CREATE_SENSOR_EVENT_CONNECTION, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(SensorServer, "android.os.ISensorServer");

status_t BnSensorServer::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case GET_SENSOR_LIST: {
    CHECK_INTERFACE(ISensorServer, data, reply);
    int res = getSensorList();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CREATE_SENSOR_EVENT_CONNECTION: {
    CHECK_INTERFACE(ISensorServer, data, reply);
    int res = createSensorEventConnection();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
