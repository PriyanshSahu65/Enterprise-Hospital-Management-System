#ifndef OBJECTCOUNTER_H
#define OBJECTCOUNTER_H

#include <string>
#include <map> // For std::map to store class counts

class ObjectCounter {
private:
    static ObjectCounter* instance; // Singleton instance
    std::map<std::string, int> counter; // Map to store counts of objects by class name

    // Private constructor to prevent direct instantiation
    ObjectCounter();

    // Private copy constructor and assignment operator to prevent copying
    ObjectCounter(const ObjectCounter&) = delete;
    ObjectCounter& operator=(const ObjectCounter&) = delete;

public:
    // Public method to get the singleton instance
    static ObjectCounter* getInstance();

    // Destructor (optional, but good practice for singletons)
    ~ObjectCounter();

    // Increment the count for a given class name
    void increment(const std::string& className);

    // Decrement the count for a given class name
    void decrement(const std::string& className);

    // Get the current count for a given class name
    int getCount(const std::string& className) const;

    // Get the entire map of counts (useful for logging/debugging all counts)
    const std::map<std::string, int>& getCounter() const;
};

#endif // OBJECTCOUNTER_H