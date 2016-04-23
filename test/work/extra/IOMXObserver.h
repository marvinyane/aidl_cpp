/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: extra/IOMXObserver.aidl
 */
#ifndef ANDROID_IOMXOBSERVER_H
#define ANDROID_IOMXOBSERVER_H

#include <binder/IInterface.h>
#include <utils/String8.h>

namespace android {

class IOMXObserver : public IInterface
{
public:
    DECLARE_META_INTERFACE(OMXObserver);
    virtual status_t bogus_connect() = 0;
    virtual status_t bogus_livesLocally() = 0;
    virtual status_t bogus_listNodes() = 0;
    virtual status_t bogus_allocateNode() = 0;
    virtual status_t bogus_freeNode() = 0;
    virtual status_t bogus_sendCommand() = 0;
    virtual status_t bogus_getParameter() = 0;
    virtual status_t bogus_setParameter() = 0;
    virtual status_t bogus_getConfig() = 0;
    virtual status_t bogus_setConfig() = 0;
    virtual status_t bogus_getState() = 0;
    virtual status_t bogus_enableGraphicBuffers() = 0;
    virtual status_t bogus_useBuffer() = 0;
    virtual status_t bogus_useGraphicBuffer() = 0;
    virtual status_t bogus_storeMetaDataInBuffers() = 0;
    virtual status_t bogus_allocateBuffer() = 0;
    virtual status_t bogus_allocateBufferWithBackup() = 0;
    virtual status_t bogus_freeBuffer() = 0;
    virtual status_t bogus_fillBuffer() = 0;
    virtual status_t bogus_emptyBuffer() = 0;
    virtual status_t bogus_getExtensionIndex() = 0;
    virtual status_t onMessage(const sp<omx_message>& msg) = 0;
    virtual status_t bogus_getGraphicBufferUsage() = 0;
};

class BnOMXObserver : public BnInterface<IOMXObserver>
{
public:
    enum {
        BOGUS_CONNECT = IBinder::FIRST_CALL_TRANSACTION,
        BOGUS_LIVES_LOCALLY,
        BOGUS_LIST_NODES,
        BOGUS_ALLOCATE_NODE,
        BOGUS_FREE_NODE,
        BOGUS_SEND_COMMAND,
        BOGUS_GET_PARAMETER,
        BOGUS_SET_PARAMETER,
        BOGUS_GET_CONFIG,
        BOGUS_SET_CONFIG,
        BOGUS_GET_STATE,
        BOGUS_ENABLE_GRAPHIC_BUFFERS,
        BOGUS_USE_BUFFER,
        BOGUS_USE_GRAPHIC_BUFFER,
        BOGUS_STORE_META_DATA_IN_BUFFERS,
        BOGUS_ALLOCATE_BUFFER,
        BOGUS_ALLOCATE_BUFFER_WITH_BACKUP,
        BOGUS_FREE_BUFFER,
        BOGUS_FILL_BUFFER,
        BOGUS_EMPTY_BUFFER,
        BOGUS_GET_EXTENSION_INDEX,
        ON_MESSAGE,
        BOGUS_GET_GRAPHIC_BUFFER_USAGE,
    };
    virtual status_t onTransact(uint32_t code, const Parcel& data,
        Parcel *reply, uint32_t flags);
};
}; // namespace android

#endif // ANDROID_IOMXOBSERVER_H
