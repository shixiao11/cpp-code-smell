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

Book* Library::findBookByTitle(const std::string& title) {
    for (auto book : books) {
        if (book->getTitle() == title) {
            return book;
        }
    }
    return nullptr;
}

bool Library::lendBook(const std::string& title, Reader* reader) {
    Book* book = findBookByTitle(title);
    if (book != nullptr && book->isAvailable()) {
        book->setAvailable(false);
        reader->borrowBook(book);
        return true;
    }
    return false;
}

