/*
** Lua binding: GameFramework
** Generated automatically by tolua++-1.0.92 on 01/08/13 14:51:42.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_GameFramework_open (lua_State* tolua_S);

#include "../WorldManager.h"
#include "../CSProtocol/CSPipeline.h"
#include "../Actors/ActorProp.h"
#include "../Actors/ActorsControl.h"
#include "../Terrain/TerrainProp.h"
#include "../SceneInfo.h"
#include "../Base/GlobalDef.h"
using namespace cocos2d;
using namespace Tools;
using namespace Game;
using namespace Net;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_CCPoint (lua_State* tolua_S)
{
 CCPoint* self = (CCPoint*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CCSize (lua_State* tolua_S)
{
 CCSize* self = (CCSize*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ActorProp (lua_State* tolua_S)
{
 ActorProp* self = (ActorProp*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_TerrainProp (lua_State* tolua_S)
{
 TerrainProp* self = (TerrainProp*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_SceneInfo (lua_State* tolua_S)
{
 SceneInfo* self = (SceneInfo*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ActorsControl (lua_State* tolua_S)
{
 ActorsControl* self = (ActorsControl*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
#ifndef Mtolua_typeid
#define Mtolua_typeid(L,TI,T)
#endif
 tolua_usertype(tolua_S,"CCPoint");
 Mtolua_typeid(tolua_S,CCPoint, "CCPoint");
 tolua_usertype(tolua_S,"ENEquipType::Decl");
 Mtolua_typeid(tolua_S,ENEquipType::Decl, "ENEquipType::Decl");
 tolua_usertype(tolua_S,"SceneInfo");
 Mtolua_typeid(tolua_S,SceneInfo, "SceneInfo");
 tolua_usertype(tolua_S,"CSPipeline");
 Mtolua_typeid(tolua_S,CSPipeline, "CSPipeline");
 tolua_usertype(tolua_S,"CCSize");
 Mtolua_typeid(tolua_S,CCSize, "CCSize");
 tolua_usertype(tolua_S,"CCNode");
 Mtolua_typeid(tolua_S,CCNode, "CCNode");
 tolua_usertype(tolua_S,"GridProp");
 Mtolua_typeid(tolua_S,GridProp, "GridProp");
 tolua_usertype(tolua_S,"AvatarData");
 Mtolua_typeid(tolua_S,AvatarData, "AvatarData");
 tolua_usertype(tolua_S,"ActorsControl");
 Mtolua_typeid(tolua_S,ActorsControl, "ActorsControl");
 tolua_usertype(tolua_S,"Scene");
 Mtolua_typeid(tolua_S,Scene, "Scene");
 tolua_usertype(tolua_S,"INotifier");
 Mtolua_typeid(tolua_S,INotifier, "INotifier");
 tolua_usertype(tolua_S,"ActorProp");
 Mtolua_typeid(tolua_S,ActorProp, "ActorProp");
 tolua_usertype(tolua_S,"TerrainProp");
 Mtolua_typeid(tolua_S,TerrainProp, "TerrainProp");
 tolua_usertype(tolua_S,"CCScene");
 Mtolua_typeid(tolua_S,CCScene, "CCScene");
 tolua_usertype(tolua_S,"ActorBattleInfo");
 Mtolua_typeid(tolua_S,ActorBattleInfo, "ActorBattleInfo");
 tolua_usertype(tolua_S,"ENActorType");
 Mtolua_typeid(tolua_S,ENActorType, "ENActorType");
 tolua_usertype(tolua_S,"Camera");
 Mtolua_typeid(tolua_S,Camera, "Camera");
 tolua_usertype(tolua_S,"WorldManager");
 Mtolua_typeid(tolua_S,WorldManager, "WorldManager");
 tolua_usertype(tolua_S,"GUI::UIProperty");
 Mtolua_typeid(tolua_S,GUI::UIProperty, "GUI::UIProperty");
 tolua_usertype(tolua_S,"Net::Client");
 Mtolua_typeid(tolua_S,Net::Client, "Net::Client");
 tolua_usertype(tolua_S,"SceneObjectsControl");
 Mtolua_typeid(tolua_S,SceneObjectsControl, "SceneObjectsControl");
 tolua_usertype(tolua_S,"PhysicalControl");
 Mtolua_typeid(tolua_S,PhysicalControl, "PhysicalControl");
 tolua_usertype(tolua_S,"GUI::UIControl");
 Mtolua_typeid(tolua_S,GUI::UIControl, "GUI::UIControl");
}

/* method: Instance of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_Instance00
static int tolua_GameFramework_WorldManager_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"WorldManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   WorldManager* tolua_ret = (WorldManager*)  WorldManager::Instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"WorldManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearUp of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_ClearUp00
static int tolua_GameFramework_WorldManager_ClearUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"WorldManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   WorldManager::ClearUp();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Init of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_Init00
static int tolua_GameFramework_WorldManager_Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"WorldManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  WorldManager* self = (WorldManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'", NULL);
#endif
  {
   CCScene* tolua_ret = (CCScene*)  self->Init();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCScene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InitSceneByFile of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_InitSceneByFile00
static int tolua_GameFramework_WorldManager_InitSceneByFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"WorldManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  WorldManager* self = (WorldManager*)  tolua_tousertype(tolua_S,1,0);
  const char* sceneName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InitSceneByFile'", NULL);
#endif
  {
   self->InitSceneByFile(sceneName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InitSceneByFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InitScene of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_InitScene00
static int tolua_GameFramework_WorldManager_InitScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"WorldManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  WorldManager* self = (WorldManager*)  tolua_tousertype(tolua_S,1,0);
  const Scene* scene = ((const Scene*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InitScene'", NULL);
#endif
  {
   self->InitScene(scene);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InitScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSceneInfo of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_GetSceneInfo00
static int tolua_GameFramework_WorldManager_GetSceneInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const WorldManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const WorldManager* self = (const WorldManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSceneInfo'", NULL);
#endif
  {
   SceneInfo* tolua_ret = (SceneInfo*)  self->GetSceneInfo();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneInfo");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSceneInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetActorsControl of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_GetActorsControl00
static int tolua_GameFramework_WorldManager_GetActorsControl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const WorldManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const WorldManager* self = (const WorldManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetActorsControl'", NULL);
#endif
  {
   ActorsControl* tolua_ret = (ActorsControl*)  self->GetActorsControl();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ActorsControl");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetActorsControl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTerrainProp of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_GetTerrainProp00
static int tolua_GameFramework_WorldManager_GetTerrainProp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const WorldManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const WorldManager* self = (const WorldManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTerrainProp'", NULL);
#endif
  {
   TerrainProp* tolua_ret = (TerrainProp*)  self->GetTerrainProp();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TerrainProp");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTerrainProp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSceneObjectsControl of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_GetSceneObjectsControl00
static int tolua_GameFramework_WorldManager_GetSceneObjectsControl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const WorldManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const WorldManager* self = (const WorldManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSceneObjectsControl'", NULL);
#endif
  {
   SceneObjectsControl* tolua_ret = (SceneObjectsControl*)  self->GetSceneObjectsControl();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneObjectsControl");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSceneObjectsControl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCamera of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_GetCamera00
static int tolua_GameFramework_WorldManager_GetCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const WorldManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const WorldManager* self = (const WorldManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCamera'", NULL);
#endif
  {
   Camera* tolua_ret = (Camera*)  self->GetCamera();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Camera");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUIControl of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_GetUIControl00
static int tolua_GameFramework_WorldManager_GetUIControl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const WorldManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const WorldManager* self = (const WorldManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUIControl'", NULL);
#endif
  {
   GUI::UIControl* tolua_ret = (GUI::UIControl*)  self->GetUIControl();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::UIControl");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUIControl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPhysicalControl of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_GetPhysicalControl00
static int tolua_GameFramework_WorldManager_GetPhysicalControl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const WorldManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const WorldManager* self = (const WorldManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPhysicalControl'", NULL);
#endif
  {
   PhysicalControl* tolua_ret = (PhysicalControl*)  self->GetPhysicalControl();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PhysicalControl");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPhysicalControl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRoot of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_GetRoot00
static int tolua_GameFramework_WorldManager_GetRoot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const WorldManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const WorldManager* self = (const WorldManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRoot'", NULL);
#endif
  {
   CCNode* tolua_ret = (CCNode*)  self->GetRoot();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRoot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WorldPosToDesign of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_WorldPosToDesign00
static int tolua_GameFramework_WorldManager_WorldPosToDesign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"WorldManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCPoint* worldPos = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
  {
   CCPoint tolua_ret = (CCPoint)  WorldManager::WorldPosToDesign(*worldPos);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WorldPosToDesign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DesignPosToWorld of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_DesignPosToWorld00
static int tolua_GameFramework_WorldManager_DesignPosToWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"WorldManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCPoint* screenPos = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
  {
   CCPoint tolua_ret = (CCPoint)  WorldManager::DesignPosToWorld(*screenPos);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DesignPosToWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LogicToPoint of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_LogicToPoint00
static int tolua_GameFramework_WorldManager_LogicToPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"WorldManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float size = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   float tolua_ret = (float)  WorldManager::LogicToPoint(size);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LogicToPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PointToLogic of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_PointToLogic00
static int tolua_GameFramework_WorldManager_PointToLogic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"WorldManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float size = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   float tolua_ret = (float)  WorldManager::PointToLogic(size);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PointToLogic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LogicToPoint of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_LogicToPoint01
static int tolua_GameFramework_WorldManager_LogicToPoint01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"WorldManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const CCPoint* pos = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
  {
   CCPoint tolua_ret = (CCPoint)  WorldManager::LogicToPoint(*pos);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_GameFramework_WorldManager_LogicToPoint00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: PointToLogic of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_PointToLogic01
static int tolua_GameFramework_WorldManager_PointToLogic01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"WorldManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const CCPoint* pos = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
  {
   CCPoint tolua_ret = (CCPoint)  WorldManager::PointToLogic(*pos);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_GameFramework_WorldManager_PointToLogic00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: LogicToPoint of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_LogicToPoint02
static int tolua_GameFramework_WorldManager_LogicToPoint02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"WorldManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const CCSize* pos = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
  {
   CCSize tolua_ret = (CCSize)  WorldManager::LogicToPoint(*pos);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCSize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCSize));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_GameFramework_WorldManager_LogicToPoint01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: PointToLogic of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_PointToLogic02
static int tolua_GameFramework_WorldManager_PointToLogic02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"WorldManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const CCSize* pos = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
  {
   CCSize tolua_ret = (CCSize)  WorldManager::PointToLogic(*pos);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCSize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCSize));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_GameFramework_WorldManager_PointToLogic01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_update00
static int tolua_GameFramework_WorldManager_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"WorldManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  WorldManager* self = (WorldManager*)  tolua_tousertype(tolua_S,1,0);
  float dt = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCollidable of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_SetCollidable00
static int tolua_GameFramework_WorldManager_SetCollidable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"WorldManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  WorldManager* self = (WorldManager*)  tolua_tousertype(tolua_S,1,0);
  bool isCollide = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCollidable'", NULL);
#endif
  {
   self->SetCollidable(isCollide);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCollidable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetClient of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_GameFramework_WorldManager_GetClient00
static int tolua_GameFramework_WorldManager_GetClient00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const WorldManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const WorldManager* self = (const WorldManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetClient'", NULL);
#endif
  {
   Net::Client* tolua_ret = (Net::Client*)  self->GetClient();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Net::Client");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetClient'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  CSPipeline */
#ifndef TOLUA_DISABLE_tolua_GameFramework_CSPipeline_Instance00
static int tolua_GameFramework_CSPipeline_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CSPipeline",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CSPipeline* tolua_ret = (CSPipeline*)  CSPipeline::Instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CSPipeline");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Init of class  CSPipeline */
#ifndef TOLUA_DISABLE_tolua_GameFramework_CSPipeline_Init00
static int tolua_GameFramework_CSPipeline_Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CSPipeline",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CSPipeline* self = (CSPipeline*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'", NULL);
#endif
  {
   self->Init();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_new00
static int tolua_GameFramework_ActorProp_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ActorProp",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ENActorType::Decl type = ((ENActorType::Decl) (int)  tolua_tonumber(tolua_S,2,0));
  int id = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   ActorProp* tolua_ret = (ActorProp*)  Mtolua_new((ActorProp)(type,id));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ActorProp");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_new00_local
static int tolua_GameFramework_ActorProp_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ActorProp",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ENActorType::Decl type = ((ENActorType::Decl) (int)  tolua_tonumber(tolua_S,2,0));
  int id = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   ActorProp* tolua_ret = (ActorProp*)  Mtolua_new((ActorProp)(type,id));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ActorProp");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_delete00
static int tolua_GameFramework_ActorProp_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorProp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorProp* self = (ActorProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetID of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_GetID00
static int tolua_GameFramework_ActorProp_GetID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ActorProp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ActorProp* self = (const ActorProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetID'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetID();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetActorType of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_GetActorType00
static int tolua_GameFramework_ActorProp_GetActorType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ActorProp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ActorProp* self = (const ActorProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetActorType'", NULL);
#endif
  {
   ENActorType::Decl tolua_ret = (ENActorType::Decl)  self->GetActorType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetActorType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPosition of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_GetPosition00
static int tolua_GameFramework_ActorProp_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ActorProp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ActorProp* self = (const ActorProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPosition'", NULL);
#endif
  {
   const CCPoint& tolua_ret = (const CCPoint&)  self->GetPosition();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const CCPoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSpeed of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_GetSpeed00
static int tolua_GameFramework_ActorProp_GetSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ActorProp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ActorProp* self = (const ActorProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Init of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_Init00
static int tolua_GameFramework_ActorProp_Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorProp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorProp* self = (ActorProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'", NULL);
#endif
  {
   self->Init();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Release of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_Release00
static int tolua_GameFramework_ActorProp_Release00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorProp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorProp* self = (ActorProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Release'", NULL);
#endif
  {
   self->Release();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Release'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MoveTo of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_MoveTo00
static int tolua_GameFramework_ActorProp_MoveTo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorProp",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorProp* self = (ActorProp*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* pos = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MoveTo'", NULL);
#endif
  {
   self->MoveTo(*pos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MoveTo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Stop of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_Stop00
static int tolua_GameFramework_ActorProp_Stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorProp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorProp* self = (ActorProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Stop'", NULL);
#endif
  {
   self->Stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Dead of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_Dead00
static int tolua_GameFramework_ActorProp_Dead00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorProp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorProp* self = (ActorProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Dead'", NULL);
#endif
  {
   self->Dead();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Dead'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StartAttack of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_StartAttack00
static int tolua_GameFramework_ActorProp_StartAttack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorProp",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ActorProp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorProp* self = (ActorProp*)  tolua_tousertype(tolua_S,1,0);
  ActorProp* target = ((ActorProp*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StartAttack'", NULL);
#endif
  {
   self->StartAttack(target);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StartAttack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChangeAvatar of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_ChangeAvatar00
static int tolua_GameFramework_ActorProp_ChangeAvatar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorProp",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"AvatarData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorProp* self = (ActorProp*)  tolua_tousertype(tolua_S,1,0);
  AvatarData* avatar = ((AvatarData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChangeAvatar'", NULL);
#endif
  {
   self->ChangeAvatar(avatar);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChangeAvatar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChangeEquip of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_ChangeEquip00
static int tolua_GameFramework_ActorProp_ChangeEquip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorProp",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ENEquipType::Decl",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorProp* self = (ActorProp*)  tolua_tousertype(tolua_S,1,0);
  ENEquipType::Decl type = *((ENEquipType::Decl*)  tolua_tousertype(tolua_S,2,0));
  const char* avatarFile = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChangeEquip'", NULL);
#endif
  {
   self->ChangeEquip(type,avatarFile);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChangeEquip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SendAttack of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_SendAttack00
static int tolua_GameFramework_ActorProp_SendAttack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorProp",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorProp* self = (ActorProp*)  tolua_tousertype(tolua_S,1,0);
  int targetID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SendAttack'", NULL);
#endif
  {
   self->SendAttack(targetID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SendAttack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeAttacked of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_BeAttacked00
static int tolua_GameFramework_ActorProp_BeAttacked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorProp",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorProp* self = (ActorProp*)  tolua_tousertype(tolua_S,1,0);
  int hpChanged = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeAttacked'", NULL);
#endif
  {
   self->BeAttacked(hpChanged);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeAttacked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AttachUI of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_AttachUI00
static int tolua_GameFramework_ActorProp_AttachUI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorProp",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::UIProperty",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorProp* self = (ActorProp*)  tolua_tousertype(tolua_S,1,0);
  GUI::UIProperty* uiProp = ((GUI::UIProperty*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AttachUI'", NULL);
#endif
  {
   self->AttachUI(uiProp);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AttachUI'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_SetPosition00
static int tolua_GameFramework_ActorProp_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorProp",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorProp* self = (ActorProp*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* pos = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(*pos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Tick of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_Tick00
static int tolua_GameFramework_ActorProp_Tick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorProp",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorProp* self = (ActorProp*)  tolua_tousertype(tolua_S,1,0);
  float dt = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Tick'", NULL);
#endif
  {
   self->Tick(dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Tick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBattleInfo of class  ActorProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorProp_GetBattleInfo00
static int tolua_GameFramework_ActorProp_GetBattleInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ActorProp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ActorProp* self = (const ActorProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBattleInfo'", NULL);
#endif
  {
   ActorBattleInfo* tolua_ret = (ActorBattleInfo*)  self->GetBattleInfo();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ActorBattleInfo");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBattleInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ActorsControl */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorsControl_new00
static int tolua_GameFramework_ActorsControl_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ActorsControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ActorsControl* tolua_ret = (ActorsControl*)  Mtolua_new((ActorsControl)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ActorsControl");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ActorsControl */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorsControl_new00_local
static int tolua_GameFramework_ActorsControl_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ActorsControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ActorsControl* tolua_ret = (ActorsControl*)  Mtolua_new((ActorsControl)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ActorsControl");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  ActorsControl */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorsControl_delete00
static int tolua_GameFramework_ActorsControl_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorsControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorsControl* self = (ActorsControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateActor of class  ActorsControl */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorsControl_CreateActor00
static int tolua_GameFramework_ActorsControl_CreateActor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorsControl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorsControl* self = (ActorsControl*)  tolua_tousertype(tolua_S,1,0);
  ENActorType::Decl type = ((ENActorType::Decl) (int)  tolua_tonumber(tolua_S,2,0));
  int actorID = ((int)  tolua_tonumber(tolua_S,3,0));
  float x = ((float)  tolua_tonumber(tolua_S,4,0));
  float y = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateActor'", NULL);
#endif
  {
   ActorProp* tolua_ret = (ActorProp*)  self->CreateActor(type,actorID,x,y);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ActorProp");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateActor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReleaseActor of class  ActorsControl */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorsControl_ReleaseActor00
static int tolua_GameFramework_ActorsControl_ReleaseActor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorsControl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorsControl* self = (ActorsControl*)  tolua_tousertype(tolua_S,1,0);
  int actorID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReleaseActor'", NULL);
#endif
  {
   self->ReleaseActor(actorID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReleaseActor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearActor of class  ActorsControl */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorsControl_ClearActor00
static int tolua_GameFramework_ActorsControl_ClearActor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorsControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorsControl* self = (ActorsControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearActor'", NULL);
#endif
  {
   self->ClearActor();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearActor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMainActor of class  ActorsControl */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorsControl_GetMainActor00
static int tolua_GameFramework_ActorsControl_GetMainActor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ActorsControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ActorsControl* self = (const ActorsControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMainActor'", NULL);
#endif
  {
   ActorProp* tolua_ret = (ActorProp*)  self->GetMainActor();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ActorProp");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMainActor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LookupActor of class  ActorsControl */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorsControl_LookupActor00
static int tolua_GameFramework_ActorsControl_LookupActor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ActorsControl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ActorsControl* self = (const ActorsControl*)  tolua_tousertype(tolua_S,1,0);
  int actorID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LookupActor'", NULL);
#endif
  {
   ActorProp* tolua_ret = (ActorProp*)  self->LookupActor(actorID);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ActorProp");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LookupActor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Tick of class  ActorsControl */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorsControl_Tick00
static int tolua_GameFramework_ActorsControl_Tick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ActorsControl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ActorsControl* self = (ActorsControl*)  tolua_tousertype(tolua_S,1,0);
  float dt = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Tick'", NULL);
#endif
  {
   self->Tick(dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Tick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Distance of class  ActorsControl */
#ifndef TOLUA_DISABLE_tolua_GameFramework_ActorsControl_Distance00
static int tolua_GameFramework_ActorsControl_Distance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ActorsControl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const ActorProp",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const ActorProp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ActorProp* firstActor = ((const ActorProp*)  tolua_tousertype(tolua_S,2,0));
  const ActorProp* secondActor = ((const ActorProp*)  tolua_tousertype(tolua_S,3,0));
  {
   float tolua_ret = (float)  ActorsControl::Distance(firstActor,secondActor);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Distance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  TerrainProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_TerrainProp_new00
static int tolua_GameFramework_TerrainProp_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TerrainProp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TerrainProp* tolua_ret = (TerrainProp*)  Mtolua_new((TerrainProp)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TerrainProp");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  TerrainProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_TerrainProp_new00_local
static int tolua_GameFramework_TerrainProp_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TerrainProp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TerrainProp* tolua_ret = (TerrainProp*)  Mtolua_new((TerrainProp)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TerrainProp");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  TerrainProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_TerrainProp_delete00
static int tolua_GameFramework_TerrainProp_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TerrainProp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TerrainProp* self = (TerrainProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Init of class  TerrainProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_TerrainProp_Init00
static int tolua_GameFramework_TerrainProp_Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TerrainProp",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TerrainProp* self = (TerrainProp*)  tolua_tousertype(tolua_S,1,0);
  const Scene* sceneFile = ((const Scene*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'", NULL);
#endif
  {
   self->Init(sceneFile);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddTerrainGrid of class  TerrainProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_TerrainProp_AddTerrainGrid00
static int tolua_GameFramework_TerrainProp_AddTerrainGrid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TerrainProp",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TerrainProp* self = (TerrainProp*)  tolua_tousertype(tolua_S,1,0);
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* imageName = ((const char*)  tolua_tostring(tolua_S,3,0));
  float x = ((float)  tolua_tonumber(tolua_S,4,0));
  float y = ((float)  tolua_tonumber(tolua_S,5,0));
  float width = ((float)  tolua_tonumber(tolua_S,6,0));
  float height = ((float)  tolua_tonumber(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddTerrainGrid'", NULL);
#endif
  {
   self->AddTerrainGrid(id,imageName,x,y,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddTerrainGrid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChangeTerrainGrid of class  TerrainProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_TerrainProp_ChangeTerrainGrid00
static int tolua_GameFramework_TerrainProp_ChangeTerrainGrid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TerrainProp",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TerrainProp* self = (TerrainProp*)  tolua_tousertype(tolua_S,1,0);
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* imageName = ((const char*)  tolua_tostring(tolua_S,3,0));
  float x = ((float)  tolua_tonumber(tolua_S,4,0));
  float y = ((float)  tolua_tonumber(tolua_S,5,0));
  float width = ((float)  tolua_tonumber(tolua_S,6,0));
  float height = ((float)  tolua_tonumber(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChangeTerrainGrid'", NULL);
#endif
  {
   self->ChangeTerrainGrid(id,imageName,x,y,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChangeTerrainGrid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveTerrainGrid of class  TerrainProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_TerrainProp_RemoveTerrainGrid00
static int tolua_GameFramework_TerrainProp_RemoveTerrainGrid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TerrainProp",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TerrainProp* self = (TerrainProp*)  tolua_tousertype(tolua_S,1,0);
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveTerrainGrid'", NULL);
#endif
  {
   self->RemoveTerrainGrid(id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveTerrainGrid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LookupGrid of class  TerrainProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_TerrainProp_LookupGrid00
static int tolua_GameFramework_TerrainProp_LookupGrid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TerrainProp",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TerrainProp* self = (TerrainProp*)  tolua_tousertype(tolua_S,1,0);
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LookupGrid'", NULL);
#endif
  {
   GridProp* tolua_ret = (GridProp*)  self->LookupGrid(id);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GridProp");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LookupGrid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  TerrainProp */
#ifndef TOLUA_DISABLE_tolua_GameFramework_TerrainProp_Clear00
static int tolua_GameFramework_TerrainProp_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TerrainProp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TerrainProp* self = (TerrainProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SceneInfo */
#ifndef TOLUA_DISABLE_tolua_GameFramework_SceneInfo_new00
static int tolua_GameFramework_SceneInfo_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SceneInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SceneInfo* tolua_ret = (SceneInfo*)  Mtolua_new((SceneInfo)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneInfo");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SceneInfo */
#ifndef TOLUA_DISABLE_tolua_GameFramework_SceneInfo_new00_local
static int tolua_GameFramework_SceneInfo_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SceneInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SceneInfo* tolua_ret = (SceneInfo*)  Mtolua_new((SceneInfo)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneInfo");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  SceneInfo */
#ifndef TOLUA_DISABLE_tolua_GameFramework_SceneInfo_delete00
static int tolua_GameFramework_SceneInfo_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneInfo* self = (SceneInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Init of class  SceneInfo */
#ifndef TOLUA_DISABLE_tolua_GameFramework_SceneInfo_Init00
static int tolua_GameFramework_SceneInfo_Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneInfo",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneInfo* self = (SceneInfo*)  tolua_tousertype(tolua_S,1,0);
  const Scene* sceneFile = ((const Scene*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'", NULL);
#endif
  {
   self->Init(sceneFile);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGridPass of class  SceneInfo */
#ifndef TOLUA_DISABLE_tolua_GameFramework_SceneInfo_GetGridPass00
static int tolua_GameFramework_SceneInfo_GetGridPass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneInfo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneInfo* self = (SceneInfo*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGridPass'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetGridPass(x,y);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGridPass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsPointCanStanc of class  SceneInfo */
#ifndef TOLUA_DISABLE_tolua_GameFramework_SceneInfo_IsPointCanStanc00
static int tolua_GameFramework_SceneInfo_IsPointCanStanc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneInfo",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneInfo* self = (SceneInfo*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsPointCanStanc'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsPointCanStanc(*point);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsPointCanStanc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWidth of class  SceneInfo */
#ifndef TOLUA_DISABLE_tolua_GameFramework_SceneInfo_GetWidth00
static int tolua_GameFramework_SceneInfo_GetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const SceneInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const SceneInfo* self = (const SceneInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHeight of class  SceneInfo */
#ifndef TOLUA_DISABLE_tolua_GameFramework_SceneInfo_GetHeight00
static int tolua_GameFramework_SceneInfo_GetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const SceneInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const SceneInfo* self = (const SceneInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetColumn of class  SceneInfo */
#ifndef TOLUA_DISABLE_tolua_GameFramework_SceneInfo_GetColumn00
static int tolua_GameFramework_SceneInfo_GetColumn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const SceneInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const SceneInfo* self = (const SceneInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetColumn'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetColumn();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetColumn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRow of class  SceneInfo */
#ifndef TOLUA_DISABLE_tolua_GameFramework_SceneInfo_GetRow00
static int tolua_GameFramework_SceneInfo_GetRow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const SceneInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const SceneInfo* self = (const SceneInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRow'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetRow();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGridSize of class  SceneInfo */
#ifndef TOLUA_DISABLE_tolua_GameFramework_SceneInfo_GetGridSize00
static int tolua_GameFramework_SceneInfo_GetGridSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const SceneInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const SceneInfo* self = (const SceneInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGridSize'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetGridSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGridSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGridArrayLength of class  SceneInfo */
#ifndef TOLUA_DISABLE_tolua_GameFramework_SceneInfo_GetGridArrayLength00
static int tolua_GameFramework_SceneInfo_GetGridArrayLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const SceneInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const SceneInfo* self = (const SceneInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGridArrayLength'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetGridArrayLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGridArrayLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSceneName of class  SceneInfo */
#ifndef TOLUA_DISABLE_tolua_GameFramework_SceneInfo_GetSceneName00
static int tolua_GameFramework_SceneInfo_GetSceneName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const SceneInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const SceneInfo* self = (const SceneInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSceneName'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetSceneName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSceneName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSceneName of class  SceneInfo */
#ifndef TOLUA_DISABLE_tolua_GameFramework_SceneInfo_SetSceneName00
static int tolua_GameFramework_SceneInfo_SetSceneName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneInfo",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneInfo* self = (SceneInfo*)  tolua_tousertype(tolua_S,1,0);
  const std::string val = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSceneName'", NULL);
#endif
  {
   self->SetSceneName(val);
   tolua_pushcppstring(tolua_S,(const char*)val);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSceneName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetGridPass of class  SceneInfo */
#ifndef TOLUA_DISABLE_tolua_GameFramework_SceneInfo_SetGridPass00
static int tolua_GameFramework_SceneInfo_SetGridPass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneInfo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneInfo* self = (SceneInfo*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  bool isPass = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetGridPass'", NULL);
#endif
  {
   self->SetGridPass(x,y,isPass);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetGridPass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCollidable of class  SceneInfo */
#ifndef TOLUA_DISABLE_tolua_GameFramework_SceneInfo_SetCollidable00
static int tolua_GameFramework_SceneInfo_SetCollidable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneInfo",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneInfo* self = (SceneInfo*)  tolua_tousertype(tolua_S,1,0);
  bool isCollide = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCollidable'", NULL);
#endif
  {
   self->SetCollidable(isCollide);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCollidable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_GameFramework_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"WorldManager","WorldManager","",NULL);
  tolua_beginmodule(tolua_S,"WorldManager");
   tolua_function(tolua_S,"Instance",tolua_GameFramework_WorldManager_Instance00);
   tolua_function(tolua_S,"ClearUp",tolua_GameFramework_WorldManager_ClearUp00);
   tolua_function(tolua_S,"Init",tolua_GameFramework_WorldManager_Init00);
   tolua_function(tolua_S,"InitSceneByFile",tolua_GameFramework_WorldManager_InitSceneByFile00);
   tolua_function(tolua_S,"InitScene",tolua_GameFramework_WorldManager_InitScene00);
   tolua_function(tolua_S,"GetSceneInfo",tolua_GameFramework_WorldManager_GetSceneInfo00);
   tolua_function(tolua_S,"GetActorsControl",tolua_GameFramework_WorldManager_GetActorsControl00);
   tolua_function(tolua_S,"GetTerrainProp",tolua_GameFramework_WorldManager_GetTerrainProp00);
   tolua_function(tolua_S,"GetSceneObjectsControl",tolua_GameFramework_WorldManager_GetSceneObjectsControl00);
   tolua_function(tolua_S,"GetCamera",tolua_GameFramework_WorldManager_GetCamera00);
   tolua_function(tolua_S,"GetUIControl",tolua_GameFramework_WorldManager_GetUIControl00);
   tolua_function(tolua_S,"GetPhysicalControl",tolua_GameFramework_WorldManager_GetPhysicalControl00);
   tolua_function(tolua_S,"GetRoot",tolua_GameFramework_WorldManager_GetRoot00);
   tolua_function(tolua_S,"WorldPosToDesign",tolua_GameFramework_WorldManager_WorldPosToDesign00);
   tolua_function(tolua_S,"DesignPosToWorld",tolua_GameFramework_WorldManager_DesignPosToWorld00);
   tolua_function(tolua_S,"LogicToPoint",tolua_GameFramework_WorldManager_LogicToPoint00);
   tolua_function(tolua_S,"PointToLogic",tolua_GameFramework_WorldManager_PointToLogic00);
   tolua_function(tolua_S,"LogicToPoint",tolua_GameFramework_WorldManager_LogicToPoint01);
   tolua_function(tolua_S,"PointToLogic",tolua_GameFramework_WorldManager_PointToLogic01);
   tolua_function(tolua_S,"LogicToPoint",tolua_GameFramework_WorldManager_LogicToPoint02);
   tolua_function(tolua_S,"PointToLogic",tolua_GameFramework_WorldManager_PointToLogic02);
   tolua_function(tolua_S,"update",tolua_GameFramework_WorldManager_update00);
   tolua_function(tolua_S,"SetCollidable",tolua_GameFramework_WorldManager_SetCollidable00);
   tolua_function(tolua_S,"GetClient",tolua_GameFramework_WorldManager_GetClient00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CSPipeline","CSPipeline","",NULL);
  tolua_beginmodule(tolua_S,"CSPipeline");
   tolua_function(tolua_S,"Instance",tolua_GameFramework_CSPipeline_Instance00);
   tolua_function(tolua_S,"Init",tolua_GameFramework_CSPipeline_Init00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"ActorProp","ActorProp","INotifier",tolua_collect_ActorProp);
  #else
  tolua_cclass(tolua_S,"ActorProp","ActorProp","INotifier",NULL);
  #endif
  tolua_beginmodule(tolua_S,"ActorProp");
   tolua_function(tolua_S,"new",tolua_GameFramework_ActorProp_new00);
   tolua_function(tolua_S,"new_local",tolua_GameFramework_ActorProp_new00_local);
   tolua_function(tolua_S,".call",tolua_GameFramework_ActorProp_new00_local);
   tolua_function(tolua_S,"delete",tolua_GameFramework_ActorProp_delete00);
   tolua_function(tolua_S,"GetID",tolua_GameFramework_ActorProp_GetID00);
   tolua_function(tolua_S,"GetActorType",tolua_GameFramework_ActorProp_GetActorType00);
   tolua_function(tolua_S,"GetPosition",tolua_GameFramework_ActorProp_GetPosition00);
   tolua_function(tolua_S,"GetSpeed",tolua_GameFramework_ActorProp_GetSpeed00);
   tolua_function(tolua_S,"Init",tolua_GameFramework_ActorProp_Init00);
   tolua_function(tolua_S,"Release",tolua_GameFramework_ActorProp_Release00);
   tolua_function(tolua_S,"MoveTo",tolua_GameFramework_ActorProp_MoveTo00);
   tolua_function(tolua_S,"Stop",tolua_GameFramework_ActorProp_Stop00);
   tolua_function(tolua_S,"Dead",tolua_GameFramework_ActorProp_Dead00);
   tolua_function(tolua_S,"StartAttack",tolua_GameFramework_ActorProp_StartAttack00);
   tolua_function(tolua_S,"ChangeAvatar",tolua_GameFramework_ActorProp_ChangeAvatar00);
   tolua_function(tolua_S,"ChangeEquip",tolua_GameFramework_ActorProp_ChangeEquip00);
   tolua_function(tolua_S,"SendAttack",tolua_GameFramework_ActorProp_SendAttack00);
   tolua_function(tolua_S,"BeAttacked",tolua_GameFramework_ActorProp_BeAttacked00);
   tolua_function(tolua_S,"AttachUI",tolua_GameFramework_ActorProp_AttachUI00);
   tolua_function(tolua_S,"SetPosition",tolua_GameFramework_ActorProp_SetPosition00);
   tolua_function(tolua_S,"Tick",tolua_GameFramework_ActorProp_Tick00);
   tolua_function(tolua_S,"GetBattleInfo",tolua_GameFramework_ActorProp_GetBattleInfo00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ENActorType","ENActorType","",NULL);
  tolua_beginmodule(tolua_S,"ENActorType");
   tolua_constant(tolua_S,"enNone",ENActorType::enNone);
   tolua_constant(tolua_S,"enMain",ENActorType::enMain);
   tolua_constant(tolua_S,"enMonster",ENActorType::enMonster);
   tolua_constant(tolua_S,"enNpc",ENActorType::enNpc);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"ActorsControl","ActorsControl","INotifier",tolua_collect_ActorsControl);
  #else
  tolua_cclass(tolua_S,"ActorsControl","ActorsControl","INotifier",NULL);
  #endif
  tolua_beginmodule(tolua_S,"ActorsControl");
   tolua_function(tolua_S,"new",tolua_GameFramework_ActorsControl_new00);
   tolua_function(tolua_S,"new_local",tolua_GameFramework_ActorsControl_new00_local);
   tolua_function(tolua_S,".call",tolua_GameFramework_ActorsControl_new00_local);
   tolua_function(tolua_S,"delete",tolua_GameFramework_ActorsControl_delete00);
   tolua_function(tolua_S,"CreateActor",tolua_GameFramework_ActorsControl_CreateActor00);
   tolua_function(tolua_S,"ReleaseActor",tolua_GameFramework_ActorsControl_ReleaseActor00);
   tolua_function(tolua_S,"ClearActor",tolua_GameFramework_ActorsControl_ClearActor00);
   tolua_function(tolua_S,"GetMainActor",tolua_GameFramework_ActorsControl_GetMainActor00);
   tolua_function(tolua_S,"LookupActor",tolua_GameFramework_ActorsControl_LookupActor00);
   tolua_function(tolua_S,"Tick",tolua_GameFramework_ActorsControl_Tick00);
   tolua_function(tolua_S,"Distance",tolua_GameFramework_ActorsControl_Distance00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"TerrainProp","TerrainProp","INotifier",tolua_collect_TerrainProp);
  #else
  tolua_cclass(tolua_S,"TerrainProp","TerrainProp","INotifier",NULL);
  #endif
  tolua_beginmodule(tolua_S,"TerrainProp");
   tolua_function(tolua_S,"new",tolua_GameFramework_TerrainProp_new00);
   tolua_function(tolua_S,"new_local",tolua_GameFramework_TerrainProp_new00_local);
   tolua_function(tolua_S,".call",tolua_GameFramework_TerrainProp_new00_local);
   tolua_function(tolua_S,"delete",tolua_GameFramework_TerrainProp_delete00);
   tolua_function(tolua_S,"Init",tolua_GameFramework_TerrainProp_Init00);
   tolua_function(tolua_S,"AddTerrainGrid",tolua_GameFramework_TerrainProp_AddTerrainGrid00);
   tolua_function(tolua_S,"ChangeTerrainGrid",tolua_GameFramework_TerrainProp_ChangeTerrainGrid00);
   tolua_function(tolua_S,"RemoveTerrainGrid",tolua_GameFramework_TerrainProp_RemoveTerrainGrid00);
   tolua_function(tolua_S,"LookupGrid",tolua_GameFramework_TerrainProp_LookupGrid00);
   tolua_function(tolua_S,"Clear",tolua_GameFramework_TerrainProp_Clear00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"SceneInfo","SceneInfo","",tolua_collect_SceneInfo);
  #else
  tolua_cclass(tolua_S,"SceneInfo","SceneInfo","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"SceneInfo");
   tolua_function(tolua_S,"new",tolua_GameFramework_SceneInfo_new00);
   tolua_function(tolua_S,"new_local",tolua_GameFramework_SceneInfo_new00_local);
   tolua_function(tolua_S,".call",tolua_GameFramework_SceneInfo_new00_local);
   tolua_function(tolua_S,"delete",tolua_GameFramework_SceneInfo_delete00);
   tolua_function(tolua_S,"Init",tolua_GameFramework_SceneInfo_Init00);
   tolua_function(tolua_S,"GetGridPass",tolua_GameFramework_SceneInfo_GetGridPass00);
   tolua_function(tolua_S,"IsPointCanStanc",tolua_GameFramework_SceneInfo_IsPointCanStanc00);
   tolua_function(tolua_S,"GetWidth",tolua_GameFramework_SceneInfo_GetWidth00);
   tolua_function(tolua_S,"GetHeight",tolua_GameFramework_SceneInfo_GetHeight00);
   tolua_function(tolua_S,"GetColumn",tolua_GameFramework_SceneInfo_GetColumn00);
   tolua_function(tolua_S,"GetRow",tolua_GameFramework_SceneInfo_GetRow00);
   tolua_function(tolua_S,"GetGridSize",tolua_GameFramework_SceneInfo_GetGridSize00);
   tolua_function(tolua_S,"GetGridArrayLength",tolua_GameFramework_SceneInfo_GetGridArrayLength00);
   tolua_function(tolua_S,"GetSceneName",tolua_GameFramework_SceneInfo_GetSceneName00);
   tolua_function(tolua_S,"SetSceneName",tolua_GameFramework_SceneInfo_SetSceneName00);
   tolua_function(tolua_S,"SetGridPass",tolua_GameFramework_SceneInfo_SetGridPass00);
   tolua_function(tolua_S,"SetCollidable",tolua_GameFramework_SceneInfo_SetCollidable00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_GameFramework (lua_State* tolua_S) {
 return tolua_GameFramework_open(tolua_S);
};
#endif

