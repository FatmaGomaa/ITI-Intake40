@echo on
SETLOCAL EnableDelayedExpansion

set folder_name=%1
set txt_file=%2
set source_file=%3
set header_file=%4
set value

if exist !folder_name! ( goto DirectroyExist )
mkdir !folder_name!
:DirectroyExist
cd !folder_name!
if exist !txt_file! ( 
	for /f "tokens=1" %%m in (!txt_file!) do (
		set /a value=%%m
		set /a value+=1
		echo !value!
	)
	echo !value! > !txt_file!
	echo !value! > !source_file!
	echo !value! > !header_file!
) else (
	echo 0 > !txt_file!
	echo 0 > !source_file!
	echo 0 > !header_file!
)
cd ..