require "tools"
require "UITargetState"

-- 是否点击到窗口
local function OnTouchWindow(x, y)
	-- cclog("TouchWindow")
	return false
end
-- 是否点击到角色
local function OnTouchPlayer(x, y)
	local pos = CCPointMake(x, y)
	local worldPos = WorldManager:DesignPosToWorld(pos)
	local actor = WorldManager:Instance():GetActorsControl():LookupActorByPos(worldPos)
	if nil ~= actor then
		local mainActor = WorldManager:Instance():GetActorsControl():GetMainActor()
		if actor == mainActor then
			return false
		end

		require "ActorAttack"
		Attack(actor)

		cclog("TouchPlayer")
		return true
	else
		return false
	end
end
-- 是否点击到建筑
local function OnTouchBuilding(x, y)
	-- cclog("TouchBuilding")
	return false
end
-- 以上都没点击到的时候响应点击地面
local function OnTouchGround(x, y)
	cclog("TouchGround")
	local mainActor = WorldManager:Instance():GetActorsControl():GetMainActor()
	local pos = CCPointMake(x, y)
	local worldPos = WorldManager:DesignPosToWorld(pos)
	require "ActorMove"
	Move(mainActor, worldPos)
	-- mainActor:MoveTo(worldPos)
	return true
end

-- 响应点击事件
local function OnTouch(eventType, x, y)
	if OnTouchWindow(x, y) then return end
	if OnTouchPlayer(x, y) then return end
	if OnTouchBuilding(x, y) then return end
	if OnTouchGround(x, y) then return end
end

local function CreateLayer()
	local uiLayer = CCLayer:create()
	uiLayer:setTouchEnabled(true)
	uiLayer:registerScriptTouchHandler(OnTouch, false, 0, true)
	cclog("CreateLayer")
	return uiLayer
end

function LoadUI()
	local uiLayer = CreateLayer()
	-- UITargetState
	uiLayer:addChild(UITargetState.Load())



	-- 加载成功
	cclog("LoadUI")
	return uiLayer
end