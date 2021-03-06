LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := gameframework_static

LOCAL_MODULE_FILENAME := libGameFramework

LOCAL_SRC_FILES :=	Actors/ActorAction.cpp \
					Actors/ActorEntity.cpp \
					Actors/ActorEvents.cpp \
					Actors/ActorProp.cpp \
					Actors/ActorsControl.cpp \
					Actors/ActorsControlEvents.cpp \
					Actors/ActorsLayer.cpp \
					Actors/ActorTouch.cpp \
					Animation/BoneAnimation.cpp \
					Animation/FrameAnimation.cpp \
					Animation/Skeleton2D.cpp \
					Animation/Skeleton2DResource.cpp \
					Animation/SkeletonAnimation2DRes.cpp \
					Animation/SkeletonCocos2D.cpp \
					Base/INotifier.cpp \
					Base/INotifyEvent.cpp \
					Base/IObserver.cpp \
					Camera/Camera.cpp \
					Camera/CameraNotifyEvents.cpp \
					Camera/CameraObserver.cpp \
					Client/Client.cpp \
					MainScene.cpp \
					Physical/PhysicalControl.cpp \
					Physical/PhysicalObj.cpp \
					SceneInfo.cpp \
					SceneObjects/SceneObjectControlEvent.cpp \
					SceneObjects/SceneObjectEntity.cpp \
					SceneObjects/SceneObjectEvents.cpp \
					SceneObjects/SceneObjectProp.cpp \
					SceneObjects/SceneObjectsControl.cpp \
					SceneObjects/SceneObjectsLayer.cpp \
					Terrain/GridEntity.cpp \
					Terrain/GridEvents.cpp \
					Terrain/GridProp.cpp \
					Terrain/TerrainEvent.cpp \
					Terrain/TerrainLayer.cpp \
					Terrain/TerrainProp.cpp \
					tolua/CCLuaEngine.cpp \
					tolua/Cocos2dxLuaLoader.cpp \
					tolua/LuaCocos2d.cpp \
					tolua/tolua_fix.c \
					Tools/DebugLayer.cpp \
					Tools/EditAvatarData.cpp \
					Tools/EditBoneAvatarData.cpp \
					Tools/EditScene.cpp \
					Tools/FrameTools.cpp \
					UI/UIControl.cpp \
					UI/UIControlEvents.cpp \
					UI/UIEvents.cpp \
					UI/UILayer.cpp \
					UI/UIProperty.cpp \
					UI/UITargetProp.cpp \
					UI/UITargetWindow.cpp \
					UI/UIWindow.cpp \
					WorldManager.cpp \
					../Tools/AnimationData.cpp \
					../Tools/AnimationGroup.cpp \
					../Tools/AvatarData.cpp \
					../Tools/BoneAnimationData.cpp \
					../Tools/BoneAnimationGroup.cpp \
					../Tools/BoneAvatarData.cpp \
					../Tools/ENDirection.cpp \
					../Tools/FrameInfo.cpp \
					../Tools/Scene.cpp \
					../Tools/StreamHelper.cpp \
					../Tools/tinystr.cpp \
					../Tools/tinyxml.cpp \
					../Tools/tinyxmlerror.cpp \
					../Tools/tinyxmlparser.cpp \
					../CSProtocol/ActorBattleInfo.cpp \
					../CSProtocol/CSMessageDef.cpp \
					../CSProtocol/CSMessageType.cpp \
					../CSProtocol/CSPipeline.cpp \
					../VirtualServer/AIControl.cpp \
					../VirtualServer/AIState.cpp \
					../VirtualServer/GameServer.cpp \
					../VirtualServer/IActor.cpp \
					../VirtualServer/ISimulateLayer.cpp \
					../VirtualServer/ISimulateObject.cpp \
					../VirtualServer/NPC.cpp \
					../VirtualServer/Player.cpp 


LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../include

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include \
                    $(LOCAL_PATH)/../libs/cocos2dx \
                    $(LOCAL_PATH)/../libs/cocos2dx/include \
                    $(LOCAL_PATH)/../libs/cocos2dx/platform/android \
					$(LOCAL_PATH)/../libs/cocos2dx/kazmath/include \
					$(LOCAL_PATH)/../libs/external \
					$(LOCAL_PATH)/../libs/CocosDenshion/include \
					$(LOCAL_PATH)/../GameFramework \
					$(LOCAL_PATH)/../libs \
					$(LOCAL_PATH)/../ \
					$(LOCAL_PATH)/../libs/extensions \
					$(LOCAL_PATH)/../libs/lua/lua \
					$(LOCAL_PATH)/../libs/lua/tolua \
					$(LOCAL_PATH)/../libs/lua

LOCAL_CFLAGS += -DBOOST_EXCEPTION_DISABLE -D_STLP_NO_EXCEPTIONS -DOS_ANDROID -D_STLP_USE_SIMPLE_NODE_ALLOC

include $(BUILD_STATIC_LIBRARY)
