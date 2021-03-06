#include "Node.h"
#include <cmath>

    Node *head = new Node();
    Node *second = new Node();
    Node *pointer = new Node();

void setUp() {
    head->nextStudent = second;
    second->nextStudent = pointer;
    pointer->nextStudent = nullptr;
}

void indexNodes() {
    int index = 1;
    pointer = head;

    while(pointer->nextStudent != nullptr) {
        pointer->studentID = index++;
        pointer = pointer->nextStudent;
    }
    pointer->studentID = index;
}

//returns the number of existing nodes
int getNodeNum() {
    int nodesNum = 0;

    pointer = head;
    while(pointer->nextStudent != nullptr) {
        pointer = pointer->nextStudent;
        nodesNum++;
    }
    return (nodesNum + 1);
}

void addElement(int choice) {
    pointer = head;

    while(pointer->nextStudent != nullptr) {
        pointer = pointer->nextStudent;    //Find the pointer node and assign it to pointer
    } 

    Node *newNode = new Node();
    newNode = pointer;
    pointer = new Node();
    newNode->nextStudent = pointer;
    pointer->nextStudent = nullptr;
}

bool findStudent(int choice) {
    pointer = head;

    while(pointer->nextStudent != nullptr) {
        if(pointer->studentID == choice) {
            return true;
        }
        pointer = pointer->nextStudent;
    }
    return false;
}

int main() {
    
    int choice;

    setUp();
    indexNodes();

    std::cout << "What is the number of student you want add?\n";
    std::cin >> choice;

    if(findStudent(choice)) {
        std::cout << "Found";
    }
    else {
        std::cout << "not found";
    }

    std::cout << "\n";
    return 0;
}