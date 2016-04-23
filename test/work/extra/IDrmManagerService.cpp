/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IDrmManagerService.aidl
 */
#define LOG_TAG "DrmManagerService"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <drmmanagerservice/IDrmManagerService.h>

namespace android {

class BpDrmManagerService : public BpInterface<IDrmManagerService>
{
    public:
    BpDrmManagerService(const sp<IBinder>& impl)
        : BpInterface<IDrmManagerService>(impl) { }

virtual int addUniqueId(bool isNative)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32((int)isNative);
    remote()->transact(BnDrmManagerService::ADD_UNIQUE_ID, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t removeUniqueId(int uniqueId)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    return remote()->transact(BnDrmManagerService::REMOVE_UNIQUE_ID, _data, &reply);
}

virtual status_t addClient(int uniqueId)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    return remote()->transact(BnDrmManagerService::ADD_CLIENT, _data, &reply);
}

virtual status_t removeClient(int uniqueId)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    return remote()->transact(BnDrmManagerService::REMOVE_CLIENT, _data, &reply);
}

virtual const sp<status_t>& setDrmServiceListener(int uniqueId, const sp<IDrmServiceListener>& infoListener)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    infoListener.writeToParcel(&_data);
    remote()->transact(BnDrmManagerService::SET_DRM_SERVICE_LISTENER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& installDrmEngine(int uniqueId, const String16& drmEngineFile)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    _data.writeString16(drmEngineFile);
    remote()->transact(BnDrmManagerService::INSTALL_DRM_ENGINE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<DrmConstraints>& getConstraints(int uniqueId, const String8& path, int action)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    _data.writeString8(path);
    _data.writeInt32(action);
    remote()->transact(BnDrmManagerService::GET_CONSTRAINTS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<DrmMetadata>& getMetadata(int uniqueId, const String16& path)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    _data.writeString16(path);
    remote()->transact(BnDrmManagerService::GET_METADATA, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual bool canHandle(int uniqueId, const String8& path, const String8& mimeType)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    _data.writeString8(path);
    _data.writeString8(mimeType);
    remote()->transact(BnDrmManagerService::CAN_HANDLE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<DrmInfoStatus>& processDrmInfo(int uniqueId, const sp<DrmInfo>& drmInfo)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    drmInfo.writeToParcel(&_data);
    remote()->transact(BnDrmManagerService::PROCESS_DRM_INFO, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<DrmInfo>& acquireDrmInfo(int uniqueId, const sp<DrmInfoRequest>& drmInforequest)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    drmInforequest.writeToParcel(&_data);
    remote()->transact(BnDrmManagerService::ACQUIRE_DRM_INFO, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& saveRights(int uniqueId, const sp<DrmRights>& drmRights, const String8& rightsPath, const String8& contentPath)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    drmRights.writeToParcel(&_data);
    _data.writeString8(rightsPath);
    _data.writeString8(contentPath);
    remote()->transact(BnDrmManagerService::SAVE_RIGHTS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual String8 getOriginalMimeType(int uniqueId, const String8& path)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    _data.writeString8(path);
    remote()->transact(BnDrmManagerService::GET_ORIGINAL_MIME_TYPE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int getDrmObjectType(int uniqueId, const String8& path, const String8& mimeType)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    _data.writeString8(path);
    _data.writeString8(mimeType);
    remote()->transact(BnDrmManagerService::GET_DRM_OBJECT_TYPE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int checkRightsStatus(int uniqueId, const String8& path, int action)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    _data.writeString8(path);
    _data.writeInt32(action);
    remote()->transact(BnDrmManagerService::CHECK_RIGHTS_STATUS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& consumeRights(int uniqueId, const sp<DecryptHandle>& decryptHandle, int action, bool reserve)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    decryptHandle.writeToParcel(&_data);
    _data.writeInt32(action);
    _data.writeInt32((int)reserve);
    remote()->transact(BnDrmManagerService::CONSUME_RIGHTS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setPlaybackStatus(int uniqueId, const sp<DecryptHandle>& decryptHandle, int playbackStatus, long position)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    decryptHandle.writeToParcel(&_data);
    _data.writeInt32(playbackStatus);
    _data.writeInt64(position);
    remote()->transact(BnDrmManagerService::SET_PLAYBACK_STATUS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual bool validateAction(int uniqueId, const String8& path, int action, const sp<ActionDescription>& description)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    _data.writeString8(path);
    _data.writeInt32(action);
    description.writeToParcel(&_data);
    remote()->transact(BnDrmManagerService::VALIDATE_ACTION, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& removeRights(int uniqueId, const String8& path)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    _data.writeString8(path);
    remote()->transact(BnDrmManagerService::REMOVE_RIGHTS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& removeAllRights(int uniqueId)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    remote()->transact(BnDrmManagerService::REMOVE_ALL_RIGHTS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int openConvertSession(int uniqueId, const String8& mimeType)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    _data.writeString8(mimeType);
    remote()->transact(BnDrmManagerService::OPEN_CONVERT_SESSION, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<DrmConvertedStatus>& convertData(int uniqueId, int convertId, const sp<DrmBuffer>& inputData)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    _data.writeInt32(convertId);
    inputData.writeToParcel(&_data);
    remote()->transact(BnDrmManagerService::CONVERT_DATA, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<DrmConvertedStatus>& closeConvertSession(int uniqueId, int convertId)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    _data.writeInt32(convertId);
    remote()->transact(BnDrmManagerService::CLOSE_CONVERT_SESSION, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getAllSupportInfo(int uniqueId, int length, const sp<DrmSupportInfo>& drmSupportInfoArray)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    remote()->transact(BnDrmManagerService::GET_ALL_SUPPORT_INFO, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<DecryptHandle>& openDecryptSession(int uniqueId, int fd, long offset, long length, const CString& mime)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    _data.writeInt32(fd);
    _data.writeInt64(offset);
    _data.writeInt64(length);
    _data.writeCString(mime);
    remote()->transact(BnDrmManagerService::OPEN_DECRYPT_SESSION, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<DecryptHandle>& openDecryptSessionFromUri(int uniqueId, const CString& uri, const CString& mime)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    _data.writeCString(uri);
    _data.writeCString(mime);
    remote()->transact(BnDrmManagerService::OPEN_DECRYPT_SESSION_FROM_URI, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& closeDecryptSession(int uniqueId, const sp<DecryptHandle>& decryptHandle)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    decryptHandle.writeToParcel(&_data);
    remote()->transact(BnDrmManagerService::CLOSE_DECRYPT_SESSION, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& initializeDecryptUnit(int uniqueId, const sp<DecryptHandle>& decryptHandle, int decryptUnitId, const sp<DrmBuffer>& headerInfo)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    decryptHandle.writeToParcel(&_data);
    _data.writeInt32(decryptUnitId);
    headerInfo.writeToParcel(&_data);
    remote()->transact(BnDrmManagerService::INITIALIZE_DECRYPT_UNIT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& decrypt(int uniqueId, const sp<DecryptHandle>& decryptHandle, int decryptUnitId, const sp<DrmBuffer>& encBuffer, const sp<DrmBuffer>& decBuffer, const sp<DrmBuffer>& IV)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    decryptHandle.writeToParcel(&_data);
    _data.writeInt32(decryptUnitId);
    encBuffer.writeToParcel(&_data);
    remote()->transact(BnDrmManagerService::DECRYPT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& finalizeDecryptUnit(int uniqueId, const sp<DecryptHandle>& decryptHandle, int decryptUnitId)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    decryptHandle.writeToParcel(&_data);
    _data.writeInt32(decryptUnitId);
    remote()->transact(BnDrmManagerService::FINALIZE_DECRYPT_UNIT, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual int pread(int uniqueId, const sp<DecryptHandle>& decryptHandle, const sp<void>& buffer, const sp<ssize_t>& numBytes, long offset)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IDrmManagerService::getInterfaceDescriptor());
    _data.writeInt32(uniqueId);
    decryptHandle.writeToParcel(&_data);
    numBytes.writeToParcel(&_data);
    _data.writeInt64(offset);
    remote()->transact(BnDrmManagerService::PREAD, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(DrmManagerService, "android.os.IDrmManagerService");

status_t BnDrmManagerService::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case ADD_UNIQUE_ID: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    bool _arg0;
    _arg0 = data.readInt32();
    int res = addUniqueId(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case REMOVE_UNIQUE_ID: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    removeUniqueId(_arg0);
    return NO_ERROR;
    }
case ADD_CLIENT: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    addClient(_arg0);
    return NO_ERROR;
    }
case REMOVE_CLIENT: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    removeClient(_arg0);
    return NO_ERROR;
    }
case SET_DRM_SERVICE_LISTENER: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<IDrmServiceListener>& _arg1;
    _arg1 = data.readStrongIDrmServiceListener();
    int res = setDrmServiceListener(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case INSTALL_DRM_ENGINE: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    String16 _arg1;
    _arg1 = data.readString16();
    int res = installDrmEngine(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_CONSTRAINTS: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    String8 _arg1;
    _arg1 = data.readString8();
    int _arg2;
    _arg2 = data.readInt32();
    int res = getConstraints(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_METADATA: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    String16 _arg1;
    _arg1 = data.readString16();
    int res = getMetadata(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CAN_HANDLE: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    String8 _arg1;
    _arg1 = data.readString8();
    String8 _arg2;
    _arg2 = data.readString8();
    int res = canHandle(_arg0, _arg1, _arg2)? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case PROCESS_DRM_INFO: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<DrmInfo>& _arg1;
    _arg1 = data.readStrongDrmInfo();
    int res = processDrmInfo(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case ACQUIRE_DRM_INFO: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<DrmInfoRequest>& _arg1;
    _arg1 = data.readStrongDrmInfoRequest();
    int res = acquireDrmInfo(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SAVE_RIGHTS: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<DrmRights>& _arg1;
    _arg1 = data.readStrongDrmRights();
    String8 _arg2;
    _arg2 = data.readString8();
    String8 _arg3;
    _arg3 = data.readString8();
    int res = saveRights(_arg0, _arg1, _arg2, _arg3);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_ORIGINAL_MIME_TYPE: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    String8 _arg1;
    _arg1 = data.readString8();
    int res = getOriginalMimeType(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_DRM_OBJECT_TYPE: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    String8 _arg1;
    _arg1 = data.readString8();
    String8 _arg2;
    _arg2 = data.readString8();
    int res = getDrmObjectType(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CHECK_RIGHTS_STATUS: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    String8 _arg1;
    _arg1 = data.readString8();
    int _arg2;
    _arg2 = data.readInt32();
    int res = checkRightsStatus(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CONSUME_RIGHTS: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<DecryptHandle>& _arg1;
    _arg1 = data.readStrongDecryptHandle();
    int _arg2;
    _arg2 = data.readInt32();
    bool _arg3;
    _arg3 = data.readInt32();
    int res = consumeRights(_arg0, _arg1, _arg2, _arg3);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_PLAYBACK_STATUS: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<DecryptHandle>& _arg1;
    _arg1 = data.readStrongDecryptHandle();
    int _arg2;
    _arg2 = data.readInt32();
    long _arg3;
    _arg3 = data.readInt64();
    int res = setPlaybackStatus(_arg0, _arg1, _arg2, _arg3);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case VALIDATE_ACTION: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    String8 _arg1;
    _arg1 = data.readString8();
    int _arg2;
    _arg2 = data.readInt32();
    const sp<ActionDescription>& _arg3;
    _arg3 = data.readStrongActionDescription();
    int res = validateAction(_arg0, _arg1, _arg2, _arg3)? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case REMOVE_RIGHTS: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    String8 _arg1;
    _arg1 = data.readString8();
    int res = removeRights(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case REMOVE_ALL_RIGHTS: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = removeAllRights(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case OPEN_CONVERT_SESSION: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    String8 _arg1;
    _arg1 = data.readString8();
    int res = openConvertSession(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CONVERT_DATA: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    const sp<DrmBuffer>& _arg2;
    _arg2 = data.readStrongDrmBuffer();
    int res = convertData(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CLOSE_CONVERT_SESSION: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int res = closeConvertSession(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_ALL_SUPPORT_INFO: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    const sp<DrmSupportInfo>& _arg2;
    int res = getAllSupportInfo(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(length);
data.%s.writeToParcel(&_data);
(drmSupportInfoArray);
    return NO_ERROR;
    }
case OPEN_DECRYPT_SESSION: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    long _arg2;
    _arg2 = data.readInt64();
    long _arg3;
    _arg3 = data.readInt64();
    CString _arg4;
    _arg4 = data.readCString();
    int res = openDecryptSession(_arg0, _arg1, _arg2, _arg3, _arg4);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case OPEN_DECRYPT_SESSION_FROM_URI: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    CString _arg1;
    _arg1 = data.readCString();
    CString _arg2;
    _arg2 = data.readCString();
    int res = openDecryptSessionFromUri(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CLOSE_DECRYPT_SESSION: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<DecryptHandle>& _arg1;
    _arg1 = data.readStrongDecryptHandle();
    int res = closeDecryptSession(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case INITIALIZE_DECRYPT_UNIT: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<DecryptHandle>& _arg1;
    _arg1 = data.readStrongDecryptHandle();
    int _arg2;
    _arg2 = data.readInt32();
    const sp<DrmBuffer>& _arg3;
    _arg3 = data.readStrongDrmBuffer();
    int res = initializeDecryptUnit(_arg0, _arg1, _arg2, _arg3);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case DECRYPT: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<DecryptHandle>& _arg1;
    _arg1 = data.readStrongDecryptHandle();
    int _arg2;
    _arg2 = data.readInt32();
    const sp<DrmBuffer>& _arg3;
    _arg3 = data.readStrongDrmBuffer();
    const sp<DrmBuffer>& _arg4;
    const sp<DrmBuffer>& _arg5;
    int res = decrypt(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(decBuffer);
data.%s.writeToParcel(&_data);
(IV);
    return NO_ERROR;
    }
case FINALIZE_DECRYPT_UNIT: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<DecryptHandle>& _arg1;
    _arg1 = data.readStrongDecryptHandle();
    int _arg2;
    _arg2 = data.readInt32();
    int res = finalizeDecryptUnit(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case PREAD: {
    CHECK_INTERFACE(IDrmManagerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<DecryptHandle>& _arg1;
    _arg1 = data.readStrongDecryptHandle();
    const sp<void>& _arg2;
    const sp<ssize_t>& _arg3;
    _arg3 = data.readStrongssize_t();
    long _arg4;
    _arg4 = data.readInt64();
    int res = pread(_arg0, _arg1, _arg2, _arg3, _arg4);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(buffer);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
