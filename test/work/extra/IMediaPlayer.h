/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMediaPlayer.aidl
 */
#ifndef ANDROID_IMEDIA_PLAYER_H
#define ANDROID_IMEDIA_PLAYER_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IMediaPlayer : public IInterface
{
public:
    DECLARE_META_INTERFACE(MediaPlayer);
    virtual status_t disconnect() = 0;
    virtual const sp<status_t>& setDataSourceUrl(const CString& url, const String16& headers) = 0;
    virtual const sp<status_t>& setDataSourceFd(int fd, long offset, long length) = 0;
    virtual const sp<status_t>& setDataSourceStream(const sp<IStreamSource>& source) = 0;
    virtual const sp<status_t>& prepareAsync() = 0;
    virtual const sp<status_t>& start() = 0;
    virtual const sp<status_t>& stop() = 0;
    virtual const sp<status_t>& isPlaying(bool state) = 0;
    virtual const sp<status_t>& pause() = 0;
    virtual const sp<status_t>& seekTo(int msec) = 0;
    virtual const sp<status_t>& getCurrentPosition(int msec) = 0;
    virtual const sp<status_t>& getDuration(int msec) = 0;
    virtual const sp<status_t>& reset() = 0;
    virtual const sp<status_t>& setAudioStreamType(int type) = 0;
    virtual const sp<status_t>& setLooping(int loop) = 0;
    virtual const sp<status_t>& setVolume(float leftVolume, float rightVolume) = 0;
    virtual const sp<status_t>& invoke(const sp<zParcel>& request, const sp<zParcel>& reply) = 0;
    virtual const sp<status_t>& setMetadataFilter(const sp<zParcel>& filter) = 0;
    virtual const sp<status_t>& getMetadata(bool update_only, bool apply_filter, const sp<zParcel>& metadata) = 0;
    virtual const sp<status_t>& setAuxEffectSendLevel(float level) = 0;
    virtual const sp<status_t>& attachAuxEffect(int effectId) = 0;
    virtual const sp<status_t>& setVideoSurfaceTexture(const sp<ISurfaceTexture>& surfaceTexture) = 0;
    virtual const sp<status_t>& setParameter(int key, const sp<zParcel>& request) = 0;
    virtual const sp<status_t>& getParameter(int key, const sp<zParcel>& reply) = 0;
    virtual const sp<status_t>& setRetransmitEndpoint(const sp<sockaddr_in>& endpoint) = 0;
    virtual const sp<status_t>& setNextPlayer(const sp<IMediaPlayer>& next) = 0;
};

class BnMediaPlayer : public BnInterface<IMediaPlayer>
{
public:
    enum {
        DISCONNECT = IBinder::FIRST_CALL_TRANSACTION,
        SET_DATA_SOURCE_URL,
        SET_DATA_SOURCE_FD,
        SET_DATA_SOURCE_STREAM,
        PREPARE_ASYNC,
        START,
        STOP,
        IS_PLAYING,
        PAUSE,
        SEEK_TO,
        GET_CURRENT_POSITION,
        GET_DURATION,
        RESET,
        SET_AUDIO_STREAM_TYPE,
        SET_LOOPING,
        SET_VOLUME,
        INVOKE,
        SET_METADATA_FILTER,
        GET_METADATA,
        SET_AUX_EFFECT_SEND_LEVEL,
        ATTACH_AUX_EFFECT,
        SET_VIDEO_SURFACE_TEXTURE,
        SET_PARAMETER,
        GET_PARAMETER,
        SET_RETRANSMIT_ENDPOINT,
        SET_NEXT_PLAYER,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IMEDIA_PLAYER_H
