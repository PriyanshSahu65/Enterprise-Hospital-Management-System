#include "ObjectCounter.h"
#include <iostream> // For std::cerr in case of error/debugging

// Initialize the static instance to nullptr
ObjectCounter* ObjectCounter::instance = nullptr;

// Private constructor implementation
ObjectCounter::ObjectCounter() {
    // Optionally, initialize counts for known classes to 0 here if needed
}

// Public method to get the singleton instance
ObjectCounter* ObjectCounter::getInstance() {
    if (instance == nullptr) {
        instance = new ObjectCounter();
    }
    return instance;
}

// Destructor implementation
ObjectCounter::~ObjectCounter() {
    // Optionally, log final counts or cleanup here
    // The map 'counter' will be automatically destructed
    // No need to delete 'instance' here as it's a static member managed globally
    // for this singleton pattern.
    if (instance != nullptr) {
        // This 'delete instance' should typically not be here for a standard
        // singleton where the instance is cleaned up at program exit
        // or through a specific shutdown function if complex cleanup is needed.
        // For simplicity, we often rely on OS to reclaim memory on exit.
        // If you had a dedicated shutdown for Logger, you could have one for ObjectCounter too.
        // For now, let's just make sure it's nullptr if deleted to prevent issues.
        // delete instance; // This line might lead to double deletion if not carefully managed in main()
        instance = nullptr;
    }
}

// Increment the count for a given class name
void ObjectCounter::increment(const std::string& className) {
    counter[className]++;
    // std::cout << "DEBUG: " << className << " count incremented to " << counter[className] << std::endl;
}

// Decrement the count for a given class name
void ObjectCounter::decrement(const std::string& className) {
    if (counter.count(className) > 0 && counter[className] > 0) {
        counter[className]--;
        // std::cout << "DEBUG: " << className << " count decremented to " << counter[className] << std::endl;
    } else {
        // This case should ideally not happen if increments/decrements are balanced
        std::cerr << "Warning: Attempted to decrement count for " << className
                  << " below zero or for an unregistered class." << std::endl;
    }
}

// Get the current count for a given class name
int ObjectCounter::getCount(const std::string& className) const {
    auto it = counter.find(className);
    if (it != counter.end()) {
        return it->second;
    }
    return 0; // Return 0 if class name not found
}

// Get the entire map of counts
const std::map<std::string, int>& ObjectCounter::getCounter() const {
    return counter;
}