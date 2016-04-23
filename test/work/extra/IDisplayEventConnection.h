/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IDisplayEventConnection.aidl
 */
#ifndef ANDROID_IDISPLAY_EVENT_CONNECTION_H
#define ANDROID_IDISPLAY_EVENT_CONNECTION_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IDisplayEventConnection : public IInterface
{
public:
    DECLARE_META_INTERFACE(DisplayEventConnection);
    virtual const sp<BitTube>& getDataChannel() = 0;
    virtual status_t setVsyncRate(int count) = 0;
    virtual status_t requestNextVsync() = 0;
};

class BnDisplayEventConnection : public BnInterface<IDisplayEventConnection>
{
public:
    enum {
        GET_DATA_CHANNEL = IBinder::FIRST_CALL_TRANSACTION,
        SET_VSYNC_RATE,
        REQUEST_NEXT_VSYNC,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IDISPLAY_EVENT_CONNECTION_H
