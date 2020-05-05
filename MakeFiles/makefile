-include config.mk

allObjs = $(allSrcs:.c=.o)
allDeps = $(allSrcs:.c=.d)


$(FinalTargetName) : CFLAG = 
$(allObjs) :  CFLAG = -c  
$(allDeps) :  CFLAG = -MM
$(FinalTargetName) : num=7 
$(allObjs) :  num=6  
$(allDeps) :  num=6

$(FinalTargetName) : $(allObjs)
	@$(CC) $(CFLAG) $^ -o $@
	@cmd /K "progress.bat"
	@cmd /C progress.py $(num)
	
$(allObjs) : %.o : %.c
	@$(CC) $(CFLAG)  $< -o $@
	@cmd /K "progress.bat"
	@cmd /C progress.py $(num)
	
$(allDeps) : %.d : %.c | Dependecies
	@$(CC) $(CFLAG) $< -o $@
	@cp $@ Dependecies
	@cmd /K "progress.bat"
	@cmd /C progress.py $(num)
	
.PHONY : clean onlyCompile link depend all 

Dependecies : 
	mkdir $@

all : $(allDeps) 
	$(MAKE) $(FinalTargetName)
	echo 0 > "progress.txt"


clean : 
	echo 0 > "progress.txt"
	rm -R $(allObjs) $(FinalTargetName) $(allDeps) Dependecies\*
	
onlyCompile : $(allObjs)
	
link : $(allObjs)
	$(CC) $(allObjs) -o $(FinalTargetName)

depend : $(allDeps)