@echo off 
SETLOCAL EnableDelayedExpansion

set progress_file="progress.txt"
set value=1

if exist !progress_file! (
	set /p value=<!progress_file!
	set /a value+=1
	echo !value! > !progress_file!
	exit
	
) else (
	touch !progress_file!
	echo 1 > !progress_file!
	exit
)

:END
exit