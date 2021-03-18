main: main.o addGrade.o findNode.o findStudent.o getNodeGrade.o getStdNode.o globalVariables.o insertElementNode.o insertStudentNode.o setUp.o printNodes.o
	g++ -g addGrade.o findNode.o findStudent.o getNodeGrade.o getStdNode.o globalVariables.o insertElementNode.o insertStudentNode.o setUp.o printNodes.o -o main

main.o: main.cpp 
	g++ -c main.cpp

addGrade.o: addGrade.h addGrade.cpp
	g++ -c addGrade.cpp

findNode.o: findNode.h findNode.cpp
	g++ -c findNode.cpp

findStudent.o: findStudent.h findStudent.cpp
	g++ -c findStudent.cpp

getNodeGrade.o: getNodeGrade.h getNodeGrade.cpp
	g++ -c getNodeGrade.cpp

getStdNode.o: getStdNode.h getStdNode.cpp
	g++ -c getStdNode.cpp

globalVariables.o: globalVariables.h globalVariables.cpp
	g++ -c globalVariables.cpp

insertElementNode.o: insertElementNode.h insertElementNode.cpp
	g++ -c insertElementNode.cpp

insertStudentNode.o: insertStudentNode.h insertStudentNode.cpp
	g++ -c insertStudentNode.cpp

printNodes.o: printNodes.h printNodes.cpp
	g++ -c printNodes.cpp

setUp.o: setUp.h setUp.cpp
	g++ -c setUp.cpp	

run:
	./main

clean:
	rm *.o
	rm main