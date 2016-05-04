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
	aidl_language.cpp \
	options.cpp \
	search_path.cpp \
	AST.cpp \
	Type.cpp \
	generate_cpp.cpp \

LOCAL_CFLAGS := -g
LOCAL_MODULE := aidl
LOCAL_MODULE_TAGS := optional

include $(BUILD_HOST_EXECUTABLE)

endif # TARGET_BUILD_APPS
