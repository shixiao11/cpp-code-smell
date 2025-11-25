#include "Reader.h"
#include "Book.h"
#include "Library.h"
#include <algorithm>

Reader::Reader(const std::string& name) : name(name) {}

std::string Reader::getName() const {
    return name;
}

void Reader::borrowBook(Book* book) {
    borrowedBooks.push_back(book);
}

bool Reader::returnBook(Book* book) {
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), book);
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);
        book->setAvailable(true);
        return true;
    }
    return false;
}

int Reader::getBorrowedCount() const {
    return borrowedBooks.size();
}

