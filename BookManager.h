#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include <string>
#include <vector>
#include "Book.h"
#include "Library.h"

// CODE SMELL 5: New file that references existing methods
class BookManager {
private:
    Library* library;
    
public:
    BookManager(Library* lib);
    
    // Uses existing Library methods
    void displayBookInfo(const std::string& title);
    void searchAndDisplay(const std::string& keyword);
    int countAvailableBooks();
};

#endif

