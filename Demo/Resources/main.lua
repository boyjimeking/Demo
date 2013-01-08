function __G__TRACKBACK__(msg)
    print("----------------------------------------")
    print("LUA ERROR: " .. tostring(msg) .. "\n")
    print(debug.traceback())
    print("----------------------------------------")
end

local function main()
    local cclog = function(...)
        CCLuaLog(string.format(...))
    end

    local sceneGame = WorldManager:Instance():Init()
    CCDirector:sharedDirector():runWithScene(sceneGame)
    CSPipeline:Instance():Init();

    require "LoadTerrain"
    LoadTerrain()

    -- local actorControl = WorldManager:Instance():GetActorsControl()
    -- actorControl:CreateActor(ENActorType.enMonster, 10000, 21.8, 10.9)

    local function UIFunc()
        cclog("UIFunc")
    end
    local uiControl = WorldManager:Instance():GetUIControl();
    cclog("get");
    if nil == uiControl then
        cclog("fail")
    else
        cclog("???")
    end
    uiControl:registerScriptTouchHandler(UIFunc, false, 0, false)
    cclog("success")
end

xpcall(main, __G__TRACKBACK__)
