#include "StrayCat.hpp"
#include <iostream>

#include "Cat.hpp"

// Default constructor - creates a FatCat with default values
StrayCat::StrayCat() : Cat() {}

// Parameterized constructor - creates a FatCat with specific values
StrayCat::StrayCat(std::string name, int age, int fullnessLevel) 
    : Cat(name, age, fullnessLevel) {}

// Copy constructor - creates a new FatCat as a copy of another FatCat
StrayCat::StrayCat(const StrayCat& other) : Cat(other) {}

// Assignment operator - assigns values from one FatCat to another
StrayCat& StrayCat::operator=(const StrayCat& other) { 
    if (this == &other) return *this; // Self-assignment check
    Cat::operator=(other);            // Use base class assignment operator
    return *this; 
}

// Destructor - ensures proper cleanup of FatCat
StrayCat::~StrayCat() {}

// Clone method (smart pointer) - returns a new FatCat (deep copy)
std::shared_ptr<Cat> StrayCat::clone() const {
    return std::make_shared<StrayCat>(*this);
}

// getType method - returns the type of this cat
std::string StrayCat::getType() const { 
    return "Stray Cat"; 
}

// sound method - unique sound for FatCat
void StrayCat::sound() const { 
    std::cout << R"(

                |\---/|
                | o_o |
                 \_^_/       
                  
       Sound: HISSS! *scratches*
    
    )" << "\n";
}