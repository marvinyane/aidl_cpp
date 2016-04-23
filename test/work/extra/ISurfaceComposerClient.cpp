/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ISurfaceComposerClient.aidl
 */
#define LOG_TAG "SurfaceComposerClient"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <surfacecomposerclient/ISurfaceComposerClient.h>

namespace android {

class BpSurfaceComposerClient : public BpInterface<ISurfaceComposerClient>
{
    public:
    BpSurfaceComposerClient(const sp<IBinder>& impl)
        : BpInterface<ISurfaceComposerClient>(impl) { }

virtual const sp<ISurface>& createSurface(const sp<surface_data_t>& data, const String8& name, int display, int w, int h, int format, int flags)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceComposerClient::getInterfaceDescriptor());
    data.writeToParcel(&_data);
    _data.writeString8(name);
    _data.writeInt32(display);
    _data.writeInt32(w);
    _data.writeInt32(h);
    _data.writeInt32(format);
    _data.writeInt32(flags);
    remote()->transact(BnSurfaceComposerClient::CREATE_SURFACE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& destroySurface(int sid)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceComposerClient::getInterfaceDescriptor());
    _data.writeInt32(sid);
    remote()->transact(BnSurfaceComposerClient::DESTROY_SURFACE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(SurfaceComposerClient, "android.os.ISurfaceComposerClient");

status_t BnSurfaceComposerClient::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case CREATE_SURFACE: {
    CHECK_INTERFACE(ISurfaceComposerClient, data, reply);
    const sp<surface_data_t>& _arg0;
    _arg0 = data.readStrongsurface_data_t();
    String8 _arg1;
    _arg1 = data.readString8();
    int _arg2;
    _arg2 = data.readInt32();
    int _arg3;
    _arg3 = data.readInt32();
    int _arg4;
    _arg4 = data.readInt32();
    int _arg5;
    _arg5 = data.readInt32();
    int _arg6;
    _arg6 = data.readInt32();
    int res = createSurface(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case DESTROY_SURFACE: {
    CHECK_INTERFACE(ISurfaceComposerClient, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = destroySurface(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
