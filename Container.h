#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <stdexcept>

// Custom namespace
namespace LibrarySystem {

// Template class: can store any type of data
template <typename T>
class Container {
private:
    std::vector<T> items;
    int maxSize;

public:
    Container(int maxSize = 100) : maxSize(maxSize) {}
    
    void add(const T& item) {
        if (items.size() >= static_cast<size_t>(maxSize)) {
            throw std::overflow_error("Container is full");
        }
        items.push_back(item);
    }
    
    T get(int index) const {
        if (index < 0 || index >= static_cast<int>(items.size())) {
            throw std::out_of_range("Index out of range");
        }
        return items[index];
    }
    
    int size() const {
        return items.size();
    }
    
    bool isEmpty() const {
        return items.empty();
    }
};

} // namespace LibrarySystem

#endif

