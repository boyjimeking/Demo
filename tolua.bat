cd Demo/GameFramework/tolua
"../../tolua.exe" -t -D -L basic.lua -o LuaGameFramework.cpp GameFramework.pkg 
"../../ReplaceToLua.exe" ./LuaGameFramework.cpp
pause