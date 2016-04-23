/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IGraphicBufferAlloc.aidl
 */
#ifndef ANDROID_IGRAPHIC_BUFFER_ALLOC_H
#define ANDROID_IGRAPHIC_BUFFER_ALLOC_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IGraphicBufferAlloc : public IInterface
{
public:
    DECLARE_META_INTERFACE(GraphicBufferAlloc);
    virtual const sp<GraphicBuffer>& createGraphicBuffer(int w, int h, int format, int usage, const sp<void>& error) = 0;
};

class BnGraphicBufferAlloc : public BnInterface<IGraphicBufferAlloc>
{
public:
    enum {
        CREATE_GRAPHIC_BUFFER = IBinder::FIRST_CALL_TRANSACTION,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IGRAPHIC_BUFFER_ALLOC_H
