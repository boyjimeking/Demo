require "tools"

function __G__TRACKBACK__(msg)
    cclog("----------------------------------------")
    cclog("LUA ERROR: " .. tostring(msg) .. "\n")
    cclog(debug.traceback())
    cclog("----------------------------------------")
end

local function main()
    local sceneGame = WorldManager:Instance():Init()
    CCDirector:sharedDirector():runWithScene(sceneGame)
    CSPipeline:Instance():Init();

    require "LoadTerrain"
    LoadTerrain()

    require "UIControl"
    local mainUI = LoadUI()
    sceneGame:addChild(mainUI)
end

xpcall(main, __G__TRACKBACK__)
