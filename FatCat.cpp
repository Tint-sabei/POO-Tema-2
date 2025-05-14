#include "FatCat.hpp"      
#include <iostream>         

#include "Cat.hpp"          

// Default constructor - creates a FatCat with default values
FatCat::FatCat() : Cat() {}

// Parameterized constructor - creates a FatCat with specific values
FatCat::FatCat(std::string name, int age, int fullnessLevel) 
    : Cat(name, age, fullnessLevel) {}

// Copy constructor - creates a new FatCat as a copy of another FatCat
FatCat::FatCat(const FatCat& other) : Cat(other) {}

// Assignment operator - assigns values from one FatCat to another
FatCat& FatCat::operator=(const FatCat& other) { 
    if (this == &other) return *this; // Self-assignment check
    Cat::operator=(other);            // Use base class assignment operator
    return *this;
}

// Destructor - ensures proper cleanup of FatCat
FatCat::~FatCat() {}

// Clone method (smart pointer) - returns a new FatCat (deep copy)
std::shared_ptr<Cat> FatCat::clone() const {
    return std::make_shared<FatCat>(*this);
}

// getType method - returns the type of this cat
std::string FatCat::getType() const { 
    return "Fat Cat"; 
}

// sound method - unique sound for FatCat
void FatCat::sound() const { 
    std::cout << R"(
                       
                    .       .
             |\_---_/|
            /   o_o   \
            |    U    |
            \  ._I_.  /
             `-_____-'                  
    
        Sound: Mrrrow... *yawn*    
    
    )" << "\n";
}