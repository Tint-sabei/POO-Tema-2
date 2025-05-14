#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Cat.hpp"
#include "Food.hpp"

#include <iostream>
#include <vector>
#include <memory>

class GameState {
private:
    std::vector<std::shared_ptr<Cat>> cats; // Store all Cats

public:
    // Add a Cat to the game
    void addCat(const std::shared_ptr<Cat>& cat);

    // Show all Cats
    void showCats() const;

    // Feed a Cat
    void feedCat(int index, const std::shared_ptr<Food>& food);

    // Show total Cat count (static method)
    void showTotalCats() const;

    // Cat Sound
    void makeCatSound(size_t index) const;

};

#endif // GAMESTATE_HPP