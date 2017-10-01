# In this makefile we are accepting the input from user as a command line
# which gets stored in macro ARGS

all:
	gcc Proc1.c -o Proc1
	gcc Proc2.c -o Proc2
run:
	./Proc1 ${ARGS}
usage:
	@echo 'use as : make ARGS="CommandLine_Argument" run'
clean:
	rm Proc1 Proc2
