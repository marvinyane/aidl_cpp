/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IObbActionListener.aidl
 */
#define LOG_TAG "ObbActionListener"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <obbactionlistener/IObbActionListener.h>

namespace android {

class BpObbActionListener : public BpInterface<IObbActionListener>
{
    public:
    BpObbActionListener(const sp<IBinder>& impl)
        : BpInterface<IObbActionListener>(impl) { }

virtual status_t onObbResult(const String16& filename, int nonce, int state)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IObbActionListener::getInterfaceDescriptor());
    _data.writeString16(filename);
    _data.writeInt32(nonce);
    _data.writeInt32(state);
    return remote()->transact(BnObbActionListener::ON_OBB_RESULT, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(ObbActionListener, "android.os.IObbActionListener");

status_t BnObbActionListener::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case ON_OBB_RESULT: {
    CHECK_INTERFACE(IObbActionListener, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    onObbResult(_arg0, _arg1, _arg2);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
