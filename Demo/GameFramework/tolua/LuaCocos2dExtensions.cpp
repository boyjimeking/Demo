/*
** Lua binding: Cocos2dExtensions
** Generated automatically by tolua++-1.0.92 on 01/14/13 16:31:53.
*/





#include "CCLuaEngine.h"
#include "tolua_fix.h"
#include "GUI/CCControlExtension/CCControlExtensions.h"
using namespace cocos2d;
using namespace cocos2d::extension;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_CCPoint (lua_State* tolua_S)
{
 CCPoint* self = (CCPoint*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CCControl (lua_State* tolua_S)
{
 CCControl* self = (CCControl*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CCControlSlider (lua_State* tolua_S)
{
 CCControlSlider* self = (CCControlSlider*) tolua_tousertype(tolua_S,1,0);
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
 tolua_usertype(tolua_S,"CCLayer");
 Mtolua_typeid(tolua_S,CCLayer, "CCLayer");
 tolua_usertype(tolua_S,"SEL_CCControlHandler");
 Mtolua_typeid(tolua_S,SEL_CCControlHandler, "SEL_CCControlHandler");
 tolua_usertype(tolua_S,"CCControl");
 Mtolua_typeid(tolua_S,CCControl, "CCControl");
 tolua_usertype(tolua_S,"CCControlEvent");
 Mtolua_typeid(tolua_S,CCControlEvent, "CCControlEvent");
 tolua_usertype(tolua_S,"CCControlSlider");
 Mtolua_typeid(tolua_S,CCControlSlider, "CCControlSlider");
 tolua_usertype(tolua_S,"CCSprite");
 Mtolua_typeid(tolua_S,CCSprite, "CCSprite");
 tolua_usertype(tolua_S,"CCRGBAProtocol");
 Mtolua_typeid(tolua_S,CCRGBAProtocol, "CCRGBAProtocol");
 tolua_usertype(tolua_S,"CCObject");
 Mtolua_typeid(tolua_S,CCObject, "CCObject");
 tolua_usertype(tolua_S,"CCTouch");
 Mtolua_typeid(tolua_S,CCTouch, "CCTouch");
}

/* get function: m_bIsOpacityModifyRGB of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_get_CCControl_m_bIsOpacityModifyRGB
static int tolua_get_CCControl_m_bIsOpacityModifyRGB(lua_State* tolua_S)
{
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_bIsOpacityModifyRGB'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->m_bIsOpacityModifyRGB);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_bIsOpacityModifyRGB of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_set_CCControl_m_bIsOpacityModifyRGB
static int tolua_set_CCControl_m_bIsOpacityModifyRGB(lua_State* tolua_S)
{
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_bIsOpacityModifyRGB'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_bIsOpacityModifyRGB = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: isOpacityModifyRGB of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_isOpacityModifyRGB00
static int tolua_Cocos2dExtensions_CCControl_isOpacityModifyRGB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isOpacityModifyRGB'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isOpacityModifyRGB();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isOpacityModifyRGB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOpacityModifyRGB of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_setOpacityModifyRGB00
static int tolua_Cocos2dExtensions_CCControl_setOpacityModifyRGB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
  bool bOpacityModifyRGB = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOpacityModifyRGB'", NULL);
#endif
  {
   self->setOpacityModifyRGB(bOpacityModifyRGB);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOpacityModifyRGB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEnabled of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_setEnabled00
static int tolua_Cocos2dExtensions_CCControl_setEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
  bool bEnabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEnabled'", NULL);
#endif
  {
   self->setEnabled(bEnabled);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isEnabled of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_isEnabled00
static int tolua_Cocos2dExtensions_CCControl_isEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isEnabled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSelected of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_setSelected00
static int tolua_Cocos2dExtensions_CCControl_setSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
  bool bSelected = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSelected'", NULL);
#endif
  {
   self->setSelected(bSelected);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isSelected of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_isSelected00
static int tolua_Cocos2dExtensions_CCControl_isSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isSelected'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isSelected();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHighlighted of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_setHighlighted00
static int tolua_Cocos2dExtensions_CCControl_setHighlighted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
  bool bHighlighted = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHighlighted'", NULL);
#endif
  {
   self->setHighlighted(bHighlighted);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHighlighted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isHighlighted of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_isHighlighted00
static int tolua_Cocos2dExtensions_CCControl_isHighlighted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isHighlighted'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isHighlighted();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isHighlighted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasVisibleParents of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_hasVisibleParents00
static int tolua_Cocos2dExtensions_CCControl_hasVisibleParents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasVisibleParents'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasVisibleParents();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasVisibleParents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: needsLayout of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_needsLayout00
static int tolua_Cocos2dExtensions_CCControl_needsLayout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'needsLayout'", NULL);
#endif
  {
   self->needsLayout();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'needsLayout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_new00
static int tolua_Cocos2dExtensions_CCControl_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCControl* tolua_ret = (CCControl*)  Mtolua_new((CCControl)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCControl");
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

/* method: new_local of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_new00_local
static int tolua_Cocos2dExtensions_CCControl_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCControl* tolua_ret = (CCControl*)  Mtolua_new((CCControl)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCControl");
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

/* method: init of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_init00
static int tolua_Cocos2dExtensions_CCControl_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_delete00
static int tolua_Cocos2dExtensions_CCControl_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
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

/* method: onEnter of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_onEnter00
static int tolua_Cocos2dExtensions_CCControl_onEnter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onEnter'", NULL);
#endif
  {
   self->onEnter();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onEnter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onExit of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_onExit00
static int tolua_Cocos2dExtensions_CCControl_onExit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onExit'", NULL);
#endif
  {
   self->onExit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onExit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerWithTouchDispatcher of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_registerWithTouchDispatcher00
static int tolua_Cocos2dExtensions_CCControl_registerWithTouchDispatcher00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerWithTouchDispatcher'", NULL);
#endif
  {
   self->registerWithTouchDispatcher();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerWithTouchDispatcher'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendActionsForControlEvents of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_sendActionsForControlEvents00
static int tolua_Cocos2dExtensions_CCControl_sendActionsForControlEvents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCControlEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
  CCControlEvent controlEvents = *((CCControlEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendActionsForControlEvents'", NULL);
#endif
  {
   self->sendActionsForControlEvents(controlEvents);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendActionsForControlEvents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addTargetWithActionForControlEvents of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_addTargetWithActionForControlEvents00
static int tolua_Cocos2dExtensions_CCControl_addTargetWithActionForControlEvents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"SEL_CCControlHandler",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CCControlEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
  CCObject* target = ((CCObject*)  tolua_tousertype(tolua_S,2,0));
  SEL_CCControlHandler action = *((SEL_CCControlHandler*)  tolua_tousertype(tolua_S,3,0));
  CCControlEvent controlEvents = *((CCControlEvent*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addTargetWithActionForControlEvents'", NULL);
#endif
  {
   self->addTargetWithActionForControlEvents(target,action,controlEvents);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addTargetWithActionForControlEvents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeTargetWithActionForControlEvents of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_removeTargetWithActionForControlEvents00
static int tolua_Cocos2dExtensions_CCControl_removeTargetWithActionForControlEvents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"SEL_CCControlHandler",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CCControlEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
  CCObject* target = ((CCObject*)  tolua_tousertype(tolua_S,2,0));
  SEL_CCControlHandler action = *((SEL_CCControlHandler*)  tolua_tousertype(tolua_S,3,0));
  CCControlEvent controlEvents = *((CCControlEvent*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeTargetWithActionForControlEvents'", NULL);
#endif
  {
   self->removeTargetWithActionForControlEvents(target,action,controlEvents);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeTargetWithActionForControlEvents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTouchLocation of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_getTouchLocation00
static int tolua_Cocos2dExtensions_CCControl_getTouchLocation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTouchLocation'", NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->getTouchLocation(touch);
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
 tolua_error(tolua_S,"#ferror in function 'getTouchLocation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isTouchInside of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControl_isTouchInside00
static int tolua_Cocos2dExtensions_CCControl_isTouchInside00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isTouchInside'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isTouchInside(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isTouchInside'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __CCRGBAProtocol__ of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_get_CCControl___CCRGBAProtocol__
static int tolua_get_CCControl___CCRGBAProtocol__(lua_State* tolua_S)
{
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__CCRGBAProtocol__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<CCRGBAProtocol*>(self), "CCRGBAProtocol");
#else
   tolua_pushusertype(tolua_S,(void*)((CCRGBAProtocol*)self), "CCRGBAProtocol");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setValue of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControlSlider_setValue00
static int tolua_Cocos2dExtensions_CCControlSlider_setValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  float val = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setValue'", NULL);
#endif
  {
   self->setValue(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMinimumValue of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControlSlider_setMinimumValue00
static int tolua_Cocos2dExtensions_CCControlSlider_setMinimumValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  float val = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMinimumValue'", NULL);
#endif
  {
   self->setMinimumValue(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMinimumValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaximumValue of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControlSlider_setMaximumValue00
static int tolua_Cocos2dExtensions_CCControlSlider_setMaximumValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  float val = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaximumValue'", NULL);
#endif
  {
   self->setMaximumValue(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaximumValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEnabled of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControlSlider_setEnabled00
static int tolua_Cocos2dExtensions_CCControlSlider_setEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEnabled'", NULL);
#endif
  {
   self->setEnabled(enabled);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isTouchInside of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControlSlider_isTouchInside00
static int tolua_Cocos2dExtensions_CCControlSlider_isTouchInside00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isTouchInside'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isTouchInside(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isTouchInside'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: locationFromTouch of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControlSlider_locationFromTouch00
static int tolua_Cocos2dExtensions_CCControlSlider_locationFromTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'locationFromTouch'", NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->locationFromTouch(touch);
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
 tolua_error(tolua_S,"#ferror in function 'locationFromTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControlSlider_new00
static int tolua_Cocos2dExtensions_CCControlSlider_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCControlSlider* tolua_ret = (CCControlSlider*)  Mtolua_new((CCControlSlider)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCControlSlider");
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

/* method: new_local of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControlSlider_new00_local
static int tolua_Cocos2dExtensions_CCControlSlider_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCControlSlider* tolua_ret = (CCControlSlider*)  Mtolua_new((CCControlSlider)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCControlSlider");
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

/* method: delete of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControlSlider_delete00
static int tolua_Cocos2dExtensions_CCControlSlider_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
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

/* method: initWithSprites of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControlSlider_initWithSprites00
static int tolua_Cocos2dExtensions_CCControlSlider_initWithSprites00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"CCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  CCSprite* backgroundSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0));
  CCSprite* progressSprite = ((CCSprite*)  tolua_tousertype(tolua_S,3,0));
  CCSprite* thumbSprite = ((CCSprite*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithSprites'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithSprites(backgroundSprite,progressSprite,thumbSprite);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithSprites'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControlSlider_create00
static int tolua_Cocos2dExtensions_CCControlSlider_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* bgFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* progressFile = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* thumbFile = ((const char*)  tolua_tostring(tolua_S,4,0));
  {
   CCControlSlider* tolua_ret = (CCControlSlider*)  CCControlSlider::create(bgFile,progressFile,thumbFile);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCControlSlider");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControlSlider_create01
static int tolua_Cocos2dExtensions_CCControlSlider_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"CCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCSprite* backgroundSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0));
  CCSprite* pogressSprite = ((CCSprite*)  tolua_tousertype(tolua_S,3,0));
  CCSprite* thumbSprite = ((CCSprite*)  tolua_tousertype(tolua_S,4,0));
  {
   CCControlSlider* tolua_ret = (CCControlSlider*)  CCControlSlider::create(backgroundSprite,pogressSprite,thumbSprite);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCControlSlider");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Cocos2dExtensions_CCControlSlider_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: needsLayout of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2dExtensions_CCControlSlider_needsLayout00
static int tolua_Cocos2dExtensions_CCControlSlider_needsLayout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'needsLayout'", NULL);
#endif
  {
   self->needsLayout();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'needsLayout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Cocos2dExtensions_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCControl","CCControl","CCLayer",tolua_collect_CCControl);
  #else
  tolua_cclass(tolua_S,"CCControl","CCControl","CCLayer",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCControl");
   tolua_variable(tolua_S,"m_bIsOpacityModifyRGB",tolua_get_CCControl_m_bIsOpacityModifyRGB,tolua_set_CCControl_m_bIsOpacityModifyRGB);
   tolua_function(tolua_S,"isOpacityModifyRGB",tolua_Cocos2dExtensions_CCControl_isOpacityModifyRGB00);
   tolua_function(tolua_S,"setOpacityModifyRGB",tolua_Cocos2dExtensions_CCControl_setOpacityModifyRGB00);
   tolua_function(tolua_S,"setEnabled",tolua_Cocos2dExtensions_CCControl_setEnabled00);
   tolua_function(tolua_S,"isEnabled",tolua_Cocos2dExtensions_CCControl_isEnabled00);
   tolua_function(tolua_S,"setSelected",tolua_Cocos2dExtensions_CCControl_setSelected00);
   tolua_function(tolua_S,"isSelected",tolua_Cocos2dExtensions_CCControl_isSelected00);
   tolua_function(tolua_S,"setHighlighted",tolua_Cocos2dExtensions_CCControl_setHighlighted00);
   tolua_function(tolua_S,"isHighlighted",tolua_Cocos2dExtensions_CCControl_isHighlighted00);
   tolua_function(tolua_S,"hasVisibleParents",tolua_Cocos2dExtensions_CCControl_hasVisibleParents00);
   tolua_function(tolua_S,"needsLayout",tolua_Cocos2dExtensions_CCControl_needsLayout00);
   tolua_function(tolua_S,"new",tolua_Cocos2dExtensions_CCControl_new00);
   tolua_function(tolua_S,"new_local",tolua_Cocos2dExtensions_CCControl_new00_local);
   tolua_function(tolua_S,".call",tolua_Cocos2dExtensions_CCControl_new00_local);
   tolua_function(tolua_S,"init",tolua_Cocos2dExtensions_CCControl_init00);
   tolua_function(tolua_S,"delete",tolua_Cocos2dExtensions_CCControl_delete00);
   tolua_function(tolua_S,"onEnter",tolua_Cocos2dExtensions_CCControl_onEnter00);
   tolua_function(tolua_S,"onExit",tolua_Cocos2dExtensions_CCControl_onExit00);
   tolua_function(tolua_S,"registerWithTouchDispatcher",tolua_Cocos2dExtensions_CCControl_registerWithTouchDispatcher00);
   tolua_function(tolua_S,"sendActionsForControlEvents",tolua_Cocos2dExtensions_CCControl_sendActionsForControlEvents00);
   tolua_function(tolua_S,"addTargetWithActionForControlEvents",tolua_Cocos2dExtensions_CCControl_addTargetWithActionForControlEvents00);
   tolua_function(tolua_S,"removeTargetWithActionForControlEvents",tolua_Cocos2dExtensions_CCControl_removeTargetWithActionForControlEvents00);
   tolua_function(tolua_S,"getTouchLocation",tolua_Cocos2dExtensions_CCControl_getTouchLocation00);
   tolua_function(tolua_S,"isTouchInside",tolua_Cocos2dExtensions_CCControl_isTouchInside00);
   tolua_variable(tolua_S,"__CCRGBAProtocol__",tolua_get_CCControl___CCRGBAProtocol__,NULL);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCControlSlider","CCControlSlider","CCControl",tolua_collect_CCControlSlider);
  #else
  tolua_cclass(tolua_S,"CCControlSlider","CCControlSlider","CCControl",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCControlSlider");
   tolua_function(tolua_S,"setValue",tolua_Cocos2dExtensions_CCControlSlider_setValue00);
   tolua_function(tolua_S,"setMinimumValue",tolua_Cocos2dExtensions_CCControlSlider_setMinimumValue00);
   tolua_function(tolua_S,"setMaximumValue",tolua_Cocos2dExtensions_CCControlSlider_setMaximumValue00);
   tolua_function(tolua_S,"setEnabled",tolua_Cocos2dExtensions_CCControlSlider_setEnabled00);
   tolua_function(tolua_S,"isTouchInside",tolua_Cocos2dExtensions_CCControlSlider_isTouchInside00);
   tolua_function(tolua_S,"locationFromTouch",tolua_Cocos2dExtensions_CCControlSlider_locationFromTouch00);
   tolua_function(tolua_S,"new",tolua_Cocos2dExtensions_CCControlSlider_new00);
   tolua_function(tolua_S,"new_local",tolua_Cocos2dExtensions_CCControlSlider_new00_local);
   tolua_function(tolua_S,".call",tolua_Cocos2dExtensions_CCControlSlider_new00_local);
   tolua_function(tolua_S,"delete",tolua_Cocos2dExtensions_CCControlSlider_delete00);
   tolua_function(tolua_S,"initWithSprites",tolua_Cocos2dExtensions_CCControlSlider_initWithSprites00);
   tolua_function(tolua_S,"create",tolua_Cocos2dExtensions_CCControlSlider_create00);
   tolua_function(tolua_S,"create",tolua_Cocos2dExtensions_CCControlSlider_create01);
   tolua_function(tolua_S,"needsLayout",tolua_Cocos2dExtensions_CCControlSlider_needsLayout00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Cocos2dExtensions (lua_State* tolua_S) {
 return tolua_Cocos2dExtensions_open(tolua_S);
};
#endif

