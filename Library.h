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
    Book* locateBookUsingTitle(const std::string& title);  // Renamed from findBookByTitle
    bool lendBook(const std::string& title, Reader* reader);
    
    // Method overloading: same name, different parameters
    std::vector<Book*> search(const std::string& title);        // Search by title
    std::vector<Book*> search(Author* author);                  // Search by author
    std::vector<Book*> search(bool availableOnly);              // Search by availability
};

#endif

