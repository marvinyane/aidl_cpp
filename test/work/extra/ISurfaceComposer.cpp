/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ISurfaceComposer.aidl
 */
#define LOG_TAG "SurfaceComposer"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <surfacecomposer/ISurfaceComposer.h>

namespace android {

class BpSurfaceComposer : public BpInterface<ISurfaceComposer>
{
    public:
    BpSurfaceComposer(const sp<IBinder>& impl)
        : BpInterface<ISurfaceComposer>(impl) { }

virtual status_t bootFinished()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceComposer::getInterfaceDescriptor());
    return remote()->transact(BnSurfaceComposer::BOOT_FINISHED, _data, &reply);
}

virtual const sp<ISurfaceComposerClient>& createConnection()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceComposer::getInterfaceDescriptor());
    remote()->transact(BnSurfaceComposer::CREATE_CONNECTION, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<IGraphicBufferAlloc>& createGraphicBufferAlloc()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceComposer::getInterfaceDescriptor());
    remote()->transact(BnSurfaceComposer::CREATE_GRAPHIC_BUFFER_ALLOC, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<IMemoryHeap>& getCblk()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceComposer::getInterfaceDescriptor());
    remote()->transact(BnSurfaceComposer::GET_CBLK, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t setTransactionState(const sp<ComposerState>& state, int orientation, int flags)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceComposer::getInterfaceDescriptor());
    state.writeToParcel(&_data);
    _data.writeInt32(orientation);
    _data.writeInt32(flags);
    return remote()->transact(BnSurfaceComposer::SET_TRANSACTION_STATE, _data, &reply);
}

virtual status_t setOrientation()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceComposer::getInterfaceDescriptor());
    return remote()->transact(BnSurfaceComposer::SET_ORIENTATION, _data, &reply);
}
/* not defined */
virtual const sp<status_t>& captureScreen(int dpy, const sp<IMemoryHeap>& heap, int width, int height, const sp<PixelFormat>& format, int reqWidth, int reqHeight, int minLayerZ, int maxLayerZ)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceComposer::getInterfaceDescriptor());
    _data.writeInt32(dpy);
    heap.writeToParcel(&_data);
    _data.writeInt32(width);
    _data.writeInt32(height);
    format.writeToParcel(&_data);
    _data.writeInt32(reqWidth);
    _data.writeInt32(reqHeight);
    _data.writeInt32(minLayerZ);
    _data.writeInt32(maxLayerZ);
    remote()->transact(BnSurfaceComposer::CAPTURE_SCREEN, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& turnElectronBeamOff(int mode)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceComposer::getInterfaceDescriptor());
    _data.writeInt32(mode);
    remote()->transact(BnSurfaceComposer::TURN_ELECTRON_BEAM_OFF, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& turnElectronBeamOn(int mode)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceComposer::getInterfaceDescriptor());
    _data.writeInt32(mode);
    remote()->transact(BnSurfaceComposer::TURN_ELECTRON_BEAM_ON, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual bool authenticateSurfaceTexture(const sp<ISurfaceTexture>& surface)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceComposer::getInterfaceDescriptor());
    surface.writeToParcel(&_data);
    remote()->transact(BnSurfaceComposer::AUTHENTICATE_SURFACE_TEXTURE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<IDisplayEventConnection>& createDisplayEventConnection()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ISurfaceComposer::getInterfaceDescriptor());
    remote()->transact(BnSurfaceComposer::CREATE_DISPLAY_EVENT_CONNECTION, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(SurfaceComposer, "android.os.ISurfaceComposer");

status_t BnSurfaceComposer::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case BOOT_FINISHED: {
    CHECK_INTERFACE(ISurfaceComposer, data, reply);
    bootFinished();
    return NO_ERROR;
    }
case CREATE_CONNECTION: {
    CHECK_INTERFACE(ISurfaceComposer, data, reply);
    int res = createConnection();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CREATE_GRAPHIC_BUFFER_ALLOC: {
    CHECK_INTERFACE(ISurfaceComposer, data, reply);
    int res = createGraphicBufferAlloc();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_CBLK: {
    CHECK_INTERFACE(ISurfaceComposer, data, reply);
    int res = getCblk();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_TRANSACTION_STATE: {
    CHECK_INTERFACE(ISurfaceComposer, data, reply);
    const sp<ComposerState>& _arg0;
    _arg0 = data.readStrongComposerState();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    setTransactionState(_arg0, _arg1, _arg2);
    return NO_ERROR;
    }
case SET_ORIENTATION: {
    CHECK_INTERFACE(ISurfaceComposer, data, reply);
    setOrientation();
    return NO_ERROR;
    }
case CAPTURE_SCREEN: {
    CHECK_INTERFACE(ISurfaceComposer, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<IMemoryHeap>& _arg1;
    _arg1 = data.readStrongIMemoryHeap();
    int _arg2;
    _arg2 = data.readInt32();
    int _arg3;
    _arg3 = data.readInt32();
    const sp<PixelFormat>& _arg4;
    _arg4 = data.readStrongPixelFormat();
    int _arg5;
    _arg5 = data.readInt32();
    int _arg6;
    _arg6 = data.readInt32();
    int _arg7;
    _arg7 = data.readInt32();
    int _arg8;
    _arg8 = data.readInt32();
    int res = captureScreen(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case TURN_ELECTRON_BEAM_OFF: {
    CHECK_INTERFACE(ISurfaceComposer, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = turnElectronBeamOff(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case TURN_ELECTRON_BEAM_ON: {
    CHECK_INTERFACE(ISurfaceComposer, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = turnElectronBeamOn(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case AUTHENTICATE_SURFACE_TEXTURE: {
    CHECK_INTERFACE(ISurfaceComposer, data, reply);
    const sp<ISurfaceTexture>& _arg0;
    _arg0 = data.readStrongISurfaceTexture();
    int res = authenticateSurfaceTexture(_arg0)? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CREATE_DISPLAY_EVENT_CONNECTION: {
    CHECK_INTERFACE(ISurfaceComposer, data, reply);
    int res = createDisplayEventConnection();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
