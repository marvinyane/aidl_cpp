/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IOMXObserver.aidl
 */
#define LOG_TAG "OMXObserver"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <omxobserver/IOMXObserver.h>

namespace android {

class BpOMXObserver : public BpInterface<IOMXObserver>
{
    public:
    BpOMXObserver(const sp<IBinder>& impl)
        : BpInterface<IOMXObserver>(impl) { }

virtual status_t bogus_connect()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_CONNECT, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_livesLocally()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_LIVES_LOCALLY, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_listNodes()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_LIST_NODES, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_allocateNode()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_ALLOCATE_NODE, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_freeNode()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_FREE_NODE, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_sendCommand()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_SEND_COMMAND, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_getParameter()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_GET_PARAMETER, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_setParameter()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_SET_PARAMETER, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_getConfig()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_GET_CONFIG, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_setConfig()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_SET_CONFIG, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_getState()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_GET_STATE, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_enableGraphicBuffers()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_ENABLE_GRAPHIC_BUFFERS, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_useBuffer()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_USE_BUFFER, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_useGraphicBuffer()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_USE_GRAPHIC_BUFFER, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_storeMetaDataInBuffers()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_STORE_META_DATA_IN_BUFFERS, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_allocateBuffer()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_ALLOCATE_BUFFER, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_allocateBufferWithBackup()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_ALLOCATE_BUFFER_WITH_BACKUP, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_freeBuffer()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_FREE_BUFFER, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_fillBuffer()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_FILL_BUFFER, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_emptyBuffer()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_EMPTY_BUFFER, _data, &reply);
}
/* only in IOMX interface */
virtual status_t bogus_getExtensionIndex()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_GET_EXTENSION_INDEX, _data, &reply);
}
/* only in IOMX interface */
virtual status_t onMessage(const sp<omx_message>& msg)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    msg.writeToParcel(&_data);
    return remote()->transact(BnOMXObserver::ON_MESSAGE, _data, &reply);
}

virtual status_t bogus_getGraphicBufferUsage()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMXObserver::getInterfaceDescriptor());
    return remote()->transact(BnOMXObserver::BOGUS_GET_GRAPHIC_BUFFER_USAGE, _data, &reply);
}
};

IMPLEMENT_META_INTERFACE(OMXObserver, "android.os.IOMXObserver");

status_t BnOMXObserver::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case BOGUS_CONNECT: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_connect();
    return NO_ERROR;
    }
case BOGUS_LIVES_LOCALLY: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_livesLocally();
    return NO_ERROR;
    }
case BOGUS_LIST_NODES: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_listNodes();
    return NO_ERROR;
    }
case BOGUS_ALLOCATE_NODE: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_allocateNode();
    return NO_ERROR;
    }
case BOGUS_FREE_NODE: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_freeNode();
    return NO_ERROR;
    }
case BOGUS_SEND_COMMAND: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_sendCommand();
    return NO_ERROR;
    }
case BOGUS_GET_PARAMETER: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_getParameter();
    return NO_ERROR;
    }
case BOGUS_SET_PARAMETER: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_setParameter();
    return NO_ERROR;
    }
case BOGUS_GET_CONFIG: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_getConfig();
    return NO_ERROR;
    }
case BOGUS_SET_CONFIG: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_setConfig();
    return NO_ERROR;
    }
case BOGUS_GET_STATE: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_getState();
    return NO_ERROR;
    }
case BOGUS_ENABLE_GRAPHIC_BUFFERS: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_enableGraphicBuffers();
    return NO_ERROR;
    }
case BOGUS_USE_BUFFER: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_useBuffer();
    return NO_ERROR;
    }
case BOGUS_USE_GRAPHIC_BUFFER: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_useGraphicBuffer();
    return NO_ERROR;
    }
case BOGUS_STORE_META_DATA_IN_BUFFERS: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_storeMetaDataInBuffers();
    return NO_ERROR;
    }
case BOGUS_ALLOCATE_BUFFER: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_allocateBuffer();
    return NO_ERROR;
    }
case BOGUS_ALLOCATE_BUFFER_WITH_BACKUP: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_allocateBufferWithBackup();
    return NO_ERROR;
    }
case BOGUS_FREE_BUFFER: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_freeBuffer();
    return NO_ERROR;
    }
case BOGUS_FILL_BUFFER: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_fillBuffer();
    return NO_ERROR;
    }
case BOGUS_EMPTY_BUFFER: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_emptyBuffer();
    return NO_ERROR;
    }
case BOGUS_GET_EXTENSION_INDEX: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_getExtensionIndex();
    return NO_ERROR;
    }
case ON_MESSAGE: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    const sp<omx_message>& _arg0;
    _arg0 = data.readStrongomx_message();
    onMessage(_arg0);
    return NO_ERROR;
    }
case BOGUS_GET_GRAPHIC_BUFFER_USAGE: {
    CHECK_INTERFACE(IOMXObserver, data, reply);
    bogus_getGraphicBufferUsage();
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
