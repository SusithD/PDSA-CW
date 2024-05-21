#ifndef BOOK_H
#define BOOK_H

#include <string>

struct Book {
    int bno;
    int quant;
    std::string bname;
    std::string aname;
    std::string pname;

    // Constructor
    Book(int bno, int quant, std::string bname, std::string aname, std::string pname)
        : bno(bno), quant(quant), bname(std::move(bname)), aname(std::move(aname)), pname(std::move(pname)) {}
};

#endif // BOOK_H
