main: main.o Node.o Student.o Class.o
	g++ -g main.o Node.o Student.o Class.o -o main

main.o: main.cpp Node.h
	g++ -g -c main.cpp

Node.o: Node.h Node.cpp
	g++ -g -c Node.cpp

Student.o: Student.h Student.cpp
	g++ -g -c Student.cpp
	
Class.o: Class.h Class.cpp
	g++ -g -c Class.cpp

run: main
	./main

clean:
	rm *.o
	rm main
	rm main.exe