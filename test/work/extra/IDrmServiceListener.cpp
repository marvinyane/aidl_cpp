/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IDrmServiceListener.aidl
 */
#define LOG_TAG "DrmServiceListener"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <drmservicelistener/IDrmServiceListener.h>

namespace android {

class BpDrmServiceListener : public BpInterface<IDrmServiceListener>
{
    public:
    BpDrmServiceListener(const sp<IBinder>& impl)
        : BpInterface<IDrmServiceListener>(impl) { }

virtual const sp<status_t>& notify(const sp<DrmInfoEvent>& event)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmServiceListener::getInterfaceDescriptor());
    event.writeToParcel(&_data);
    remote()->transact(BnDrmServiceListener::NOTIFY, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(DrmServiceListener, "android.os.IDrmServiceListener");

status_t BnDrmServiceListener::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case NOTIFY: {
    CHECK_INTERFACE(IDrmServiceListener, data, reply);
    const sp<DrmInfoEvent>& _arg0;
    _arg0 = data.readStrongDrmInfoEvent();
    int res = notify(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
