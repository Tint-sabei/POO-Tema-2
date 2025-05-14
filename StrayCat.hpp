#ifndef STRAY_CAT_HPP
#define STRAY_CAT_HPP

#include "Cat.hpp"

class StrayCat : public Cat {
public:
    // Normal Constructors
    StrayCat();
    StrayCat(std::string name, int age, int fullnessLevel);
    StrayCat(const StrayCat& other);
    StrayCat& operator=(const StrayCat& other);
    
    // Destructor
    ~StrayCat();
    
    // Clone Method (Smart Pointer)
    std::shared_ptr<Cat> clone() const override;
    
    // Overridden Methods
    std::string getType() const override;
    void sound() const override; 

};
    
#endif // STRAY_CAT_HPP