#include "Book.h"
#include "Author.h"

Book::Book(const std::string& title, const std::string& isbn) 
    : title(title), isbn(isbn), author(nullptr), available(true) {}

std::string Book::getTitle() const {
    return title;
}

void Book::setAuthor(Author* author) {
    this->author = author;
    if (author != nullptr) {
        author->addBook(this);
    }
}

Author* Book::getAuthor() const {
    return author;
}

bool Book::isAvailable() const {
    return available;
}

void Book::setAvailable(bool status) {
    available = status;
}

