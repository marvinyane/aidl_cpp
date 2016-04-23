/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMediaPlayerService.aidl
 */
#ifndef ANDROID_IMEDIA_PLAYER_SERVICE_H
#define ANDROID_IMEDIA_PLAYER_SERVICE_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IMediaPlayerService : public IInterface
{
public:
    DECLARE_META_INTERFACE(MediaPlayerService);
    virtual const sp<IMediaPlayer>& create(int pid, const sp<IMediaPlayerClient>& client, int audioSessionId) = 0;
    virtual const sp<IMemory>& decodeUrl(const CString& url, int pSampleRate, int pNumChannels, int pFormat) = 0;
    virtual const sp<IMemory>& decodeFd(int fd, long offset, long length, int pSampleRate, int pNumChannels, int pFormat) = 0;
    virtual const sp<IMediaRecorder>& createMediaRecorder(int pid) = 0;
    virtual const sp<IMediaMetadataRetriever>& createMetadataRetriever(int pid) = 0;
    virtual const sp<IOMX>& getOMX() = 0;
    virtual const sp<ICrypto>& makeCrypto() = 0;
    virtual status_t addBatteryData(int params) = 0;
    virtual status_t pullBatteryData(const sp<zParcel>& reply) = 0;
};

class BnMediaPlayerService : public BnInterface<IMediaPlayerService>
{
public:
    enum {
        CREATE = IBinder::FIRST_CALL_TRANSACTION,
        DECODE_URL,
        DECODE_FD,
        CREATE_MEDIA_RECORDER,
        CREATE_METADATA_RETRIEVER,
        GET_OMX,
        MAKE_CRYPTO,
        ADD_BATTERY_DATA,
        PULL_BATTERY_DATA,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IMEDIA_PLAYER_SERVICE_H
