/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IOMX.aidl
 */
#ifndef ANDROID_IOMX_H
#define ANDROID_IOMX_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IOMX : public IInterface
{
public:
    DECLARE_META_INTERFACE(OMX);
    virtual status_t connect() = 0;
    virtual bool livesLocally(const sp<IntPtr>& node, int pid) = 0;
    virtual const sp<status_t>& listNodes(const sp<ListComponentInfo>& list) = 0;
    virtual const sp<status_t>& allocateNode(const CString& name, const sp<IOMXObserver>& observer, const sp<IntPtr>& node) = 0;
    virtual const sp<status_t>& freeNode(const sp<IntPtr>& node) = 0;
    virtual const sp<status_t>& sendCommand(const sp<IntPtr>& node, int cmd, int param) = 0;
    virtual const sp<status_t>& getParameter(const sp<IntPtr>& node, int index, const sp<void>& params, int size) = 0;
    virtual const sp<status_t>& setParameter(const sp<IntPtr>& node, int index, const sp<void>& params, int size) = 0;
    virtual const sp<status_t>& getConfig(const sp<IntPtr>& node, int index, const sp<void>& params, int size) = 0;
    virtual const sp<status_t>& setConfig(const sp<IntPtr>& node, int index, const sp<void>& params, int size) = 0;
    virtual const sp<status_t>& getState(const sp<IntPtr>& node, int state) = 0;
    virtual const sp<status_t>& enableGraphicBuffers(const sp<IntPtr>& node, int port_index, bool enable) = 0;
    virtual const sp<status_t>& useBuffer(const sp<IntPtr>& node, int port_index, const sp<IMemory>& params, const sp<buffer_id>& buffer) = 0;
    virtual const sp<status_t>& useGraphicBuffer(const sp<IntPtr>& node, int port_index, const sp<GraphicBuffer>& graphicBuffer, const sp<buffer_id>& buffer) = 0;
    virtual const sp<status_t>& storeMetaDataInBuffers(const sp<IntPtr>& node, int port_index, bool enable) = 0;
    virtual const sp<status_t>& allocateBuffer(const sp<IntPtr>& node, int port_index, int size, const sp<buffer_id>& buffer, int buffer_data) = 0;
    virtual const sp<status_t>& allocateBufferWithBackup(const sp<IntPtr>& node, int port_index, const sp<IMemory>& params, const sp<buffer_id>& buffer) = 0;
    virtual const sp<status_t>& freeBuffer(const sp<IntPtr>& node, int port_index, int buffer) = 0;
    virtual const sp<status_t>& fillBuffer(const sp<IntPtr>& node, int buffer) = 0;
    virtual const sp<status_t>& emptyBuffer(const sp<IntPtr>& node, int buffer, int range_offset, int range_length, int flags, long timestamp) = 0;
    virtual const sp<status_t>& getExtensionIndex(const sp<IntPtr>& node, const CString& parameter_name, int index) = 0;
    virtual status_t onMessage_bogus() = 0;
    virtual const sp<status_t>& getGraphicBufferUsage(const sp<IntPtr>& node, int port_index, int usage) = 0;
};

class BnOMX : public BnInterface<IOMX>
{
public:
    enum {
        CONNECT = IBinder::FIRST_CALL_TRANSACTION,
        LIVES_LOCALLY,
        LIST_NODES,
        ALLOCATE_NODE,
        FREE_NODE,
        SEND_COMMAND,
        GET_PARAMETER,
        SET_PARAMETER,
        GET_CONFIG,
        SET_CONFIG,
        GET_STATE,
        ENABLE_GRAPHIC_BUFFERS,
        USE_BUFFER,
        USE_GRAPHIC_BUFFER,
        STORE_META_DATA_IN_BUFFERS,
        ALLOCATE_BUFFER,
        ALLOCATE_BUFFER_WITH_BACKUP,
        FREE_BUFFER,
        FILL_BUFFER,
        EMPTY_BUFFER,
        GET_EXTENSION_INDEX,
        ON_MESSAGE_BOGUS,
        GET_GRAPHIC_BUFFER_USAGE,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IOMX_H
