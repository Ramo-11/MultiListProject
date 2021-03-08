main:  
	g++ -std=c++0x -g main.cpp Node.cpp -o main

run: main
	./main

clean:
	rm main