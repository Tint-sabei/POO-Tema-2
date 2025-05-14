#include "GameState.hpp"   
#include <iostream>        

#include "Exceptions.hpp"
#include "FatCat.hpp"

// Add a Cat to the Game 

// Adds a Cat object (shared pointer) to the list of Cats in the game
void GameState::addCat(const std::shared_ptr<Cat>& cat) {
    cats.push_back(cat); // Store the Cat in the vector (smart pointer)
}

// Show All Cats 

// Displays all Cats in the game with their details (type, name, age, fullness)
void GameState::showCats() const {
    std::cout << "\n=== All Cats ===\n";
    
    // Loop through the list of Cats
    for (size_t i = 0; i < cats.size(); ++i) {
        // Display each Cat's type, name, age, and fullness level
        std::cout << "[" << i << "] " 
                  << cats[i]->getType() 
                  << " - " << cats[i]->getName() 
                  << ", Age: " << cats[i]->getAge() 
                  << ", Fullness: " << cats[i]->getFullnessLevel() << "\n";
    }
}

// Feed a Cat with Food 

// Feeds the specified Cat with a chosen Food type
void GameState::feedCat(int index, const std::shared_ptr<Food>& food) {
    // Check if the index is valid
    if (index < 0 || index >= static_cast<int>(cats.size())) {
        std::cout << "Invalid Cat index.\n";
        return;
    }

    try {
        // Display feeding action
        std::cout << "\nFeeding " << cats[index]->getName() << " with food...\n";
        food->treat();       // Show the treat message for the chosen food
        food->eat();         // Show the eating sound for the chosen food

        // Normal fullness increase
        int fullnessIncrease = 20;
        
        // Use dynamic_cast to check if this is a FatCat (without unused variable issue)
        if (dynamic_cast<FatCat*>(cats[index].get())) {
            std::cout << "This is a FatCat! Extra fullness bonus applied!\n";
            fullnessIncrease += 10; // Bonus for FatCat
        }

        // Increase the Cat's fullness
        cats[index]->update(fullnessIncrease);

        // Display the updated fullness level
        std::cout << "Fullness after feeding: " << cats[index]->getFullnessLevel() << "\n";

        // Display feedback based on the fullness level
        if (cats[index]->getFullnessLevel() >= 100) {
            std::cout << R"(

                      /^--^\     /^--^\     /^--^\
                      \____/     \____/     \____/
                     /      \   /      \   /      \
                    |        | |        | |        |
                     \__  __/   \__  __/   \__  __/
|^|^|^|^|^|^|^|^|^|^|^|^\ \^|^|^|^/ /^|^|^|^|^\ \^|^|^|^|^|^|^|^|^|^|^|^|
| | | | | | | | | | | | |\ \| | |/ /| | | | | | \ \ | | | | | | | | | | |
| | | | | | | | | | | | / / | | |\ \| | | | | |/ /| | | | | | | | | | | |
| | | | | | | | | | | | \/| | | | \/| | | | | |\/ | | | | | | | | | | | |
#########################################################################
| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |


            )" << "\n";
                std::cout << "\"I'm full now! *purrr*\"\n";

        } else if (cats[index]->getFullnessLevel() >= 50) {
            std::cout << R"(
           
         /\     /\
        {  `---'  }
        {  O   O  }
        ~~>  V  <~~
         \  \|/  /
          `-----'____
          /     \    \_
         {       }\  )_\_   _
         |  \_/  |/ /  \_\_/ )
          \__/  /(_/     \__/
            (__/                      


            )" << "\n";
                std::cout << "\"I'm okay. I can eat more!\"\n";
        } else {
            std::cout << R"(

                                    |\__/,|   (`\
                                    |_ _  |.--.) )
                                    ( T   )     /
                                   (((^_(((/(((_/

            )" << "\n";
                std::cout << "\"Meeooowww... starving... feed meeee!\"\n";
        }

    } catch (const FullnessTooHighException& e) {
        // Handle any exception that may occur (like overfeeding)
        std::cerr << "Error: " << e.what() << "\n";
    }
}

// Show Total Cat Count 

// Displays the total number of Cats (static method from Cat class)
void GameState::showTotalCats() const {
    std::cout << "\nTotal Cats: " << Cat::getCatCount() << "\n";
}


// Display Cat Sound
void GameState::makeCatSound(size_t index) const {
    if (index < cats.size()) { // No need to check index >= 0
        cats[index]->sound();
    } else {
        std::cout << "Invalid Cat Index.\n";
    }
}

