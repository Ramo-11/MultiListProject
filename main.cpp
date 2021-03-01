#include "Node.h"
#include "Student.h"
#include "Class.h"

#include <vector>

int main() {

    int tempStdID;

    std::vector<Student*> row;
    std::vector<Class*> column;
 
    for(int i = 0; i < 10; i++) {
        row.push_back(new Student());
    }

    for(int i = 0; i < 5; i++) {
        column.push_back(new Class());
    }

    /*for(int i = 0; i < 10; i++) {
        if(i == 9) {
            row[i]->S_nextStudent = nullptr;
        }
        else{
            row[i]->S_nextStudent = row[i + 1];
        }
    }

    for(int i = 0; i < 5; i++) {
        if(i == 4) {
            column[i]->C_nextClass = nullptr;
        }
        else{
            column[i]->C_nextClass = column[i + 1];
        }
    } */   

    std::cout << std::endl;    
    return 0;
}