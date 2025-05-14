#ifndef FOOD_HPP
#define FOOD_HPP

#include <iostream>
#include <memory> // For std::shared_ptr

class Food {
public:
    // Normal Constructor and Destructor
    Food();
    virtual ~Food();

    // Pure Virtual Methods (Polymorphic Behavior)
    virtual void treat() = 0;
    virtual void eat() = 0;

    // Factory Method for Smart Pointer
    static std::shared_ptr<Food> createFish();
    static std::shared_ptr<Food> createDryFood();
    static std::shared_ptr<Food> createMilk();
};

// Fish Class 
class Fish : public Food {
public:
    Fish();
    ~Fish();
    void treat() override;
    void eat() override;
};

// DryFood Class 
class DryFood : public Food {
public:
    DryFood();
    ~DryFood();
    void treat() override;
    void eat() override;
};

// Milk Class 
class Milk : public Food {
public:
    Milk();
    ~Milk();
    void treat() override;
    void eat() override;
};

#endif // FOOD_HPP