#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Student {
    std::string name;
    int bno; 
    int token; 
    int admno; 

    
    Student(std::string name, int admno, int bno = 0, int token = 0)
        : name(std::move(name)), admno(admno), bno(bno), token(token) {}
};

#endif 
