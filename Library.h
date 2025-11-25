#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include "Book.h"
#include "Author.h"

class Reader;

class Library {
private:
    std::string name;
    std::vector<Book*> books;
    std::vector<Author*> authors;

public:
    Library(const std::string& name);
    ~Library();
    
    void addBook(Book* book);
    void addAuthor(Author* author);
    Book* findBookByTitle(const std::string& title);
    bool lendBook(const std::string& title, Reader* reader);
};

#endif

