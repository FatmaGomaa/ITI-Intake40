@echo on
SETLOCAL EnableDelayedExpansion

for /f "tokens=1-4" %%a in (input.txt) do (
	CALL HelloWorld.bat %%a %%b %%c %%d

	if not exist TextFiles   ( mkdir TextFiles )
	if not exist SourceFiles ( mkdir SourceFiles )
	if not exist HeaderFiles ( mkdir HeaderFiles )	
	copy /y %%a\*.txt	 TextFiles
	copy /y %%a\*.c 	 SourceFiles
	copy /y %%a\*.h 	 HeaderFiles

	echo "reached end"
) 

