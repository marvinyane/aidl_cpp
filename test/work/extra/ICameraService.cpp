/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/ICameraService.aidl
 */
#define LOG_TAG "CameraService"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <cameraservice/ICameraService.h>

namespace android {

class BpCameraService : public BpInterface<ICameraService>
{
    public:
    BpCameraService(const sp<IBinder>& impl)
        : BpInterface<ICameraService>(impl) { }

virtual int getNumberOfCameras()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICameraService::getInterfaceDescriptor());
    remote()->transact(BnCameraService::GET_NUMBER_OF_CAMERAS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getCameraInfo(int cameraId, const sp<CameraInfo>& cameraInfo)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICameraService::getInterfaceDescriptor());
    _data.writeInt32(cameraId);
    remote()->transact(BnCameraService::GET_CAMERA_INFO, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<ICamera>& connect(const sp<ICameraClient>& cameraClient, int cameraId)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(ICameraService::getInterfaceDescriptor());
    cameraClient.writeToParcel(&_data);
    _data.writeInt32(cameraId);
    remote()->transact(BnCameraService::CONNECT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(CameraService, "android.os.ICameraService");

status_t BnCameraService::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case GET_NUMBER_OF_CAMERAS: {
    CHECK_INTERFACE(ICameraService, data, reply);
    int res = getNumberOfCameras();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_CAMERA_INFO: {
    CHECK_INTERFACE(ICameraService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<CameraInfo>& _arg1;
    int res = getCameraInfo(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(cameraInfo);
    return NO_ERROR;
    }
case CONNECT: {
    CHECK_INTERFACE(ICameraService, data, reply);
    const sp<ICameraClient>& _arg0;
    _arg0 = data.readStrongICameraClient();
    int _arg1;
    _arg1 = data.readInt32();
    int res = connect(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
