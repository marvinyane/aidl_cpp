/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ISurfaceComposerClient.aidl
 */
#ifndef ANDROID_ISURFACE_COMPOSER_CLIENT_H
#define ANDROID_ISURFACE_COMPOSER_CLIENT_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class ISurfaceComposerClient : public IInterface
{
public:
    DECLARE_META_INTERFACE(SurfaceComposerClient);
    virtual const sp<ISurface>& createSurface(const sp<surface_data_t>& data, const String8& name, int display, int w, int h, int format, int flags) = 0;
    virtual const sp<status_t>& destroySurface(int sid) = 0;
};

class BnSurfaceComposerClient : public BnInterface<ISurfaceComposerClient>
{
public:
    enum {
        CREATE_SURFACE = IBinder::FIRST_CALL_TRANSACTION,
        DESTROY_SURFACE,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ISURFACE_COMPOSER_CLIENT_H
