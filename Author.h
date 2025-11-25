#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
#include <vector>

class Book;

class Author {
private:
    std::string name;
    std::vector<Book*> books;

public:
    Author(const std::string& name);
    
    std::string getName() const;
    void addBook(Book* book);
    int getBookCount() const;
    std::vector<Book*> getBooks() const;
};

#endif

