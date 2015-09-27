#Stephen Friedman
#cse109
#Prog 7
#This program rocks my socks
#Due Friday April 4th 2014
run:silc
	./silc test5.in

silc: Lex.o Token.o parser.o silc.o
	g++ -o silc silc.o parser.o Token.o Lex.o

silc.o: silc.cc parser.h Lex.h Token.h
	g++ silc.cc -c -g -Wall -Werror

parser.o: parser.cc parser.h
	g++ parser.cc -c -g -Wall -Werror

Lex.o: Lex.cc Lex.h
	g++ Lex.cc -c -g -Wall -Werror

Token.o:Token.cc Token.h
	g++ Token.cc -c -g -Wall -Werror

clean:
	rm -f *.o silc *~


