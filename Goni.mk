# Copyright 2007 The Android Open Source Project
#
# Copies files into the directory structure described by a manifest

# This tool is prebuilt if we're doing an app-only build.
ifeq ($(TARGET_BUILD_APPS),)

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	aidl_language_y.y \
	aidl_language_l.l \
	aidl.cpp \
	options.cpp \
	generate_cpp.cpp \

LOCAL_CFLAGS := -g -std=gnu++0x
LOCAL_MODULE := aidl
LOCAL_MODULE_TAGS := optional

include $(BUILD_HOST_EXECUTABLE)

endif # TARGET_BUILD_APPS
