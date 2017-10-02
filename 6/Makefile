# In this makefile we are accepting the input from user as a command line
# which gets stored in macro ARGS

all:
	gcc proc1.c -o proc1
	gcc proc2.c -o proc2
run:
	./proc1 ${ARGS}
usage:
	@echo 'use as : make ARGS="CommandLine_Argument" run'
clean:
	rm proc1 proc2
