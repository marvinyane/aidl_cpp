/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ICommonClockListener.aidl
 */
#define LOG_TAG "CommonClockListener"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <commonclocklistener/ICommonClockListener.h>

namespace android {

class BpCommonClockListener : public BpInterface<ICommonClockListener>
{
    public:
    BpCommonClockListener(const sp<IBinder>& impl)
        : BpInterface<ICommonClockListener>(impl) { }

virtual status_t onTimelineChanged(long timelineID)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICommonClockListener::getInterfaceDescriptor());
    _data.writeInt64(timelineID);
    return remote()->transact(BnCommonClockListener::ON_TIMELINE_CHANGED, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(CommonClockListener, "android.os.ICommonClockListener");

status_t BnCommonClockListener::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case ON_TIMELINE_CHANGED: {
    CHECK_INTERFACE(ICommonClockListener, data, reply);
    long _arg0;
    _arg0 = data.readInt64();
    onTimelineChanged(_arg0);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
