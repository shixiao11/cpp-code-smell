#include "BookManager.h"
#include "Author.h"
#include <iostream>

// CODE SMELL 5: Implementation that calls existing Library methods
BookManager::BookManager(Library* lib) : library(lib) {}

void BookManager::displayBookInfo(const std::string& title) {
    // Calls the renamed method from Library
    Book* book = library->locateBookUsingTitle(title);
    if (book != nullptr) {
        std::cout << "Book found: " << book->getTitle() << std::endl;
        Author* author = book->getAuthor();
        if (author != nullptr) {
            std::cout << "Author: " << author->getName() << std::endl;
        }
        std::cout << "Available: " << (book->isAvailable() ? "Yes" : "No") << std::endl;
    } else {
        std::cout << "Book not found: " << title << std::endl;
    }
}

void BookManager::searchAndDisplay(const std::string& keyword) {
    // Calls the overloaded search method with null pointer issue
    std::vector<Book*> results = library->search(keyword);
    std::cout << "Search results for '" << keyword << "':" << std::endl;
    for (auto book : results) {
        std::cout << "  - " << book->getTitle() << std::endl;
    }
}

int BookManager::countAvailableBooks() {
    // Calls the search method with poor variable naming
    std::vector<Book*> availableBooks = library->search(true);
    return availableBooks.size();
}

