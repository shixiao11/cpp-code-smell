#ifndef BOOK_H
#define BOOK_H

#include <string>

class Author;

class Book {
private:
    std::string title;
    std::string isbn;
    Author* author;
    bool available;

public:
    Book(const std::string& title, const std::string& isbn);
    
    std::string getTitle() const;
    void setAuthor(Author* author);
    Author* getAuthor() const;
    bool isAvailable() const;
    void setAvailable(bool status);
};

#endif

