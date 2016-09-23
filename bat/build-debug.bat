@echo off
cd ..

"%VSINSTALLDIR%/../Common7/IDE/devenv.com" "sln/dimensions.sln" /build "Debug"

cd bat
@echo on
