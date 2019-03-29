CC=g++

bc:
	${CC} -o bc main.cpp lexical.cpp symTable.cpp top-down.cpp

clean:
	rm bc
