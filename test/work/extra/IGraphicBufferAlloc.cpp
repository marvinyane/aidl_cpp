/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IGraphicBufferAlloc.aidl
 */
#define LOG_TAG "GraphicBufferAlloc"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <graphicbufferalloc/IGraphicBufferAlloc.h>

namespace android {

class BpGraphicBufferAlloc : public BpInterface<IGraphicBufferAlloc>
{
    public:
    BpGraphicBufferAlloc(const sp<IBinder>& impl)
        : BpInterface<IGraphicBufferAlloc>(impl) { }

virtual const sp<GraphicBuffer>& createGraphicBuffer(int w, int h, int format, int usage, const sp<void>& error)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IGraphicBufferAlloc::getInterfaceDescriptor());
    _data.writeInt32(w);
    _data.writeInt32(h);
    _data.writeInt32(format);
    _data.writeInt32(usage);
    remote()->transact(BnGraphicBufferAlloc::CREATE_GRAPHIC_BUFFER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(GraphicBufferAlloc, "android.os.IGraphicBufferAlloc");

status_t BnGraphicBufferAlloc::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case CREATE_GRAPHIC_BUFFER: {
    CHECK_INTERFACE(IGraphicBufferAlloc, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int _arg3;
    _arg3 = data.readInt32();
    const sp<void>& _arg4;
    int res = createGraphicBuffer(_arg0, _arg1, _arg2, _arg3, _arg4);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(error);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
