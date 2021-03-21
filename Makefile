main: main.o Methods.o Node.o
	g++ -g main.o Methods.o Node.o -o main

main.o: main.cpp 
	g++ -g -c main.cpp

Methods.o: Methods.h Methods.cpp
	g++ -g -c Methods.cpp	

Node.o: Node.h Node.cpp
	g++ -g -c Node.cpp	

run:
	./main

clean:
	rm *.o
	rm main