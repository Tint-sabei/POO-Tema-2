#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include <memory> // For std::shared_ptr

class Cat {
protected:
    std::string name;
    int age;
    int fullnessLevel;
    static int catCount; // Static counter for all Cat objects

public:
    // Normal Constructors
    Cat();
    Cat(std::string name, int age, int fullnessLevel);
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);

    // Virtual Destructor
    virtual ~Cat();

    // Static Method (Get Total Cats)
    static int getCatCount();
    
    // Pure Virtual Methods (Polymorphic Behavior)
    virtual std::shared_ptr<Cat> clone() const = 0; // Clone with smart pointer
    virtual std::string getType() const = 0;
    virtual void sound() const = 0; 


    // Normal Getter Methods
    std::string getName() const;
    int getAge() const;
    int getFullnessLevel() const;

    // Update Fullness Level
    void update(int value);
};

#endif // CAT_HPP