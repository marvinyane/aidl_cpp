/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IDrmManagerService.aidl
 */
#ifndef ANDROID_IDRM_MANAGER_SERVICE_H
#define ANDROID_IDRM_MANAGER_SERVICE_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IDrmManagerService : public IInterface
{
public:
    DECLARE_META_INTERFACE(DrmManagerService);
    virtual int addUniqueId(bool isNative) = 0;
    virtual status_t removeUniqueId(int uniqueId) = 0;
    virtual status_t addClient(int uniqueId) = 0;
    virtual status_t removeClient(int uniqueId) = 0;
    virtual const sp<status_t>& setDrmServiceListener(int uniqueId, const sp<IDrmServiceListener>& infoListener) = 0;
    virtual const sp<status_t>& installDrmEngine(int uniqueId, const String16& drmEngineFile) = 0;
    virtual const sp<DrmConstraints>& getConstraints(int uniqueId, const String8& path, int action) = 0;
    virtual const sp<DrmMetadata>& getMetadata(int uniqueId, const String16& path) = 0;
    virtual bool canHandle(int uniqueId, const String8& path, const String8& mimeType) = 0;
    virtual const sp<DrmInfoStatus>& processDrmInfo(int uniqueId, const sp<DrmInfo>& drmInfo) = 0;
    virtual const sp<DrmInfo>& acquireDrmInfo(int uniqueId, const sp<DrmInfoRequest>& drmInforequest) = 0;
    virtual const sp<status_t>& saveRights(int uniqueId, const sp<DrmRights>& drmRights, const String8& rightsPath, const String8& contentPath) = 0;
    virtual String8 getOriginalMimeType(int uniqueId, const String8& path) = 0;
    virtual int getDrmObjectType(int uniqueId, const String8& path, const String8& mimeType) = 0;
    virtual int checkRightsStatus(int uniqueId, const String8& path, int action) = 0;
    virtual const sp<status_t>& consumeRights(int uniqueId, const sp<DecryptHandle>& decryptHandle, int action, bool reserve) = 0;
    virtual const sp<status_t>& setPlaybackStatus(int uniqueId, const sp<DecryptHandle>& decryptHandle, int playbackStatus, long position) = 0;
    virtual bool validateAction(int uniqueId, const String8& path, int action, const sp<ActionDescription>& description) = 0;
    virtual const sp<status_t>& removeRights(int uniqueId, const String8& path) = 0;
    virtual const sp<status_t>& removeAllRights(int uniqueId) = 0;
    virtual int openConvertSession(int uniqueId, const String8& mimeType) = 0;
    virtual const sp<DrmConvertedStatus>& convertData(int uniqueId, int convertId, const sp<DrmBuffer>& inputData) = 0;
    virtual const sp<DrmConvertedStatus>& closeConvertSession(int uniqueId, int convertId) = 0;
    virtual const sp<status_t>& getAllSupportInfo(int uniqueId, int length, const sp<DrmSupportInfo>& drmSupportInfoArray) = 0;
    virtual const sp<DecryptHandle>& openDecryptSession(int uniqueId, int fd, long offset, long length, const CString& mime) = 0;
    virtual const sp<DecryptHandle>& openDecryptSessionFromUri(int uniqueId, const CString& uri, const CString& mime) = 0;
    virtual const sp<status_t>& closeDecryptSession(int uniqueId, const sp<DecryptHandle>& decryptHandle) = 0;
    virtual const sp<status_t>& initializeDecryptUnit(int uniqueId, const sp<DecryptHandle>& decryptHandle, int decryptUnitId, const sp<DrmBuffer>& headerInfo) = 0;
    virtual const sp<status_t>& decrypt(int uniqueId, const sp<DecryptHandle>& decryptHandle, int decryptUnitId, const sp<DrmBuffer>& encBuffer, const sp<DrmBuffer>& decBuffer, const sp<DrmBuffer>& IV) = 0;
    virtual const sp<status_t>& finalizeDecryptUnit(int uniqueId, const sp<DecryptHandle>& decryptHandle, int decryptUnitId) = 0;
    virtual int pread(int uniqueId, const sp<DecryptHandle>& decryptHandle, const sp<void>& buffer, const sp<ssize_t>& numBytes, long offset) = 0;
};

class BnDrmManagerService : public BnInterface<IDrmManagerService>
{
public:
    enum {
        ADD_UNIQUE_ID = IBinder::FIRST_CALL_TRANSACTION,
        REMOVE_UNIQUE_ID,
        ADD_CLIENT,
        REMOVE_CLIENT,
        SET_DRM_SERVICE_LISTENER,
        INSTALL_DRM_ENGINE,
        GET_CONSTRAINTS,
        GET_METADATA,
        CAN_HANDLE,
        PROCESS_DRM_INFO,
        ACQUIRE_DRM_INFO,
        SAVE_RIGHTS,
        GET_ORIGINAL_MIME_TYPE,
        GET_DRM_OBJECT_TYPE,
        CHECK_RIGHTS_STATUS,
        CONSUME_RIGHTS,
        SET_PLAYBACK_STATUS,
        VALIDATE_ACTION,
        REMOVE_RIGHTS,
        REMOVE_ALL_RIGHTS,
        OPEN_CONVERT_SESSION,
        CONVERT_DATA,
        CLOSE_CONVERT_SESSION,
        GET_ALL_SUPPORT_INFO,
        OPEN_DECRYPT_SESSION,
        OPEN_DECRYPT_SESSION_FROM_URI,
        CLOSE_DECRYPT_SESSION,
        INITIALIZE_DECRYPT_UNIT,
        DECRYPT,
        FINALIZE_DECRYPT_UNIT,
        PREAD,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IDRM_MANAGER_SERVICE_H
