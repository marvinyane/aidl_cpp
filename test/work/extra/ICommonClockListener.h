/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ICommonClockListener.aidl
 */
#ifndef ANDROID_ICOMMON_CLOCK_LISTENER_H
#define ANDROID_ICOMMON_CLOCK_LISTENER_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class ICommonClockListener : public IInterface
{
public:
    DECLARE_META_INTERFACE(CommonClockListener);
    virtual status_t onTimelineChanged(long timelineID) = 0;
};

class BnCommonClockListener : public BnInterface<ICommonClockListener>
{
public:
    enum {
        ON_TIMELINE_CHANGED = IBinder::FIRST_CALL_TRANSACTION,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ICOMMON_CLOCK_LISTENER_H
