#include "Author.h"
#include "Book.h"
#include <algorithm>

Author::Author(const std::string& name) : name(name) {}

std::string Author::getName() const {
    return name;
}

void Author::addBook(Book* book) {
    if (std::find(books.begin(), books.end(), book) == books.end()) {
        books.push_back(book);
    }
}

int Author::getBookCount() const {
    return books.size();
}

std::vector<Book*> Author::getBooks() const {
    return books;
}

