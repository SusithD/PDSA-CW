#include "../include/System.h"
#include <iostream>
#include <algorithm>
#include <limits>


System::System() {}

System::~System() {
    
}

void System::createBook(int bno, int quant, const std::string& bname, const std::string& aname, const std::string& pname) {
   
    auto it = bookMap.find(bno);
    if (it == bookMap.end()) { 
        books.emplace_back(bno, quant, bname, aname, pname);
        bookMap[bno] = &books.back(); 
        std::cout << "Book added successfully.\n";
    } else {
        std::cout << "Book already exists.\n";
    }
}

void System::createStudent(const std::string& name, int admno) {
    
    auto it = std::find_if(students.begin(), students.end(), [admno](const Student& s) { return s.admno == admno; });
    if (it == students.end()) { 
        students.emplace_back(name, admno);
        std::cout << "Student added successfully.\n";
    } else {
        std::cout << "Student already exists.\n";
    }
}


void System::issueBook(int admno, int bno) {
    auto studentIt = std::find_if(students.begin(), students.end(), [admno](const Student& student) { return student.admno == admno; });
    auto bookIt = bookMap.find(bno);

    if (studentIt != students.end() && bookIt != bookMap.end()) {
        if (studentIt->token == 0 && bookIt->second->quant > 0) {
            studentIt->bno = bno;
            studentIt->token = 1;
            bookIt->second->quant--;
            std::cout << "Book issued successfully.\n";
        } else {
            std::cout << "Book cannot be issued. Either the book is out of stock or the student already has a book issued.\n";
        }
    } else {
        std::cout << "Either the book or the student does not exist.\n";
    }
}


void System::returnBook(int admno, int bno) {
    auto studentIt = std::find_if(students.begin(), students.end(), [admno](const Student& student) { return student.admno == admno; });
    auto bookIt = bookMap.find(bno);

    if (studentIt != students.end() && bookIt != bookMap.end()) {
        if (studentIt->bno == bno && studentIt->token == 1) {
            studentIt->bno = 0;
            studentIt->token = 0;
            bookIt->second->quant++;
            std::cout << "Book returned successfully.\n";
        } else {
            std::cout << "Error in returning the book. Either the book does not match or the student did not issue any book.\n";
        }
    } else {
        std::cout << "Either the book or the student does not exist.\n";
    }
}