/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: aidl/android/os/IPowerManager.aidl
 */
#ifndef ANDROID_IPOWER_MANAGER_H
#define ANDROID_IPOWER_MANAGER_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IPowerManager : public IInterface
{
public:
    DECLARE_META_INTERFACE(PowerManager);
    virtual status_t acquireWakeLock(int flags, const sp<IBinder>& lock, const String16& tag, WorkSource ws) = 0;
    virtual status_t updateWakeLockWorkSource(const sp<IBinder>& lock, WorkSource ws) = 0;
    virtual status_t goToSleep(long time) = 0;
    virtual status_t goToSleepWithReason(long time, int reason) = 0;
    virtual status_t releaseWakeLock(const sp<IBinder>& lock, int flags) = 0;
    virtual status_t userActivity(long when, bool noChangeLights) = 0;
    virtual status_t userActivityWithForce(long when, bool noChangeLights, bool force) = 0;
    virtual status_t clearUserActivityTimeout(long now, long timeout) = 0;
    virtual status_t setPokeLock(int pokey, const sp<IBinder>& lock, const String16& tag) = 0;
    virtual int getSupportedWakeLockFlags() = 0;
    virtual status_t setStayOnSetting(int val) = 0;
    virtual status_t setMaximumScreenOffTimeount(int timeMs) = 0;
    virtual status_t preventScreenOn(bool prevent) = 0;
    virtual bool isScreenOn() = 0;
    virtual status_t reboot(const String16& reason) = 0;
    virtual status_t crash(const String16& message) = 0;
    virtual status_t setBacklightBrightness(int brightness) = 0;
    virtual status_t setAttentionLight(bool on, int color) = 0;
    virtual status_t setAutoBrightnessAdjustment(float adj) = 0;
};

class BnPowerManager : public BnInterface<IPowerManager>
{
public:
    enum {
        ACQUIRE_WAKE_LOCK = IBinder::FIRST_CALL_TRANSACTION,
        UPDATE_WAKE_LOCK_WORK_SOURCE,
        GO_TO_SLEEP,
        GO_TO_SLEEP_WITH_REASON,
        RELEASE_WAKE_LOCK,
        USER_ACTIVITY,
        USER_ACTIVITY_WITH_FORCE,
        CLEAR_USER_ACTIVITY_TIMEOUT,
        SET_POKE_LOCK,
        GET_SUPPORTED_WAKE_LOCK_FLAGS,
        SET_STAY_ON_SETTING,
        SET_MAXIMUM_SCREEN_OFF_TIMEOUNT,
        PREVENT_SCREEN_ON,
        IS_SCREEN_ON,
        REBOOT,
        CRASH,
        SET_BACKLIGHT_BRIGHTNESS,
        SET_ATTENTION_LIGHT,
        SET_AUTO_BRIGHTNESS_ADJUSTMENT,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IPOWER_MANAGER_H
