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
        if (studentIt->token == 0 && checkBookAvailability(bno)) {
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

void System::searchBooksByAuthor(const std::string& author) const {
    bool found = false;
    for (const auto& book : books) {
        if (book.aname == author) {
            std::cout << "Book Number: " << book.bno << "\n"
                      << "Name: " << book.bname << "\n"
                      << "Author: " << book.aname << "\n"
                      << "Publication: " << book.pname << "\n"
                      << "Quantity: " << book.quant << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No books found for author: " << author << std::endl;
    }
}

void System::searchBooksByPublication(const std::string& publication) const {
    bool found = false;
    for (const auto& book : books) {
        if (book.pname == publication) {
            std::cout << "Book Number: " << book.bno << "\n"
                      << "Name: " << book.bname << "\n"
                      << "Author: " << book.aname << "\n"
                      << "Publication: " << book.pname << "\n"
                      << "Quantity: " << book.quant << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No books found for publication: " << publication << std::endl;
    }
}

bool System::checkBookAvailability(int bno) const {
    auto bookIt = bookMap.find(bno);
    if (bookIt != bookMap.end()) {
        return (bookIt->second->quant > 0);
    }
    return false;
}

bool System::deleteBook(int bno) {
    auto it = std::find_if(books.begin(), books.end(), [bno](const Book& book) { return book.bno == bno; });
    if (it != books.end()) {
        deletedBooksStack.push(*it); // Push the deleted book onto the stack
        books.erase(it); // Erase the book from the system
        std::cout << "Book deleted successfully.\n";
        return true; // Return true indicating successful deletion
    } else {
        std::cout << "Book not found.\n";
        return false; // Return false indicating book not found
    }
}

void System::undoDeleteBook() {
    if (!deletedBooksStack.empty()) {
        Book book = deletedBooksStack.top(); // Get the top book from the stack
        books.push_back(book); // Add the deleted book back to the system
        deletedBooksStack.pop(); // Remove the top item from the stack
        std::cout << "Undone deletion of book.\n";
    } else {
        std::cout << "No deleted books to undo.\n";
    }
}

void System::redoDeleteBook() {
    if (!deletedBooksStack.empty()) {
        Book book = deletedBooksStack.top(); // Get the top book from the stack
        deletedBooksStack.pop(); // Remove the top item from the stack
        books.push_back(book); // Add the book back to the system
        std::cout << "Redone deletion of book.\n";
    } else {
        std::cout << "No deleted books to redo.\n";
    }
}

bool System::deleteStudent(int admno) {
    auto it = std::find_if(students.begin(), students.end(), [admno](const Student& student) { return student.admno == admno; });
    if (it != students.end()) {
        deletedStudentsStack.push(*it); // Push the deleted student onto the stack
        students.erase(it); // Erase the student from the system
        std::cout << "Student deleted successfully.\n";
        return true; // Return true indicating successful deletion
    } else {
        std::cout << "Student not found.\n";
        return false; // Return false indicating student not found
    }
}

void System::undoDeleteStudent() {
    if (!deletedStudentsStack.empty()) {
        Student student = deletedStudentsStack.top(); // Get the top student from the stack
        students.push_back(student); // Add the deleted student back to the system
        deletedStudentsStack.pop(); // Remove the top item from the stack
        std::cout << "Undone deletion of student.\n";
    } else {
        std::cout << "No deleted students to undo.\n";
    }
}

void System::redoDeleteStudent() {
    if (!deletedStudentsStack.empty()) {
        Student student = deletedStudentsStack.top(); // Get the top student from the stack
        deletedStudentsStack.pop(); // Remove the top item from the stack
        students.push_back(student); // Add the student back to the system
        std::cout << "Redone deletion of student.\n";
    } else {
        std::cout << "No deleted students to redo.\n";
    }
}

void System::displayAllBooks() const {
    std::cout << "All Books:\n";
    for (const auto& book : books) {
        std::cout << "Book Number: " << book.bno << "\n"
                  << "Name: " << book.bname << "\n"
                  << "Author: " << book.aname << "\n"
                  << "Publication: " << book.pname << "\n"
                  << "Quantity: " << book.quant << "\n\n";
    }
}

void System::displayAllStudents() const {
    std::cout << "All Students:\n";
    for (const auto& student : students) {
        std::cout << "Admission Number: " << student.admno << "\n"
                  << "Name: " << student.name << "\n"
                  << "Book Issued (Book No.): " << student.bno << "\n"
                  << "Token: " << student.token << "\n\n";
    }
}
