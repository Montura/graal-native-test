@echo off
IF exist  %1 ( rmdir /s /q %1 )
IF exist  %2 ( rmdir /s /q %2 )