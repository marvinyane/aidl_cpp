/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ISensorEventConnection.aidl
 */
#ifndef ANDROID_ISENSOR_EVENT_CONNECTION_H
#define ANDROID_ISENSOR_EVENT_CONNECTION_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class ISensorEventConnection : public IInterface
{
public:
    DECLARE_META_INTERFACE(SensorEventConnection);
    virtual const sp<BitTube>& getSensorChannel() = 0;
    virtual const sp<status_t>& enableDisable(int handle, bool enabled) = 0;
    virtual const sp<status_t>& setEventRate(int handle, long ns) = 0;
};

class BnSensorEventConnection : public BnInterface<ISensorEventConnection>
{
public:
    enum {
        GET_SENSOR_CHANNEL = IBinder::FIRST_CALL_TRANSACTION,
        ENABLE_DISABLE,
        SET_EVENT_RATE,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ISENSOR_EVENT_CONNECTION_H
