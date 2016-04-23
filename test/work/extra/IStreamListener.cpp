/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IStreamListener.aidl
 */
#define LOG_TAG "StreamListener"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <streamlistener/IStreamListener.h>

namespace android {

class BpStreamListener : public BpInterface<IStreamListener>
{
    public:
    BpStreamListener(const sp<IBinder>& impl)
        : BpInterface<IStreamListener>(impl) { }

virtual status_t bogus_setListener()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IStreamListener::getInterfaceDescriptor());
    return remote()->transact(BnStreamListener::BOGUS_SET_LISTENER, _data, &reply);
}
/* only in IStreamSource */
virtual status_t bogus_setBuffers()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IStreamListener::getInterfaceDescriptor());
    return remote()->transact(BnStreamListener::BOGUS_SET_BUFFERS, _data, &reply);
}
/* only in IStreamSource */
virtual status_t bogus_onBufferAvailable()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IStreamListener::getInterfaceDescriptor());
    return remote()->transact(BnStreamListener::BOGUS_ON_BUFFER_AVAILABLE, _data, &reply);
}
/* only in IStreamSource */
virtual status_t queueBuffer(const sp<size_t>& index, const sp<size_t>& size)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IStreamListener::getInterfaceDescriptor());
    index.writeToParcel(&_data);
    size.writeToParcel(&_data);
    return remote()->transact(BnStreamListener::QUEUE_BUFFER, _data, &reply);
}

virtual status_t issueCommand(int cmd, bool synchronous, const sp<AMessage>& msg)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IStreamListener::getInterfaceDescriptor());
    _data.writeInt32(cmd);
    _data.writeInt32((int)synchronous);
    msg.writeToParcel(&_data);
    return remote()->transact(BnStreamListener::ISSUE_COMMAND, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(StreamListener, "android.os.IStreamListener");

status_t BnStreamListener::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case BOGUS_SET_LISTENER: {
    CHECK_INTERFACE(IStreamListener, data, reply);
    bogus_setListener();
    return NO_ERROR;
    }
case BOGUS_SET_BUFFERS: {
    CHECK_INTERFACE(IStreamListener, data, reply);
    bogus_setBuffers();
    return NO_ERROR;
    }
case BOGUS_ON_BUFFER_AVAILABLE: {
    CHECK_INTERFACE(IStreamListener, data, reply);
    bogus_onBufferAvailable();
    return NO_ERROR;
    }
case QUEUE_BUFFER: {
    CHECK_INTERFACE(IStreamListener, data, reply);
    const sp<size_t>& _arg0;
    _arg0 = data.readStrongsize_t();
    const sp<size_t>& _arg1;
    _arg1 = data.readStrongsize_t();
    queueBuffer(_arg0, _arg1);
    return NO_ERROR;
    }
case ISSUE_COMMAND: {
    CHECK_INTERFACE(IStreamListener, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    bool _arg1;
    _arg1 = data.readInt32();
    const sp<AMessage>& _arg2;
    _arg2 = data.readStrongAMessage();
    issueCommand(_arg0, _arg1, _arg2);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
