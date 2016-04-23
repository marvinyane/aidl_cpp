/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IOMX.aidl
 */
#define LOG_TAG "OMX"
//#define LOG_NDEBUG 0

#include <binder/Parcel.h>
#include <omx/IOMX.h>

namespace android {

class BpOMX : public BpInterface<IOMX>
{
    public:
    BpOMX(const sp<IBinder>& impl)
        : BpInterface<IOMX>(impl) { }

virtual status_t connect()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    return remote()->transact(BnOMX::CONNECT, _data, &reply);
}
/* not defined */
virtual bool livesLocally(const sp<IntPtr>& node, int pid)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    _data.writeInt32(pid);
    remote()->transact(BnOMX::LIVES_LOCALLY, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& listNodes(const sp<ListComponentInfo>& list)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    remote()->transact(BnOMX::LIST_NODES, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& allocateNode(const CString& name, const sp<IOMXObserver>& observer, const sp<IntPtr>& node)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    _data.writeCString(name);
    observer.writeToParcel(&_data);
    remote()->transact(BnOMX::ALLOCATE_NODE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& freeNode(const sp<IntPtr>& node)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    remote()->transact(BnOMX::FREE_NODE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& sendCommand(const sp<IntPtr>& node, int cmd, int param)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    _data.writeInt32(cmd);
    _data.writeInt32(param);
    remote()->transact(BnOMX::SEND_COMMAND, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getParameter(const sp<IntPtr>& node, int index, const sp<void>& params, int size)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    _data.writeInt32(index);
    params.writeToParcel(&_data);
    _data.writeInt32(size);
    remote()->transact(BnOMX::GET_PARAMETER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setParameter(const sp<IntPtr>& node, int index, const sp<void>& params, int size)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    _data.writeInt32(index);
    params.writeToParcel(&_data);
    _data.writeInt32(size);
    remote()->transact(BnOMX::SET_PARAMETER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getConfig(const sp<IntPtr>& node, int index, const sp<void>& params, int size)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    _data.writeInt32(index);
    params.writeToParcel(&_data);
    _data.writeInt32(size);
    remote()->transact(BnOMX::GET_CONFIG, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& setConfig(const sp<IntPtr>& node, int index, const sp<void>& params, int size)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    _data.writeInt32(index);
    params.writeToParcel(&_data);
    _data.writeInt32(size);
    remote()->transact(BnOMX::SET_CONFIG, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getState(const sp<IntPtr>& node, int state)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    remote()->transact(BnOMX::GET_STATE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& enableGraphicBuffers(const sp<IntPtr>& node, int port_index, bool enable)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    _data.writeInt32(port_index);
    _data.writeInt32((int)enable);
    remote()->transact(BnOMX::ENABLE_GRAPHIC_BUFFERS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& useBuffer(const sp<IntPtr>& node, int port_index, const sp<IMemory>& params, const sp<buffer_id>& buffer)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    _data.writeInt32(port_index);
    params.writeToParcel(&_data);
    remote()->transact(BnOMX::USE_BUFFER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& useGraphicBuffer(const sp<IntPtr>& node, int port_index, const sp<GraphicBuffer>& graphicBuffer, const sp<buffer_id>& buffer)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    _data.writeInt32(port_index);
    graphicBuffer.writeToParcel(&_data);
    remote()->transact(BnOMX::USE_GRAPHIC_BUFFER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& storeMetaDataInBuffers(const sp<IntPtr>& node, int port_index, bool enable)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    _data.writeInt32(port_index);
    _data.writeInt32((int)enable);
    remote()->transact(BnOMX::STORE_META_DATA_IN_BUFFERS, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& allocateBuffer(const sp<IntPtr>& node, int port_index, int size, const sp<buffer_id>& buffer, int buffer_data)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    _data.writeInt32(port_index);
    _data.writeInt32(size);
    remote()->transact(BnOMX::ALLOCATE_BUFFER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& allocateBufferWithBackup(const sp<IntPtr>& node, int port_index, const sp<IMemory>& params, const sp<buffer_id>& buffer)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    _data.writeInt32(port_index);
    params.writeToParcel(&_data);
    remote()->transact(BnOMX::ALLOCATE_BUFFER_WITH_BACKUP, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& freeBuffer(const sp<IntPtr>& node, int port_index, int buffer)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    _data.writeInt32(port_index);
    _data.writeInt32(buffer);
    remote()->transact(BnOMX::FREE_BUFFER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& fillBuffer(const sp<IntPtr>& node, int buffer)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    _data.writeInt32(buffer);
    remote()->transact(BnOMX::FILL_BUFFER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& emptyBuffer(const sp<IntPtr>& node, int buffer, int range_offset, int range_length, int flags, long timestamp)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    _data.writeInt32(buffer);
    _data.writeInt32(range_offset);
    _data.writeInt32(range_length);
    _data.writeInt32(flags);
    _data.writeInt64(timestamp);
    remote()->transact(BnOMX::EMPTY_BUFFER, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual const sp<status_t>& getExtensionIndex(const sp<IntPtr>& node, const CString& parameter_name, int index)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    _data.writeCString(parameter_name);
    remote()->transact(BnOMX::GET_EXTENSION_INDEX, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}

virtual status_t onMessage_bogus()
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    return remote()->transact(BnOMX::ON_MESSAGE_BOGUS, _data, &reply);
}
/* this is only in the IOMXObserver interface */
virtual const sp<status_t>& getGraphicBufferUsage(const sp<IntPtr>& node, int port_index, int usage)
{
    Parcel _data, reply;
   _data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    node.writeToParcel(&_data);
    _data.writeInt32(port_index);
    remote()->transact(BnOMX::GET_GRAPHIC_BUFFER_USAGE, _data, &reply);
    // fail on exception
    if (reply.readExceptionCode() != 0) return 0;
    return reply.readInt32();
}
};

IMPLEMENT_META_INTERFACE(OMX, "android.os.IOMX");

status_t BnOMX::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)
{
switch (code) {
case CONNECT: {
    CHECK_INTERFACE(IOMX, data, reply);
    connect();
    return NO_ERROR;
    }
case LIVES_LOCALLY: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    int _arg1;
    _arg1 = data.readInt32();
    int res = livesLocally(_arg0, _arg1)? 1 : 0;
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case LIST_NODES: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<ListComponentInfo>& _arg0;
    int res = listNodes(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(list);
    return NO_ERROR;
    }
case ALLOCATE_NODE: {
    CHECK_INTERFACE(IOMX, data, reply);
    CString _arg0;
    _arg0 = data.readCString();
    const sp<IOMXObserver>& _arg1;
    _arg1 = data.readStrongIOMXObserver();
    const sp<IntPtr>& _arg2;
    int res = allocateNode(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(node);
    return NO_ERROR;
    }
case FREE_NODE: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    int res = freeNode(_arg0);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case SEND_COMMAND: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int res = sendCommand(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_PARAMETER: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    int _arg1;
    _arg1 = data.readInt32();
    const sp<void>& _arg2;
    _arg2 = data.readStrongvoid();
    int _arg3;
    _arg3 = data.readInt32();
    int res = getParameter(_arg0, _arg1, _arg2, _arg3);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(params);
    return NO_ERROR;
    }
case SET_PARAMETER: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    int _arg1;
    _arg1 = data.readInt32();
    const sp<void>& _arg2;
    _arg2 = data.readStrongvoid();
    int _arg3;
    _arg3 = data.readInt32();
    int res = setParameter(_arg0, _arg1, _arg2, _arg3);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_CONFIG: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    int _arg1;
    _arg1 = data.readInt32();
    const sp<void>& _arg2;
    _arg2 = data.readStrongvoid();
    int _arg3;
    _arg3 = data.readInt32();
    int res = getConfig(_arg0, _arg1, _arg2, _arg3);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(params);
    return NO_ERROR;
    }
case SET_CONFIG: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    int _arg1;
    _arg1 = data.readInt32();
    const sp<void>& _arg2;
    _arg2 = data.readStrongvoid();
    int _arg3;
    _arg3 = data.readInt32();
    int res = setConfig(_arg0, _arg1, _arg2, _arg3);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_STATE: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    int _arg1;
    int res = getState(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(state);
    return NO_ERROR;
    }
case ENABLE_GRAPHIC_BUFFERS: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    int _arg1;
    _arg1 = data.readInt32();
    bool _arg2;
    _arg2 = data.readInt32();
    int res = enableGraphicBuffers(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case USE_BUFFER: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    int _arg1;
    _arg1 = data.readInt32();
    const sp<IMemory>& _arg2;
    _arg2 = data.readStrongIMemory();
    const sp<buffer_id>& _arg3;
    int res = useBuffer(_arg0, _arg1, _arg2, _arg3);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(buffer);
    return NO_ERROR;
    }
case USE_GRAPHIC_BUFFER: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    int _arg1;
    _arg1 = data.readInt32();
    const sp<GraphicBuffer>& _arg2;
    _arg2 = data.readStrongGraphicBuffer();
    const sp<buffer_id>& _arg3;
    int res = useGraphicBuffer(_arg0, _arg1, _arg2, _arg3);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(buffer);
    return NO_ERROR;
    }
case STORE_META_DATA_IN_BUFFERS: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    int _arg1;
    _arg1 = data.readInt32();
    bool _arg2;
    _arg2 = data.readInt32();
    int res = storeMetaDataInBuffers(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case ALLOCATE_BUFFER: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    const sp<buffer_id>& _arg3;
    int _arg4;
    int res = allocateBuffer(_arg0, _arg1, _arg2, _arg3, _arg4);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(buffer);
data._data.writeInt32(%s);
(buffer_data);
    return NO_ERROR;
    }
case ALLOCATE_BUFFER_WITH_BACKUP: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    int _arg1;
    _arg1 = data.readInt32();
    const sp<IMemory>& _arg2;
    _arg2 = data.readStrongIMemory();
    const sp<buffer_id>& _arg3;
    int res = allocateBufferWithBackup(_arg0, _arg1, _arg2, _arg3);
    reply->writeNoException();
    reply->writeInt32(res);
data.%s.writeToParcel(&_data);
(buffer);
    return NO_ERROR;
    }
case FREE_BUFFER: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int res = freeBuffer(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case FILL_BUFFER: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    int _arg1;
    _arg1 = data.readInt32();
    int res = fillBuffer(_arg0, _arg1);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case EMPTY_BUFFER: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    _arg2 = data.readInt32();
    int _arg3;
    _arg3 = data.readInt32();
    int _arg4;
    _arg4 = data.readInt32();
    long _arg5;
    _arg5 = data.readInt64();
    int res = emptyBuffer(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5);
    reply->writeNoException();
    reply->writeInt32(res);
    return NO_ERROR;
    }
case GET_EXTENSION_INDEX: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    CString _arg1;
    _arg1 = data.readCString();
    int _arg2;
    int res = getExtensionIndex(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(index);
    return NO_ERROR;
    }
case ON_MESSAGE_BOGUS: {
    CHECK_INTERFACE(IOMX, data, reply);
    onMessage_bogus();
    return NO_ERROR;
    }
case GET_GRAPHIC_BUFFER_USAGE: {
    CHECK_INTERFACE(IOMX, data, reply);
    const sp<IntPtr>& _arg0;
    _arg0 = data.readStrongIntPtr();
    int _arg1;
    _arg1 = data.readInt32();
    int _arg2;
    int res = getGraphicBufferUsage(_arg0, _arg1, _arg2);
    reply->writeNoException();
    reply->writeInt32(res);
data._data.writeInt32(%s);
(usage);
    return NO_ERROR;
    }
}
return BBinder::onTransact(code, data, reply, flags);
}

}; // namespace android
