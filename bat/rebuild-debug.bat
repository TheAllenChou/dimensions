@echo off
cd ..

"%VSINSTALLDIR%/../Common7/IDE/devenv.com" "sln/dimensions.sln" /rebuild "Debug"

cd bat
@echo on
