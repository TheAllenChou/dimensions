@echo off
cd ..

"%VSINSTALLDIR%/../Common7/IDE/devenv.com" "sln/dimensions.sln" /build "Ship"

cd bat
@echo on
