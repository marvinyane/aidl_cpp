/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ISurfaceTexture.aidl
 */
#define LOG_TAG "SurfaceTexture"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <surfacetexture/ISurfaceTexture.h>

namespace android {

class BpSurfaceTexture : public BpInterface<ISurfaceTexture>
{
    public:
    BpSurfaceTexture(const sp<IBinder>& impl)
        : BpInterface<ISurfaceTexture>(impl) { }

virtual const sp<status_t>& requestBuffer(int slot, const sp<GraphicBuffer>& buf)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceTexture::getInterfaceDescriptor());
    _data.writeInt32(slot);
    remote()->transact(BnSurfaceTexture::REQUEST_BUFFER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setBufferCount(int bufferCount)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceTexture::getInterfaceDescriptor());
    _data.writeInt32(bufferCount);
    remote()->transact(BnSurfaceTexture::SET_BUFFER_COUNT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& dequeueBuffer(int buf, int w, int h, int format, int usage)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceTexture::getInterfaceDescriptor());
    _data.writeInt32(w);
    _data.writeInt32(h);
    _data.writeInt32(format);
    _data.writeInt32(usage);
    remote()->transact(BnSurfaceTexture::DEQUEUE_BUFFER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& queueBuffer(int buf, const sp<QueueBufferInput>& input, const sp<QueueBufferOutput>& output)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceTexture::getInterfaceDescriptor());
    _data.writeInt32(buf);
    input.writeToParcel(&_data);
    remote()->transact(BnSurfaceTexture::QUEUE_BUFFER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& cancelBuffer(int buf)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceTexture::getInterfaceDescriptor());
    _data.writeInt32(buf);
    remote()->transact(BnSurfaceTexture::CANCEL_BUFFER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int query(int what, int value)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceTexture::getInterfaceDescriptor());
    _data.writeInt32(what);
    remote()->transact(BnSurfaceTexture::QUERY, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setSynchronousMode(bool enabled)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceTexture::getInterfaceDescriptor());
    _data.writeInt32((int)enabled);
    remote()->transact(BnSurfaceTexture::SET_SYNCHRONOUS_MODE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& connect(int api, const sp<QueueBufferOutput>& output)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceTexture::getInterfaceDescriptor());
    _data.writeInt32(api);
    output.writeToParcel(&_data);
    remote()->transact(BnSurfaceTexture::CONNECT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& disconnect(int api)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceTexture::getInterfaceDescriptor());
    _data.writeInt32(api);
    remote()->transact(BnSurfaceTexture::DISCONNECT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(SurfaceTexture, "android.os.ISurfaceTexture");

status_t BnSurfaceTexture::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case REQUEST_BUFFER: {
    CHECK_INTERFACE(ISurfaceTexture, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<GraphicBuffer>& _arg1;
    int res = requestBuffer(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(buf);
    return NO_ERROR;
    }
case SET_BUFFER_COUNT: {
    CHECK_INTERFACE(ISurfaceTexture, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = setBufferCount(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case DEQUEUE_BUFFER: {
    CHECK_INTERFACE(ISurfaceTexture, data, reply);
    int _arg0;
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int _arg3;
    _arg3 = data.readInt32();
    int _arg4;
    _arg4 = data.readInt32();
    int res = dequeueBuffer(_arg0, _arg1, _arg2, _arg3, _arg4);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(buf);
    return NO_ERROR;
    }
case QUEUE_BUFFER: {
    CHECK_INTERFACE(ISurfaceTexture, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<QueueBufferInput>& _arg1;
    _arg1 = data.readStrongQueueBufferInput();
    const sp<QueueBufferOutput>& _arg2;
    int res = queueBuffer(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(output);
    return NO_ERROR;
    }
case CANCEL_BUFFER: {
    CHECK_INTERFACE(ISurfaceTexture, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = cancelBuffer(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case QUERY: {
    CHECK_INTERFACE(ISurfaceTexture, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    int res = query(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(value);
    return NO_ERROR;
    }
case SET_SYNCHRONOUS_MODE: {
    CHECK_INTERFACE(ISurfaceTexture, data, reply);
    bool _arg0;
    _arg0 = data.readInt32();
    int res = setSynchronousMode(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CONNECT: {
    CHECK_INTERFACE(ISurfaceTexture, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<QueueBufferOutput>& _arg1;
    _arg1 = data.readStrongQueueBufferOutput();
    int res = connect(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case DISCONNECT: {
    CHECK_INTERFACE(ISurfaceTexture, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = disconnect(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
