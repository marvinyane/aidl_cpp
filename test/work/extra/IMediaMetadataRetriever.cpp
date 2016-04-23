/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMediaMetadataRetriever.aidl
 */
#define LOG_TAG "MediaMetadataRetriever"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <mediametadataretriever/IMediaMetadataRetriever.h>

namespace android {

class BpMediaMetadataRetriever : public BpInterface<IMediaMetadataRetriever>
{
    public:
    BpMediaMetadataRetriever(const sp<IBinder>& impl)
        : BpInterface<IMediaMetadataRetriever>(impl) { }

virtual status_t disconnect()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaMetadataRetriever::getInterfaceDescriptor());
    return remote()->transact(BnMediaMetadataRetriever::DISCONNECT, _data, &reply);
}

virtual const sp<status_t>& setDataSourceUrl(const CString& srcUrl, const CString& headers)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaMetadataRetriever::getInterfaceDescriptor());
    _data.writeCString(srcUrl);
    _data.writeCString(headers);
    remote()->transact(BnMediaMetadataRetriever::SET_DATA_SOURCE_URL, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setDataSourceFd(int fd, long offset, long length)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaMetadataRetriever::getInterfaceDescriptor());
    _data.writeInt32(fd);
    _data.writeInt64(offset);
    _data.writeInt64(length);
    remote()->transact(BnMediaMetadataRetriever::SET_DATA_SOURCE_FD, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<IMemory>& getFrameAtTime(long timeUs, int option)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaMetadataRetriever::getInterfaceDescriptor());
    _data.writeInt64(timeUs);
    _data.writeInt32(option);
    remote()->transact(BnMediaMetadataRetriever::GET_FRAME_AT_TIME, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<IMemory>& extractAlbumArt()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaMetadataRetriever::getInterfaceDescriptor());
    remote()->transact(BnMediaMetadataRetriever::EXTRACT_ALBUM_ART, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual CString extractMetadata(int keyCode)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IMediaMetadataRetriever::getInterfaceDescriptor());
    _data.writeInt32(keyCode);
    remote()->transact(BnMediaMetadataRetriever::EXTRACT_METADATA, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(MediaMetadataRetriever, "android.os.IMediaMetadataRetriever");

status_t BnMediaMetadataRetriever::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case DISCONNECT: {
    CHECK_INTERFACE(IMediaMetadataRetriever, data, reply);
    disconnect();
    return NO_ERROR;
    }
case SET_DATA_SOURCE_URL: {
    CHECK_INTERFACE(IMediaMetadataRetriever, data, reply);
    CString _arg0;
    _arg0 = data.readCString();
    CString _arg1;
    _arg1 = data.readCString();
    int res = setDataSourceUrl(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SET_DATA_SOURCE_FD: {
    CHECK_INTERFACE(IMediaMetadataRetriever, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    long _arg1;
    _arg1 = data.readInt64();
    long _arg2;
    _arg2 = data.readInt64();
    int res = setDataSourceFd(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_FRAME_AT_TIME: {
    CHECK_INTERFACE(IMediaMetadataRetriever, data, reply);
    long _arg0;
    _arg0 = data.readInt64();
    int _arg1;
    _arg1 = data.readInt32();
    int res = getFrameAtTime(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case EXTRACT_ALBUM_ART: {
    CHECK_INTERFACE(IMediaMetadataRetriever, data, reply);
    int res = extractAlbumArt();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case EXTRACT_METADATA: {
    CHECK_INTERFACE(IMediaMetadataRetriever, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int res = extractMetadata(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
