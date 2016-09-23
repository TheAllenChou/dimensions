@echo off
cd ..

"%VSINSTALLDIR%/../Common7/IDE/devenv.com" "sln/dimensions.sln" /build "Release"

cd bat
@echo on
