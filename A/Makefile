#makefile for stack
#J. Femister
#CSE 109
#Spring 2014

OBJ= teststack.o stack.o
OPTS= -g -c -Wall -Werror

test: $(OBJ)
	g++ -o teststack $(OBJ)

teststack.o: teststack.cc stack.h stack.cc
	g++ $(OPTS) teststack.cc

stack.o: stack.cc stack.h
	g++ $(OPTS) stack.cc

clean:
	rm -f *.o *~
