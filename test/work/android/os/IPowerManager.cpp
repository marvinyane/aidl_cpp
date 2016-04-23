/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: aidl/android/os/IPowerManager.aidl
 */
#define LOG_TAG "PowerManager"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <powermanager/IPowerManager.h>

namespace android {

class BpPowerManager : public BpInterface<IPowerManager>
{
    public:
    BpPowerManager(const sp<IBinder>& impl)
        : BpInterface<IPowerManager>(impl) { }
// WARNING: changes in acquireWakeLock() signature must be reflected in IPowerManager.cpp/h

virtual status_t acquireWakeLock(int flags, const sp<IBinder>& lock, const String16& tag, WorkSource ws)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    _data.writeInt32(flags);
    _data.writeStrongBinder(lock);
    _data.writeString16(tag);
    _data.writeInt32(0);
    return remote()->transact(BnPowerManager::ACQUIRE_WAKE_LOCK, _data, &reply);
}

virtual status_t updateWakeLockWorkSource(const sp<IBinder>& lock, WorkSource ws)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    _data.writeStrongBinder(lock);
    _data.writeInt32(0);
    return remote()->transact(BnPowerManager::UPDATE_WAKE_LOCK_WORK_SOURCE, _data, &reply);
}

virtual status_t goToSleep(long time)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    _data.writeInt64(time);
    return remote()->transact(BnPowerManager::GO_TO_SLEEP, _data, &reply);
}

virtual status_t goToSleepWithReason(long time, int reason)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    _data.writeInt64(time);
    _data.writeInt32(reason);
    return remote()->transact(BnPowerManager::GO_TO_SLEEP_WITH_REASON, _data, &reply);
}
// WARNING: changes in releaseWakeLock() signature must be reflected in IPowerManager.cpp/h

virtual status_t releaseWakeLock(const sp<IBinder>& lock, int flags)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    _data.writeStrongBinder(lock);
    _data.writeInt32(flags);
    return remote()->transact(BnPowerManager::RELEASE_WAKE_LOCK, _data, &reply);
}

virtual status_t userActivity(long when, bool noChangeLights)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    _data.writeInt64(when);
    _data.writeInt32((int)noChangeLights);
    return remote()->transact(BnPowerManager::USER_ACTIVITY, _data, &reply);
}

virtual status_t userActivityWithForce(long when, bool noChangeLights, bool force)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    _data.writeInt64(when);
    _data.writeInt32((int)noChangeLights);
    _data.writeInt32((int)force);
    return remote()->transact(BnPowerManager::USER_ACTIVITY_WITH_FORCE, _data, &reply);
}

virtual status_t clearUserActivityTimeout(long now, long timeout)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    _data.writeInt64(now);
    _data.writeInt64(timeout);
    return remote()->transact(BnPowerManager::CLEAR_USER_ACTIVITY_TIMEOUT, _data, &reply);
}

virtual status_t setPokeLock(int pokey, const sp<IBinder>& lock, const String16& tag)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    _data.writeInt32(pokey);
    _data.writeStrongBinder(lock);
    _data.writeString16(tag);
    return remote()->transact(BnPowerManager::SET_POKE_LOCK, _data, &reply);
}

virtual int getSupportedWakeLockFlags()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    remote()->transact(BnPowerManager::GET_SUPPORTED_WAKE_LOCK_FLAGS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t setStayOnSetting(int val)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    _data.writeInt32(val);
    return remote()->transact(BnPowerManager::SET_STAY_ON_SETTING, _data, &reply);
}

virtual status_t setMaximumScreenOffTimeount(int timeMs)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    _data.writeInt32(timeMs);
    return remote()->transact(BnPowerManager::SET_MAXIMUM_SCREEN_OFF_TIMEOUNT, _data, &reply);
}

virtual status_t preventScreenOn(bool prevent)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    _data.writeInt32((int)prevent);
    return remote()->transact(BnPowerManager::PREVENT_SCREEN_ON, _data, &reply);
}

virtual bool isScreenOn()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    remote()->transact(BnPowerManager::IS_SCREEN_ON, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t reboot(const String16& reason)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    _data.writeString16(reason);
    return remote()->transact(BnPowerManager::REBOOT, _data, &reply);
}

virtual status_t crash(const String16& message)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    _data.writeString16(message);
    return remote()->transact(BnPowerManager::CRASH, _data, &reply);
}
// sets the brightness of the backlights (screen, keyboard, button) 0-255

virtual status_t setBacklightBrightness(int brightness)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    _data.writeInt32(brightness);
    return remote()->transact(BnPowerManager::SET_BACKLIGHT_BRIGHTNESS, _data, &reply);
}

virtual status_t setAttentionLight(bool on, int color)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    _data.writeInt32((int)on);
    _data.writeInt32(color);
    return remote()->transact(BnPowerManager::SET_ATTENTION_LIGHT, _data, &reply);
}

virtual status_t setAutoBrightnessAdjustment(float adj)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IPowerManager::getInterfaceDescriptor());
    _data.writeFloat(adj);
    return remote()->transact(BnPowerManager::SET_AUTO_BRIGHTNESS_ADJUSTMENT, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(PowerManager, "android.os.IPowerManager");

status_t BnPowerManager::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case ACQUIRE_WAKE_LOCK: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    sp<IBinder> _arg1;
    _arg1 = data.readStrongBinder();
    String16 _arg2;
    _arg2 = data.readString16();
    WorkSource _arg3;
    _arg3 = data.readInt32();
    acquireWakeLock(_arg0, _arg1, _arg2, _arg3);
    return NO_ERROR;
    }
case UPDATE_WAKE_LOCK_WORK_SOURCE: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    sp<IBinder> _arg0;
    _arg0 = data.readStrongBinder();
    WorkSource _arg1;
    _arg1 = data.readInt32();
    updateWakeLockWorkSource(_arg0, _arg1);
    return NO_ERROR;
    }
case GO_TO_SLEEP: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    long _arg0;
    _arg0 = data.readInt64();
    goToSleep(_arg0);
    return NO_ERROR;
    }
case GO_TO_SLEEP_WITH_REASON: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    long _arg0;
    _arg0 = data.readInt64();
    int _arg1;
    _arg1 = data.readInt32();
    goToSleepWithReason(_arg0, _arg1);
    return NO_ERROR;
    }
case RELEASE_WAKE_LOCK: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    sp<IBinder> _arg0;
    _arg0 = data.readStrongBinder();
    int _arg1;
    _arg1 = data.readInt32();
    releaseWakeLock(_arg0, _arg1);
    return NO_ERROR;
    }
case USER_ACTIVITY: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    long _arg0;
    _arg0 = data.readInt64();
    bool _arg1;
    _arg1 = data.readInt32();
    userActivity(_arg0, _arg1);
    return NO_ERROR;
    }
case USER_ACTIVITY_WITH_FORCE: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    long _arg0;
    _arg0 = data.readInt64();
    bool _arg1;
    _arg1 = data.readInt32();
    bool _arg2;
    _arg2 = data.readInt32();
    userActivityWithForce(_arg0, _arg1, _arg2);
    return NO_ERROR;
    }
case CLEAR_USER_ACTIVITY_TIMEOUT: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    long _arg0;
    _arg0 = data.readInt64();
    long _arg1;
    _arg1 = data.readInt64();
    clearUserActivityTimeout(_arg0, _arg1);
    return NO_ERROR;
    }
case SET_POKE_LOCK: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    sp<IBinder> _arg1;
    _arg1 = data.readStrongBinder();
    String16 _arg2;
    _arg2 = data.readString16();
    setPokeLock(_arg0, _arg1, _arg2);
    return NO_ERROR;
    }
case GET_SUPPORTED_WAKE_LOCK_FLAGS: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    int res = getSupportedWakeLockFlags();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_STAY_ON_SETTING: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    setStayOnSetting(_arg0);
    return NO_ERROR;
    }
case SET_MAXIMUM_SCREEN_OFF_TIMEOUNT: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    setMaximumScreenOffTimeount(_arg0);
    return NO_ERROR;
    }
case PREVENT_SCREEN_ON: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    bool _arg0;
    _arg0 = data.readInt32();
    preventScreenOn(_arg0);
    return NO_ERROR;
    }
case IS_SCREEN_ON: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    int res = isScreenOn()? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case REBOOT: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    reboot(_arg0);
    return NO_ERROR;
    }
case CRASH: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    crash(_arg0);
    return NO_ERROR;
    }
case SET_BACKLIGHT_BRIGHTNESS: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    setBacklightBrightness(_arg0);
    return NO_ERROR;
    }
case SET_ATTENTION_LIGHT: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    bool _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    setAttentionLight(_arg0, _arg1);
    return NO_ERROR;
    }
case SET_AUTO_BRIGHTNESS_ADJUSTMENT: {
    CHECK_INTERFACE(IPowerManager, data, reply);
    float _arg0;
    _arg0 = data.readFloat();
    setAutoBrightnessAdjustment(_arg0);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
