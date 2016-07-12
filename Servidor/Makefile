all: main

main: Server.o Word.o Start.o BDFile.o
	g++ -std=c++11 Server.o Word.o Start.o BDFile.o -o main

Server.o: Server.cpp
	g++ -std=c++11 -c Server.cpp

Start.o: Start.cpp Start.h
	g++ -std=c++11 -c Start.cpp

Word.o: Word.cpp Word.h
	g++ -std=c++11 -c Word.cpp

BDFile.o: BDFile.cpp BDFile.h
	g++ -std=c++11 -c BDFile.cpp

clean:
	rm *o main

