@echo off
cd ..

"%VSINSTALLDIR%/../Common7/IDE/devenv.com" "sln/dimensions.sln" /rebuild "Release"

cd bat
@echo on
