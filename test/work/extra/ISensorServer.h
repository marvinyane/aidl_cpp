/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ISensorServer.aidl
 */
#ifndef ANDROID_ISENSOR_SERVER_H
#define ANDROID_ISENSOR_SERVER_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class ISensorServer : public IInterface
{
public:
    DECLARE_META_INTERFACE(SensorServer);
    virtual const sp<Sensor>&[] getSensorList() = 0;
    virtual const sp<ISensorEventConnection>& createSensorEventConnection() = 0;
};

class BnSensorServer : public BnInterface<ISensorServer>
{
public:
    enum {
        GET_SENSOR_LIST = IBinder::FIRST_CALL_TRANSACTION,
        CREATE_SENSOR_EVENT_CONNECTION,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ISENSOR_SERVER_H
