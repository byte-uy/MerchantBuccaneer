@echo off
del /F /Q engine\build\*
rmdir /S /Q engine\build\CMakeFiles
del /F /Q game\build\*
rmdir /S /Q game\build\CMakeFiles
