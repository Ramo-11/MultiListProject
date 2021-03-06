main:  
	g++ -g main.cpp Node.cpp -o main

run: main
	./main

clean:
	rm main