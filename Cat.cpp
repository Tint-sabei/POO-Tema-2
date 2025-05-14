#include "Cat.hpp"
#include <iostream>

#include "Exceptions.hpp"


// Initialize Static Counter
int Cat::catCount = 0;

// Default constructor
Cat::Cat() : name("Unnamed"), age(0), fullnessLevel(100) { catCount++; }

// Parameterized constructor
Cat::Cat(std::string name, int age, int fullnessLevel)
    : name(name), age(age), fullnessLevel(fullnessLevel) { catCount++; }

// Copy constructor
Cat::Cat(const Cat& other)
    : name(other.name), age(other.age), fullnessLevel(other.fullnessLevel) { catCount++; }

// Assignment operator
Cat& Cat::operator=(const Cat& other) {
    if (this == &other) return *this;
    name = other.name;
    age = other.age;
    fullnessLevel = other.fullnessLevel;
    return *this;
}

// Destructor
Cat::~Cat() { catCount--; }

// Static method to get total Cat count
int Cat::getCatCount() { 
    return catCount; }

// Getter methods
std::string Cat::getName() const { 
    return name; 
}
int Cat::getAge() const { 
    return age; 
}
int Cat::getFullnessLevel() const { 
    return fullnessLevel; 
}

// Update Fullness Level
void Cat::update(int value) {
    fullnessLevel += value;
    
    // Check for overfeeding (throws exception)
    if (fullnessLevel > 100) 
        throw FullnessTooHighException(); 
}

