main: main.o Node.o 
	g++ -g main.o Node.o -o main

main.o: 
	g++ -g -c main.cpp

Node.o: 
	g++ -g -c Node.cpp

run:
	./main

clean:
	rm *.o
	rm main
	rm main.exe