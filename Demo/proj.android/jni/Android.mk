LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp
                   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes\
					$(LOCAL_PATH)/../../GameFramework\
					$(LOCAL_PATH)/../../libs/lua/lua

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static cocos_extension_static gameframework_static cocos_lua_static
            
include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android) \
$(call import-module,cocos2dx) \
$(call import-module,extensions) \
$(call import-module,lua/proj.android/jni) \
$(call import-module,../GameFramework)
