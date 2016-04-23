/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IObbActionListener.aidl
 */
#ifndef ANDROID_IOBB_ACTION_LISTENER_H
#define ANDROID_IOBB_ACTION_LISTENER_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IObbActionListener : public IInterface
{
public:
    DECLARE_META_INTERFACE(ObbActionListener);
    virtual status_t onObbResult(const String16& filename, int nonce, int state) = 0;
};

class BnObbActionListener : public BnInterface<IObbActionListener>
{
public:
    enum {
        ON_OBB_RESULT = IBinder::FIRST_CALL_TRANSACTION,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IOBB_ACTION_LISTENER_H
