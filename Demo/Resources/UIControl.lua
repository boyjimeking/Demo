require "tools"

local function OnTouch(eventType, x, y)
	local mainActor = WorldManager:Instance():GetActorsControl():GetMainActor()
	local pos = CCPointMake(x, y)
	local worldPos = WorldManager:DesignPosToWorld(pos)
	mainActor:MoveTo(worldPos)
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
	-- local targetState = require "UITargetState"
	-- uiLayer:addChild(targetState)



	-- 
	cclog("LoadUI")
	return uiLayer
end