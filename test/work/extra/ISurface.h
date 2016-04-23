/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ISurface.aidl
 */
#ifndef ANDROID_ISURFACE_H
#define ANDROID_ISURFACE_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class ISurface : public IInterface
{
public:
    DECLARE_META_INTERFACE(Surface);
    virtual const sp<ISurfaceTexture>& getSurfaceTexture() = 0;
};

class BnSurface : public BnInterface<ISurface>
{
public:
    enum {
        GET_SURFACE_TEXTURE = IBinder::FIRST_CALL_TRANSACTION,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ISURFACE_H
