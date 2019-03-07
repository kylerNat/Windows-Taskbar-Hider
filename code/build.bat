@echo off

mkdir "../build"
pushd "../build"

del "Taskbar Hider.exe"
REM clang -g -o "Taskbar Hider.exe" -D DEBUG ../code/"main.cpp"
rem cl -MT -Zi -Od -Oi -nologo /Fe"Taskbar Hider.exe" /DDEBUG "../code/main.cpp" User32.lib Gdi32.lib
cl -MT -Zi -Ox -Oi -nologo /Fe"Taskbar Hider.exe" "../code/main.cpp" User32.lib

"Taskbar Hider.exe"
popd
