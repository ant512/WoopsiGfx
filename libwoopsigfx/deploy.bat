@echo off

rmdir C:\devkitpro\libwoopsigfx /s /q
mkdir C:\devkitpro\libwoopsigfx
xcopy icon C:\devkitpro\libwoopsigfx\icon\
xcopy include C:\devkitpro\libwoopsigfx\include\
xcopy lib C:\devkitpro\libwoopsigfx\lib\