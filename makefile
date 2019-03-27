CC=g++

all:
	${CC} main.cpp lexical.cpp symTable.cpp top-down.cpp

clean:
	rm a.out
