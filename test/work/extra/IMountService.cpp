/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMountService.aidl
 */
#define LOG_TAG "MountService"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <mountservice/IMountService.h>

namespace android {

class BpMountService : public BpInterface<IMountService>
{
    public:
    BpMountService(const sp<IBinder>& impl)
        : BpInterface<IMountService>(impl) { }

virtual status_t registerListener(const sp<IMountServiceListener>& listener)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    listener.writeToParcel(&_data);
    return remote()->transact(BnMountService::REGISTER_LISTENER, _data, &reply);
}

virtual status_t unregisterListener(const sp<IMountServiceListener>& listener)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    listener.writeToParcel(&_data);
    return remote()->transact(BnMountService::UNREGISTER_LISTENER, _data, &reply);
}

virtual bool isUsbMassStorageConnected()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    remote()->transact(BnMountService::IS_USB_MASS_STORAGE_CONNECTED, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t setUsbMassStorageEnabled(bool enable)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeInt32((int)enable);
    return remote()->transact(BnMountService::SET_USB_MASS_STORAGE_ENABLED, _data, &reply);
}

virtual bool isUsbMassStorageEnabled()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    remote()->transact(BnMountService::IS_USB_MASS_STORAGE_ENABLED, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int mountVolume(const String16& mountPoint)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(mountPoint);
    remote()->transact(BnMountService::MOUNT_VOLUME, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int unmountVolume(const String16& mountPoint, bool force, bool removeEncryption)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(mountPoint);
    _data.writeInt32((int)force);
    _data.writeInt32((int)removeEncryption);
    remote()->transact(BnMountService::UNMOUNT_VOLUME, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int formatVolume(const String16& mountPoint)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(mountPoint);
    remote()->transact(BnMountService::FORMAT_VOLUME, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int getStorageUsers(const String16& mountPoint, int users)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(mountPoint);
    remote()->transact(BnMountService::GET_STORAGE_USERS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int getVolumeState(const String16& mountPoint)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(mountPoint);
    remote()->transact(BnMountService::GET_VOLUME_STATE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int createSecureContainer(const String16& id, int sizeMb, const String16& fstype, const String16& key, int ownerUid)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(id);
    _data.writeInt32(sizeMb);
    _data.writeString16(fstype);
    _data.writeString16(key);
    _data.writeInt32(ownerUid);
    remote()->transact(BnMountService::CREATE_SECURE_CONTAINER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int finalizeSecureContainer(const String16& id)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(id);
    remote()->transact(BnMountService::FINALIZE_SECURE_CONTAINER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int destroySecureContainer(const String16& id)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(id);
    remote()->transact(BnMountService::DESTROY_SECURE_CONTAINER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int mountSecureContainer(const String16& id, const String16& key, int ownerUid)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(id);
    _data.writeString16(key);
    _data.writeInt32(ownerUid);
    remote()->transact(BnMountService::MOUNT_SECURE_CONTAINER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int unmountSecureContainer(const String16& id, bool force)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(id);
    _data.writeInt32((int)force);
    remote()->transact(BnMountService::UNMOUNT_SECURE_CONTAINER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual bool isSecureContainerMounted(const String16& id)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(id);
    remote()->transact(BnMountService::IS_SECURE_CONTAINER_MOUNTED, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int renameSecureContainer(const String16& oldId, const String16& newId)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(oldId);
    _data.writeString16(newId);
    remote()->transact(BnMountService::RENAME_SECURE_CONTAINER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual bool getSecureContainerPath(const String16& id, const String16& path)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(id);
    _data.writeString16(path);
    remote()->transact(BnMountService::GET_SECURE_CONTAINER_PATH, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int getSecureContainerList(const String16& id, const String16& containers)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(id);
    remote()->transact(BnMountService::GET_SECURE_CONTAINER_LIST, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t shutdown(const sp<IMountShutdownObserver>& observer)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    observer.writeToParcel(&_data);
    return remote()->transact(BnMountService::SHUTDOWN, _data, &reply);
}

virtual status_t finishMediaUpdate()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    return remote()->transact(BnMountService::FINISH_MEDIA_UPDATE, _data, &reply);
}

virtual status_t mountObb(const String16& filename, const String16& key, const sp<IObbActionListener>& token, int nonce)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(filename);
    _data.writeString16(key);
    token.writeToParcel(&_data);
    _data.writeInt32(nonce);
    return remote()->transact(BnMountService::MOUNT_OBB, _data, &reply);
}

virtual status_t unmountObb(const String16& filename, bool force, const sp<IObbActionListener>& token, int nonce)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(filename);
    _data.writeInt32((int)force);
    token.writeToParcel(&_data);
    _data.writeInt32(nonce);
    return remote()->transact(BnMountService::UNMOUNT_OBB, _data, &reply);
}

virtual bool isObbMounted(const String16& filename)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(filename);
    remote()->transact(BnMountService::IS_OBB_MOUNTED, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual bool getMountedObbPath(const String16& filename, const String16& path)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(filename);
    remote()->transact(BnMountService::GET_MOUNTED_OBB_PATH, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t isExternalStorageEmulated()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    return remote()->transact(BnMountService::IS_EXTERNAL_STORAGE_EMULATED, _data, &reply);
}
/* not defined */
virtual int decryptStorage(const String16& password)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(password);
    remote()->transact(BnMountService::DECRYPT_STORAGE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int encryptStorage(const String16& password)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMountService::getInterfaceDescriptor());
    _data.writeString16(password);
    remote()->transact(BnMountService::ENCRYPT_STORAGE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(MountService, "android.os.IMountService");

status_t BnMountService::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case REGISTER_LISTENER: {
    CHECK_INTERFACE(IMountService, data, reply);
    const sp<IMountServiceListener>& _arg0;
    _arg0 = data.readStrongIMountServiceListener();
    registerListener(_arg0);
    return NO_ERROR;
    }
case UNREGISTER_LISTENER: {
    CHECK_INTERFACE(IMountService, data, reply);
    const sp<IMountServiceListener>& _arg0;
    _arg0 = data.readStrongIMountServiceListener();
    unregisterListener(_arg0);
    return NO_ERROR;
    }
case IS_USB_MASS_STORAGE_CONNECTED: {
    CHECK_INTERFACE(IMountService, data, reply);
    int res = isUsbMassStorageConnected()? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_USB_MASS_STORAGE_ENABLED: {
    CHECK_INTERFACE(IMountService, data, reply);
    bool _arg0;
    _arg0 = data.readInt32();
    setUsbMassStorageEnabled(_arg0);
    return NO_ERROR;
    }
case IS_USB_MASS_STORAGE_ENABLED: {
    CHECK_INTERFACE(IMountService, data, reply);
    int res = isUsbMassStorageEnabled()? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case MOUNT_VOLUME: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    int res = mountVolume(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case UNMOUNT_VOLUME: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    bool _arg1;
    _arg1 = data.readInt32();
    bool _arg2;
    _arg2 = data.readInt32();
    int res = unmountVolume(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case FORMAT_VOLUME: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    int res = formatVolume(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_STORAGE_USERS: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    int _arg1;
    int res = getStorageUsers(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(users);
    return NO_ERROR;
    }
case GET_VOLUME_STATE: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    int res = getVolumeState(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CREATE_SECURE_CONTAINER: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    int _arg1;
    _arg1 = data.readInt32();
    String16 _arg2;
    _arg2 = data.readString16();
    String16 _arg3;
    _arg3 = data.readString16();
    int _arg4;
    _arg4 = data.readInt32();
    int res = createSecureContainer(_arg0, _arg1, _arg2, _arg3, _arg4);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case FINALIZE_SECURE_CONTAINER: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    int res = finalizeSecureContainer(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case DESTROY_SECURE_CONTAINER: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    int res = destroySecureContainer(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case MOUNT_SECURE_CONTAINER: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    String16 _arg1;
    _arg1 = data.readString16();
    int _arg2;
    _arg2 = data.readInt32();
    int res = mountSecureContainer(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case UNMOUNT_SECURE_CONTAINER: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    bool _arg1;
    _arg1 = data.readInt32();
    int res = unmountSecureContainer(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case IS_SECURE_CONTAINER_MOUNTED: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    int res = isSecureContainerMounted(_arg0)? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case RENAME_SECURE_CONTAINER: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    String16 _arg1;
    _arg1 = data.readString16();
    int res = renameSecureContainer(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_SECURE_CONTAINER_PATH: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    String16 _arg1;
    _arg1 = data.readString16();
    int res = getSecureContainerPath(_arg0, _arg1)? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_SECURE_CONTAINER_LIST: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    String16 _arg1;
    int res = getSecureContainerList(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeString16(%s);
(containers);
    return NO_ERROR;
    }
case SHUTDOWN: {
    CHECK_INTERFACE(IMountService, data, reply);
    const sp<IMountShutdownObserver>& _arg0;
    _arg0 = data.readStrongIMountShutdownObserver();
    shutdown(_arg0);
    return NO_ERROR;
    }
case FINISH_MEDIA_UPDATE: {
    CHECK_INTERFACE(IMountService, data, reply);
    finishMediaUpdate();
    return NO_ERROR;
    }
case MOUNT_OBB: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    String16 _arg1;
    _arg1 = data.readString16();
    const sp<IObbActionListener>& _arg2;
    _arg2 = data.readStrongIObbActionListener();
    int _arg3;
    _arg3 = data.readInt32();
    mountObb(_arg0, _arg1, _arg2, _arg3);
    return NO_ERROR;
    }
case UNMOUNT_OBB: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    bool _arg1;
    _arg1 = data.readInt32();
    const sp<IObbActionListener>& _arg2;
    _arg2 = data.readStrongIObbActionListener();
    int _arg3;
    _arg3 = data.readInt32();
    unmountObb(_arg0, _arg1, _arg2, _arg3);
    return NO_ERROR;
    }
case IS_OBB_MOUNTED: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    int res = isObbMounted(_arg0)? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_MOUNTED_OBB_PATH: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    String16 _arg1;
    int res = getMountedObbPath(_arg0, _arg1)? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeString16(%s);
(path);
    return NO_ERROR;
    }
case IS_EXTERNAL_STORAGE_EMULATED: {
    CHECK_INTERFACE(IMountService, data, reply);
    isExternalStorageEmulated();
    return NO_ERROR;
    }
case DECRYPT_STORAGE: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    int res = decryptStorage(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case ENCRYPT_STORAGE: {
    CHECK_INTERFACE(IMountService, data, reply);
    String16 _arg0;
    _arg0 = data.readString16();
    int res = encryptStorage(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
