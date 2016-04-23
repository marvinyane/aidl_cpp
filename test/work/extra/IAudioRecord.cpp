/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IAudioRecord.aidl
 */
#define LOG_TAG "AudioRecord"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <audiorecord/IAudioRecord.h>

namespace android {

class BpAudioRecord : public BpInterface<IAudioRecord>
{
    public:
    BpAudioRecord(const sp<IBinder>& impl)
        : BpInterface<IAudioRecord>(impl) { }

virtual const sp<IMemory>& getCblk()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioRecord::getInterfaceDescriptor());
    remote()->transact(BnAudioRecord::GET_CBLK, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& start(int event, int triggerSession)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioRecord::getInterfaceDescriptor());
    _data.writeInt32(event);
    _data.writeInt32(triggerSession);
    remote()->transact(BnAudioRecord::START, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t stop()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IAudioRecord::getInterfaceDescriptor());
    return remote()->transact(BnAudioRecord::STOP, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(AudioRecord, "android.os.IAudioRecord");

status_t BnAudioRecord::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case GET_CBLK: {
    CHECK_INTERFACE(IAudioRecord, data, reply);
    int res = getCblk();
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case START: {
    CHECK_INTERFACE(IAudioRecord, data, reply);
    int _arg0;
    _arg0 = data.readInt32();
    int _arg1;
    _arg1 = data.readInt32();
    int res = start(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case STOP: {
    CHECK_INTERFACE(IAudioRecord, data, reply);
    stop();
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
