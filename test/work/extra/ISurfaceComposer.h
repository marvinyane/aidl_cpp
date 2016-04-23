/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ISurfaceComposer.aidl
 */
#ifndef ANDROID_ISURFACE_COMPOSER_H
#define ANDROID_ISURFACE_COMPOSER_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class ISurfaceComposer : public IInterface
{
public:
    DECLARE_META_INTERFACE(SurfaceComposer);
    virtual status_t bootFinished() = 0;
    virtual const sp<ISurfaceComposerClient>& createConnection() = 0;
    virtual const sp<IGraphicBufferAlloc>& createGraphicBufferAlloc() = 0;
    virtual const sp<IMemoryHeap>& getCblk() = 0;
    virtual status_t setTransactionState(const sp<ComposerState>& state, int orientation, int flags) = 0;
    virtual status_t setOrientation() = 0;
    virtual const sp<status_t>& captureScreen(int dpy, const sp<IMemoryHeap>& heap, int width, int height, const sp<PixelFormat>& format, int reqWidth, int reqHeight, int minLayerZ, int maxLayerZ) = 0;
    virtual const sp<status_t>& turnElectronBeamOff(int mode) = 0;
    virtual const sp<status_t>& turnElectronBeamOn(int mode) = 0;
    virtual bool authenticateSurfaceTexture(const sp<ISurfaceTexture>& surface) = 0;
    virtual const sp<IDisplayEventConnection>& createDisplayEventConnection() = 0;
};

class BnSurfaceComposer : public BnInterface<ISurfaceComposer>
{
public:
    enum {
        BOOT_FINISHED = IBinder::FIRST_CALL_TRANSACTION,
        CREATE_CONNECTION,
        CREATE_GRAPHIC_BUFFER_ALLOC,
        GET_CBLK,
        SET_TRANSACTION_STATE,
        SET_ORIENTATION,
        CAPTURE_SCREEN,
        TURN_ELECTRON_BEAM_OFF,
        TURN_ELECTRON_BEAM_ON,
        AUTHENTICATE_SURFACE_TEXTURE,
        CREATE_DISPLAY_EVENT_CONNECTION,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ISURFACE_COMPOSER_H
