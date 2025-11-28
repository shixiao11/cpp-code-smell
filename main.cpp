#include <iostream>
#include "Book.h"
#include "Author.h"
#include "Library.h"
#include "Reader.h"
#include "Container.h"

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
    
    std::cout << "\n--- Demonstrating Method Overloading ---" << std::endl;
    
    // Overload 1: search by title (string parameter)
    std::vector<Book*> result1 = library->search("C++");
    std::cout << "Search by title 'C++': found " << result1.size() << " book(s)" << std::endl;
    
    // Overload 2: search by author (Author* parameter)
    std::vector<Book*> result2 = library->search(author);
    std::cout << "Search by author '" << author->getName() << "': found " 
              << result2.size() << " book(s)" << std::endl;
    
    // Overload 3: search by availability (bool parameter)
    std::vector<Book*> result3 = library->search(true);
    std::cout << "Search available books only: found " << result3.size() << " book(s)" << std::endl;
    
    std::cout << "\n--- Demonstrating Template Class and Namespace ---" << std::endl;
    
    // Using namespace and template class with different types
    // Template instantiation 1: Container of integers
    LibrarySystem::Container<int> numberContainer(5);
    numberContainer.add(10);
    numberContainer.add(20);
    numberContainer.add(30);
    std::cout << "Integer container size: " << numberContainer.size() << std::endl;
    std::cout << "First number: " << numberContainer.get(0) << std::endl;
    
    // Template instantiation 2: Container of strings
    LibrarySystem::Container<std::string> nameContainer(5);
    nameContainer.add("Alice");
    nameContainer.add("Bob");
    nameContainer.add("Charlie");
    std::cout << "String container size: " << nameContainer.size() << std::endl;
    std::cout << "First name: " << nameContainer.get(0) << std::endl;
    
    // Template instantiation 3: Container of doubles
    LibrarySystem::Container<double> priceContainer(5);
    priceContainer.add(19.99);
    priceContainer.add(29.99);
    std::cout << "Double container size: " << priceContainer.size() << std::endl;
    std::cout << "First price: " << priceContainer.get(0) << std::endl;
    
    delete reader;
    delete library;
    
    return 0;
}

