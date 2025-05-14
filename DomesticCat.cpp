#include "DomesticCat.hpp"
#include <iostream>

#include "Cat.hpp"

// Default constructor - creates a FatCat with default values
DomesticCat::DomesticCat() : Cat() {}

// Parameterized constructor - creates a FatCat with specific values
DomesticCat::DomesticCat(std::string name, int age, int fullnessLevel)
    : Cat(name, age, fullnessLevel) {}

// Copy constructor - creates a new FatCat as a copy of another FatCat
DomesticCat::DomesticCat(const DomesticCat& other) : Cat(other) {}

// Assignment operator
DomesticCat& DomesticCat::operator=(const DomesticCat& other) {
    if (this == &other) return *this;
    Cat::operator=(other);
    return *this;
}

// Destructor - ensures proper cleanup of FatCat
DomesticCat::~DomesticCat() {}

// Clone method (smart pointer) - returns a new FatCat (deep copy)
std::shared_ptr<Cat> DomesticCat::clone() const {
    return std::make_shared<DomesticCat>(*this);
}

// getType method - returns the type of this cat
std::string DomesticCat::getType() const { 
    return "Domestic Cat"; 
}

// sound method - unique sound for FatCat
void DomesticCat::sound() const {
    std::cout << R"(

             /\_____/\
            /  o   o  \
           ( ==  ^  == )
            )         (
           (           )
          ( (  )   (  ) )
         (__(__)___(__)__)

        Sound: Purrr... meow!
    
    )" << "\n";
}


