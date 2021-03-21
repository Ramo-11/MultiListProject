main: main.o addGrade.o findNode.o findStudent.o getNodeGrade.o getStdNode.o insertElementNode.o insertStudentNode.o setUp.o printNodes.o Node.o
	g++ -g main.o addGrade.o findNode.o findStudent.o getNodeGrade.o getStdNode.o insertElementNode.o insertStudentNode.o setUp.o printNodes.o Node.o -o main

main.o: main.cpp 
	g++ -g -c main.cpp

addGrade.o: addGrade.h addGrade.cpp
	g++ -g -c addGrade.cpp

findNode.o: findNode.h findNode.cpp
	g++ -g -c findNode.cpp

findStudent.o: findStudent.h findStudent.cpp
	g++ -g -c findStudent.cpp

getNodeGrade.o: getNodeGrade.h getNodeGrade.cpp
	g++ -g -c getNodeGrade.cpp

getStdNode.o: getStdNode.h getStdNode.cpp
	g++ -g -c getStdNode.cpp
	
insertElementNode.o: insertElementNode.h insertElementNode.cpp
	g++ -g -c insertElementNode.cpp

insertStudentNode.o: insertStudentNode.h insertStudentNode.cpp
	g++ -g -c insertStudentNode.cpp

printNodes.o: printNodes.h printNodes.cpp
	g++ -g -c printNodes.cpp

setUp.o: setUp.h setUp.cpp
	g++ -g -c setUp.cpp	

Node.o: Node.h Node.cpp
	g++ -g -c Node.cpp	


run:
	./main

clean:
	rm *.o
	rm main