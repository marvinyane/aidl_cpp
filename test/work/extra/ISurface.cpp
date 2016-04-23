/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ISurface.aidl
 */
#define LOG_TAG "Surface"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <surface/ISurface.h>

namespace android {

class BpSurface : public BpInterface<ISurface>
{
    public:
    BpSurface(const sp<IBinder>& impl)
        : BpInterface<ISurface>(impl) { }

virtual const sp<ISurfaceTexture>& getSurfaceTexture()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurface::getInterfaceDescriptor());
    remote()->transact(BnSurface::GET_SURFACE_TEXTURE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(Surface, "android.os.ISurface");

status_t BnSurface::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case GET_SURFACE_TEXTURE: {
    CHECK_INTERFACE(ISurface, data, reply);
    int res = getSurfaceTexture();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
