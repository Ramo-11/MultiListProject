#include "Node.h"

#include <vector>

Node *head;
Node *last;

void setUp(int stdIndex, int clsIndex) {
    head = new Node();
    last = new Node();

    head->studentID = stdIndex++;
    head->nextStudent = last;
    
    last->studentID = stdIndex++;
    last->nextStudent = nullptr;
}

void addElement(int stdIndex, int clsIndex) {
    Node *another = new Node();

    last = head;
    while(last->nextStudent != nullptr) {
        last = last->nextStudent;   //Finds last node
    }
    another = last;
    last = new Node();
    another->nextStudent = last;
    last->nextStudent = nullptr;
}

void showElements() {
    last = head;
    while(last->nextStudent != nullptr) {
        std::cout << last->studentID << " ";
        last = last->nextStudent;
    }
    std::cout << last->studentID << " ";
}

int main() {
    int stdIndex = 0;
    int clsIndex = 0;

    setUp(stdIndex, clsIndex);
    addElement(4, 5);
    showElements();
    
    delete head;
    std::cout << std::endl;    
    return 0;
}