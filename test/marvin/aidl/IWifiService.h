/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: ./aidl/IWifiService.aidl
 */
#ifndef ANDROID_IWIFI_SERVICE_H
#define ANDROID_IWIFI_SERVICE_H

#include"servicebase/ServiceProxyBase.h"
#include "servicebase/ServiceBaseDefines.h"

namespace goni {

class IWifiServiceProxy : public ServiceProxyBase
{
public:
    virtual status_t SetEnabled(bool enabled);
    virtual status_t SendCommand(int command, int arg1, int arg2);
};

