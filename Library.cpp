#include "Library.h"
#include "Reader.h"

Library::Library(const std::string& name) : name(name) {}

Library::~Library() {
    for (auto book : books) {
        delete book;
    }
    for (auto author : authors) {
        delete author;
    }
}

void Library::addBook(Book* book) {
    books.push_back(book);
}

void Library::addAuthor(Author* author) {
    authors.push_back(author);
}

// CODE SMELL 4: Method renamed from findBookByTitle to locateBookUsingTitle
Book* Library::locateBookUsingTitle(const std::string& title) {
    for (auto book : books) {
        if (book->getTitle() == title) {
            return book;
        }
    }
    return nullptr;
}

// CODE SMELL 2: Memory leak - allocating temporary buffer without freeing it
bool Library::lendBook(const std::string& title, Reader* reader) {
    // Memory leak: allocating heap memory for log message but never freeing it
    char* logMessage = new char[256];
    sprintf(logMessage, "Attempting to lend book: %s", title.c_str());
    // logMessage is never deleted - MEMORY LEAK
    
    Book* book = locateBookUsingTitle(title);
    if (book != nullptr && book->isAvailable()) {
        book->setAvailable(false);
        reader->borrowBook(book);
        return true;
    }
    return false;
}

// Method overloading implementation
// Overload 1: Search by title
// CODE SMELL 1: Potential null pointer dereference - accessing book without null check
std::vector<Book*> Library::search(const std::string& title) {
    std::vector<Book*> result;
    for (auto book : books) {
        // Dangerous: book could be nullptr but we dereference it directly
        if (book->getTitle().find(title) != std::string::npos) {
            result.push_back(book);
        }
    }
    return result;
}

// Overload 2: Search by author
// CODE SMELL 1: Potential null pointer dereference - using author without null check
std::vector<Book*> Library::search(Author* author) {
    std::vector<Book*> result;
    // Dangerous: author could be nullptr and we dereference it in comparison
    // Also dereferencing book->getAuthor() without checking if book is null
    for (auto book : books) {
        if (book->getAuthor() == author && book->getAuthor()->getName() == author->getName()) {
            result.push_back(book);
        }
    }
    return result;
}

// CODE SMELL 3: Poor variable naming - confusing variable names that hurt readability
std::vector<Book*> Library::search(bool availableOnly) {
    std::vector<Book*> x;  // renamed from 'result' to 'x' - unclear name
    for (auto y : books) {  // renamed from 'book' to 'y' - unclear name
        if (!availableOnly || y->isAvailable()) {
            x.push_back(y);
        }
    }
    return x;
}

