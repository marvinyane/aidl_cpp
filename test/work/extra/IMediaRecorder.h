/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IMediaRecorder.aidl
 */
#ifndef ANDROID_IMEDIA_RECORDER_H
#define ANDROID_IMEDIA_RECORDER_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IMediaRecorder : public IInterface
{
public:
    DECLARE_META_INTERFACE(MediaRecorder);
    virtual const sp<status_t>& release() = 0;
    virtual const sp<status_t>& init() = 0;
    virtual const sp<status_t>& close() = 0;
    virtual const sp<ISurfaceTexture>& querySurfaceMediaSource() = 0;
    virtual const sp<status_t>& reset() = 0;
    virtual const sp<status_t>& stop() = 0;
    virtual const sp<status_t>& start() = 0;
    virtual const sp<status_t>& prepare() = 0;
    virtual const sp<status_t>& getMaxAmplitude(int max) = 0;
    virtual const sp<status_t>& setVideoSource(int vs) = 0;
    virtual const sp<status_t>& setAudioSource(int as) = 0;
    virtual const sp<status_t>& setOutputFormat(int of) = 0;
    virtual const sp<status_t>& setVideoEncoder(int ve) = 0;
    virtual const sp<status_t>& setAudioEncoder(int ae) = 0;
    virtual const sp<status_t>& setOutputFilePath(const CString& path) = 0;
    virtual const sp<status_t>& setOutputFileFd(int fd, long offset, long length) = 0;
    virtual const sp<status_t>& setVideoSize(int width, int height) = 0;
    virtual const sp<status_t>& setVideoFrameRate(int frames_per_second) = 0;
    virtual const sp<status_t>& setParameters(const String8& params) = 0;
    virtual const sp<status_t>& setPreviewSurface(const sp<Surface>& surface) = 0;
    virtual const sp<status_t>& setCamera(const sp<ICamera>& camera, const sp<ICameraRecordingProxy>& proxy) = 0;
    virtual const sp<status_t>& setListener(const sp<IMediaRecorderClient>& listener) = 0;
};

class BnMediaRecorder : public BnInterface<IMediaRecorder>
{
public:
    enum {
        RELEASE = IBinder::FIRST_CALL_TRANSACTION,
        INIT,
        CLOSE,
        QUERY_SURFACE_MEDIA_SOURCE,
        RESET,
        STOP,
        START,
        PREPARE,
        GET_MAX_AMPLITUDE,
        SET_VIDEO_SOURCE,
        SET_AUDIO_SOURCE,
        SET_OUTPUT_FORMAT,
        SET_VIDEO_ENCODER,
        SET_AUDIO_ENCODER,
        SET_OUTPUT_FILE_PATH,
        SET_OUTPUT_FILE_FD,
        SET_VIDEO_SIZE,
        SET_VIDEO_FRAME_RATE,
        SET_PARAMETERS,
        SET_PREVIEW_SURFACE,
        SET_CAMERA,
        SET_LISTENER,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IMEDIA_RECORDER_H
