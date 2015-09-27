run:lextest
	cat test1.in|./lextester

lextest: Lex.o Token.o lextest.o
	g++ lextest.o Token.o Lex.o -o lextester

lextest.o: Lex.h Token.h
	g++ lextest.cc -c -g -Wall -Werror

Lex.o: Lex.cc Lex.h Token.o
	g++ Lex.cc -c -g -Wall -Werror

Token.o:Token.cc Token.h clean
	g++ Token.cc -c -g -Wall -Werror

clean:
	rm -f *.o lextest *~


