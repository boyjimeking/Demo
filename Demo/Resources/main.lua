require "tools"

function __G__TRACKBACK__(msg)
    print("----------------------------------------")
    print("LUA ERROR: " .. tostring(msg) .. "\n")
    print(debug.traceback())
    print("----------------------------------------")
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
