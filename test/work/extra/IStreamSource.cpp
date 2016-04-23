/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IStreamSource.aidl
 */
#define LOG_TAG "StreamSource"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <streamsource/IStreamSource.h>

namespace android {

class BpStreamSource : public BpInterface<IStreamSource>
{
    public:
    BpStreamSource(const sp<IBinder>& impl)
        : BpInterface<IStreamSource>(impl) { }

virtual status_t setListener(const sp<IStreamListener>& listener)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IStreamSource::getInterfaceDescriptor());
    listener.writeToParcel(&_data);
    return remote()->transact(BnStreamSource::SET_LISTENER, _data, &reply);
}

virtual status_t setBuffers(const sp<IMemory>& buffers)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IStreamSource::getInterfaceDescriptor());
    buffers.writeToParcel(&_data);
    return remote()->transact(BnStreamSource::SET_BUFFERS, _data, &reply);
}

virtual status_t onBufferAvailable(const sp<size_t>& index)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IStreamSource::getInterfaceDescriptor());
    index.writeToParcel(&_data);
    return remote()->transact(BnStreamSource::ON_BUFFER_AVAILABLE, _data, &reply);
}

virtual status_t bogus_queueBuffer()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IStreamSource::getInterfaceDescriptor());
    return remote()->transact(BnStreamSource::BOGUS_QUEUE_BUFFER, _data, &reply);
}
/* only in IStreamListener */
virtual status_t bogus_issueCommand()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IStreamSource::getInterfaceDescriptor());
    return remote()->transact(BnStreamSource::BOGUS_ISSUE_COMMAND, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(StreamSource, "android.os.IStreamSource");

status_t BnStreamSource::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case SET_LISTENER: {
    CHECK_INTERFACE(IStreamSource, data, reply);
    const sp<IStreamListener>& _arg0;
    _arg0 = data.readStrongIStreamListener();
    setListener(_arg0);
    return NO_ERROR;
    }
case SET_BUFFERS: {
    CHECK_INTERFACE(IStreamSource, data, reply);
    const sp<IMemory>& _arg0;
    _arg0 = data.readStrongIMemory();
    setBuffers(_arg0);
    return NO_ERROR;
    }
case ON_BUFFER_AVAILABLE: {
    CHECK_INTERFACE(IStreamSource, data, reply);
    const sp<size_t>& _arg0;
    _arg0 = data.readStrongsize_t();
    onBufferAvailable(_arg0);
    return NO_ERROR;
    }
case BOGUS_QUEUE_BUFFER: {
    CHECK_INTERFACE(IStreamSource, data, reply);
    bogus_queueBuffer();
    return NO_ERROR;
    }
case BOGUS_ISSUE_COMMAND: {
    CHECK_INTERFACE(IStreamSource, data, reply);
    bogus_issueCommand();
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
