#ifndef SYSTEM_H
#define SYSTEM_H

#include "Book.h"
#include "Student.h"

#include <vector>
#include <unordered_map>

class System {
private:
    std::vector<Book> books;
    std::vector<Student> students;
    std::unordered_map<int, Book*> bookMap; 
    std::unordered_map<int, Student*> studentMap; 

public:
    System();
    ~System();
    void createBook(int bno, int quant, const std::string& bname, const std::string& aname, const std::string& pname);
    void createStudent(const std::string& name, int admno);
    void issueBook(int admno, int bno);
    void returnBook(int admno, int bno);
    
    void showStudent(int admno) const;
    void showBook(int bno) const; 

};

#endif 
