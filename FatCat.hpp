#ifndef FAT_CAT_HPP
#define FAT_CAT_HPP

#include "Cat.hpp"

class FatCat : public Cat {
public:
    // Normal Constructors
    FatCat();
    FatCat(std::string name, int age, int fullnessLevel);
    FatCat(const FatCat& other);
    FatCat& operator=(const FatCat& other);

    // Destructor
    ~FatCat();

    // Clone Method (Smart Pointer)
    std::shared_ptr<Cat> clone() const override;

    // Overridden Methods
    std::string getType() const override;
    void sound() const override; 

};

#endif // FAT_CAT_HPP