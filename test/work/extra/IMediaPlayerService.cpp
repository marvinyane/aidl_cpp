/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMediaPlayerService.aidl
 */
#define LOG_TAG "MediaPlayerService"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <mediaplayerservice/IMediaPlayerService.h>

namespace android {

class BpMediaPlayerService : public BpInterface<IMediaPlayerService>
{
    public:
    BpMediaPlayerService(const sp<IBinder>& impl)
        : BpInterface<IMediaPlayerService>(impl) { }

virtual const sp<IMediaPlayer>& create(int pid, const sp<IMediaPlayerClient>& client, int audioSessionId)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayerService::getInterfaceDescriptor());
    _data.writeInt32(pid);
    client.writeToParcel(&_data);
    _data.writeInt32(audioSessionId);
    remote()->transact(BnMediaPlayerService::CREATE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<IMemory>& decodeUrl(const CString& url, int pSampleRate, int pNumChannels, int pFormat)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayerService::getInterfaceDescriptor());
    _data.writeCString(url);
    remote()->transact(BnMediaPlayerService::DECODE_URL, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<IMemory>& decodeFd(int fd, long offset, long length, int pSampleRate, int pNumChannels, int pFormat)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayerService::getInterfaceDescriptor());
    _data.writeInt32(fd);
    _data.writeInt64(offset);
    _data.writeInt64(length);
    remote()->transact(BnMediaPlayerService::DECODE_FD, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<IMediaRecorder>& createMediaRecorder(int pid)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayerService::getInterfaceDescriptor());
    _data.writeInt32(pid);
    remote()->transact(BnMediaPlayerService::CREATE_MEDIA_RECORDER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<IMediaMetadataRetriever>& createMetadataRetriever(int pid)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayerService::getInterfaceDescriptor());
    _data.writeInt32(pid);
    remote()->transact(BnMediaPlayerService::CREATE_METADATA_RETRIEVER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<IOMX>& getOMX()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayerService::getInterfaceDescriptor());
    remote()->transact(BnMediaPlayerService::GET_OMX, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<ICrypto>& makeCrypto()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayerService::getInterfaceDescriptor());
    remote()->transact(BnMediaPlayerService::MAKE_CRYPTO, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t addBatteryData(int params)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayerService::getInterfaceDescriptor());
    _data.writeInt32(params);
    return remote()->transact(BnMediaPlayerService::ADD_BATTERY_DATA, _data, &reply);
}

virtual status_t pullBatteryData(const sp<zParcel>& reply)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaPlayerService::getInterfaceDescriptor());
    return remote()->transact(BnMediaPlayerService::PULL_BATTERY_DATA, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(MediaPlayerService, "android.os.IMediaPlayerService");

status_t BnMediaPlayerService::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case CREATE: {
    CHECK_INTERFACE(IMediaPlayerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    const sp<IMediaPlayerClient>& _arg1;
    _arg1 = data.readStrongIMediaPlayerClient();
    int _arg2;
    _arg2 = data.readInt32();
    int res = create(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case DECODE_URL: {
    CHECK_INTERFACE(IMediaPlayerService, data, reply);
    CString _arg0;
    _arg0 = data.readCString();
    int _arg1;
    int _arg2;
    int _arg3;
    int res = decodeUrl(_arg0, _arg1, _arg2, _arg3);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(pSampleRate);
data._data.writeInt32(%s);
(pNumChannels);
data._data.writeInt32(%s);
(pFormat);
    return NO_ERROR;
    }
case DECODE_FD: {
    CHECK_INTERFACE(IMediaPlayerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    long _arg1;
    _arg1 = data.readInt64();
    long _arg2;
    _arg2 = data.readInt64();
    int _arg3;
    int _arg4;
    int _arg5;
    int res = decodeFd(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(pSampleRate);
data._data.writeInt32(%s);
(pNumChannels);
data._data.writeInt32(%s);
(pFormat);
    return NO_ERROR;
    }
case CREATE_MEDIA_RECORDER: {
    CHECK_INTERFACE(IMediaPlayerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = createMediaRecorder(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case CREATE_METADATA_RETRIEVER: {
    CHECK_INTERFACE(IMediaPlayerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = createMetadataRetriever(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_OMX: {
    CHECK_INTERFACE(IMediaPlayerService, data, reply);
    int res = getOMX();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case MAKE_CRYPTO: {
    CHECK_INTERFACE(IMediaPlayerService, data, reply);
    int res = makeCrypto();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case ADD_BATTERY_DATA: {
    CHECK_INTERFACE(IMediaPlayerService, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    addBatteryData(_arg0);
    return NO_ERROR;
    }
case PULL_BATTERY_DATA: {
    CHECK_INTERFACE(IMediaPlayerService, data, reply);
    const sp<zParcel>& _arg0;
    pullBatteryData(_arg0);
data.%s.writeToParcel(&_data);
(reply);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
