#include <iostream>
#include "Book.h"
#include "Author.h"
#include "Library.h"
#include "Reader.h"

int main() {
    // Create library
    Library* library = new Library("City Library");
    
    // Create author
    Author* author = new Author("John Smith");
    library->addAuthor(author);
    
    // Create book
    Book* book = new Book("C++ Programming", "ISBN-12345");
    book->setAuthor(author);
    library->addBook(book);
    
    // Create reader
    Reader* reader = new Reader("Alice");
    
    // Borrow book
    std::cout << "Reader " << reader->getName() << " borrows book: " 
              << book->getTitle() << std::endl;
    library->lendBook("C++ Programming", reader);
    
    std::cout << "Book available: " << (book->isAvailable() ? "Yes" : "No") << std::endl;
    std::cout << "Reader borrowed count: " << reader->getBorrowedCount() << std::endl;
    
    // Return book
    reader->returnBook(book);
    std::cout << "After return, book available: " 
              << (book->isAvailable() ? "Yes" : "No") << std::endl;
    
    delete reader;
    delete library;
    
    return 0;
}

