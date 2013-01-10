cd Demo/GameFramework/tolua
"../../tolua.exe" -t -D -L basic.lua -o LuaGameFramework.cpp GameFramework.pkg 
"../../ReplaceToLua.exe" LuaGameFramework.cpp GameFramework

"../../tolua.exe" -t -D -L basic.lua -o LuaCocos2dExtensions.cpp -H LuaCocos2dExtensions.h Cocos2dExtensions.pkg 
"../../ReplaceToLua.exe" LuaCocos2dExtensions.cpp Cocos2dExtensions
pause