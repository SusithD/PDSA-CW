#include "../include/System.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

void System::showBook(int bno) const {
    auto it = std::find_if(books.begin(), books.end(), [bno](const Book& book) { return book.bno == bno; });
    if (it != books.end()) {
        const auto& book = *it;
        std::cout << "Book Number: " << book.bno << "\n"
                  << "Name: " << book.bname << "\n"
                  << "Author: " << book.aname << "\n"
                  << "Publication: " << book.pname << "\n"
                  << "Quantity: " << book.quant << std::endl;
    } else {
        std::cout << "Book not found." << std::endl;
    }
}

void System::showStudent(int admno) const {
    auto it = std::find_if(students.begin(), students.end(), [admno](const Student& student) { return student.admno == admno; });
    if (it != students.end()) {
        const auto& student = *it;
        std::cout << "Student Admission Number: " << student.admno << "\n"
                  << "Name: " << student.name << "\n";
        if (student.token == 1) {
            std::cout << "Book Issued (Book No.): " << student.bno << std::endl;
            
            auto bookIt = std::find_if(books.begin(), books.end(), [student](const Book& book) { return book.bno == student.bno; });
            if (bookIt != books.end()) {
                const auto& book = *bookIt;
                std::cout << "Book Name: " << book.bname << "\n"
                          << "Author: " << book.aname << "\n"
                          << "Publication: " << book.pname << std::endl;
            }
        } else {
            std::cout << "No book issued." << std::endl;
        }
    } else {
        std::cout << "Student not found." << std::endl;
    }
}

