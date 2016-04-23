/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ICameraService.aidl
 */
#ifndef ANDROID_ICAMERA_SERVICE_H
#define ANDROID_ICAMERA_SERVICE_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class ICameraService : public IInterface
{
public:
    DECLARE_META_INTERFACE(CameraService);
    virtual int getNumberOfCameras() = 0;
    virtual const sp<status_t>& getCameraInfo(int cameraId, const sp<CameraInfo>& cameraInfo) = 0;
    virtual const sp<ICamera>& connect(const sp<ICameraClient>& cameraClient, int cameraId) = 0;
};

class BnCameraService : public BnInterface<ICameraService>
{
public:
    enum {
        GET_NUMBER_OF_CAMERAS = IBinder::FIRST_CALL_TRANSACTION,
        GET_CAMERA_INFO,
        CONNECT,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_ICAMERA_SERVICE_H
