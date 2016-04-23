/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMountService.aidl
 */
#ifndef ANDROID_IMOUNT_SERVICE_H
#define ANDROID_IMOUNT_SERVICE_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IMountService : public IInterface
{
public:
    DECLARE_META_INTERFACE(MountService);
    virtual status_t registerListener(const sp<IMountServiceListener>& listener) = 0;
    virtual status_t unregisterListener(const sp<IMountServiceListener>& listener) = 0;
    virtual bool isUsbMassStorageConnected() = 0;
    virtual status_t setUsbMassStorageEnabled(bool enable) = 0;
    virtual bool isUsbMassStorageEnabled() = 0;
    virtual int mountVolume(const String16& mountPoint) = 0;
    virtual int unmountVolume(const String16& mountPoint, bool force, bool removeEncryption) = 0;
    virtual int formatVolume(const String16& mountPoint) = 0;
    virtual int getStorageUsers(const String16& mountPoint, int users) = 0;
    virtual int getVolumeState(const String16& mountPoint) = 0;
    virtual int createSecureContainer(const String16& id, int sizeMb, const String16& fstype, const String16& key, int ownerUid) = 0;
    virtual int finalizeSecureContainer(const String16& id) = 0;
    virtual int destroySecureContainer(const String16& id) = 0;
    virtual int mountSecureContainer(const String16& id, const String16& key, int ownerUid) = 0;
    virtual int unmountSecureContainer(const String16& id, bool force) = 0;
    virtual bool isSecureContainerMounted(const String16& id) = 0;
    virtual int renameSecureContainer(const String16& oldId, const String16& newId) = 0;
    virtual bool getSecureContainerPath(const String16& id, const String16& path) = 0;
    virtual int getSecureContainerList(const String16& id, const String16& containers) = 0;
    virtual status_t shutdown(const sp<IMountShutdownObserver>& observer) = 0;
    virtual status_t finishMediaUpdate() = 0;
    virtual status_t mountObb(const String16& filename, const String16& key, const sp<IObbActionListener>& token, int nonce) = 0;
    virtual status_t unmountObb(const String16& filename, bool force, const sp<IObbActionListener>& token, int nonce) = 0;
    virtual bool isObbMounted(const String16& filename) = 0;
    virtual bool getMountedObbPath(const String16& filename, const String16& path) = 0;
    virtual status_t isExternalStorageEmulated() = 0;
    virtual int decryptStorage(const String16& password) = 0;
    virtual int encryptStorage(const String16& password) = 0;
};

class BnMountService : public BnInterface<IMountService>
{
public:
    enum {
        REGISTER_LISTENER = IBinder::FIRST_CALL_TRANSACTION,
        UNREGISTER_LISTENER,
        IS_USB_MASS_STORAGE_CONNECTED,
        SET_USB_MASS_STORAGE_ENABLED,
        IS_USB_MASS_STORAGE_ENABLED,
        MOUNT_VOLUME,
        UNMOUNT_VOLUME,
        FORMAT_VOLUME,
        GET_STORAGE_USERS,
        GET_VOLUME_STATE,
        CREATE_SECURE_CONTAINER,
        FINALIZE_SECURE_CONTAINER,
        DESTROY_SECURE_CONTAINER,
        MOUNT_SECURE_CONTAINER,
        UNMOUNT_SECURE_CONTAINER,
        IS_SECURE_CONTAINER_MOUNTED,
        RENAME_SECURE_CONTAINER,
        GET_SECURE_CONTAINER_PATH,
        GET_SECURE_CONTAINER_LIST,
        SHUTDOWN,
        FINISH_MEDIA_UPDATE,
        MOUNT_OBB,
        UNMOUNT_OBB,
        IS_OBB_MOUNTED,
        GET_MOUNTED_OBB_PATH,
        IS_EXTERNAL_STORAGE_EMULATED,
        DECRYPT_STORAGE,
        ENCRYPT_STORAGE,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IMOUNT_SERVICE_H
