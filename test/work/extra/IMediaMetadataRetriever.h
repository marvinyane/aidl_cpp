/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMediaMetadataRetriever.aidl
 */
#ifndef ANDROID_IMEDIA_METADATA_RETRIEVER_H
#define ANDROID_IMEDIA_METADATA_RETRIEVER_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IMediaMetadataRetriever : public IInterface
{
public:
    DECLARE_META_INTERFACE(MediaMetadataRetriever);
    virtual status_t disconnect() = 0;
    virtual const sp<status_t>& setDataSourceUrl(const CString& srcUrl, const CString& headers) = 0;
    virtual const sp<status_t>& setDataSourceFd(int fd, long offset, long length) = 0;
    virtual const sp<IMemory>& getFrameAtTime(long timeUs, int option) = 0;
    virtual const sp<IMemory>& extractAlbumArt() = 0;
    virtual CString extractMetadata(int keyCode) = 0;
};

class BnMediaMetadataRetriever : public BnInterface<IMediaMetadataRetriever>
{
public:
    enum {
        DISCONNECT = IBinder::FIRST_CALL_TRANSACTION,
        SET_DATA_SOURCE_URL,
        SET_DATA_SOURCE_FD,
        GET_FRAME_AT_TIME,
        EXTRACT_ALBUM_ART,
        EXTRACT_METADATA,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IMEDIA_METADATA_RETRIEVER_H
