#ifndef READER_H
#define READER_H

#include <string>
#include <vector>

class Book;
class Library;

class Reader {
private:
    std::string name;
    std::vector<Book*> borrowedBooks;

public:
    Reader(const std::string& name);
    
    std::string getName() const;
    void borrowBook(Book* book);
    bool returnBook(Book* book);
    int getBorrowedCount() const;
};

#endif

