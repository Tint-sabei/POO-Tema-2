#include "GameState.hpp"
#include "Cat.hpp"
#include "DomesticCat.hpp"
#include "FatCat.hpp"
#include "StrayCat.hpp"
#include "Food.hpp"
#include "GameState.cpp"
#include "Cat.cpp"
#include "DomesticCat.cpp"
#include "FatCat.cpp"
#include "StrayCat.cpp"
#include "Food.cpp"


#include <iostream>
#include <memory>

void displayMenu() {
    std::cout << "\n";
    std::cout << "=============================================\n";
    std::cout << "          FEEDING HUNGRY CATS GAME\n";
    std::cout << "=============================================\n";
    std::cout << "| 1. Show All Cats                          |\n";
    std::cout << "| 2. Add a New Cat                          |\n";
    std::cout << "| 3. Feed a Cat                             |\n";
    std::cout << "| 4. Show Total Cats Registered             |\n";
    std::cout << "| 5. Display a Cat Sound                    |\n";
    std::cout << "| 6. Exit                                   |\n";
    std::cout << "=============================================\n";
    std::cout << "Choose an option (1-6): ";
}


int main() {
    GameState game;
    bool running = true;

    // Initial Cats
    game.addCat(std::make_shared<DomesticCat>("Mimi", 3, 80));
    game.addCat(std::make_shared<FatCat>("Chonky", 5, 60));
    game.addCat(std::make_shared<StrayCat>("Ghost", 2, 40));

    while (running) {
        displayMenu();
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();            // Clear the error state of input 
            std::cin.ignore(1000, '\n'); // Ignore invalid input up to 1000 characters (max no of character to ignore)
            std::cout << "Invalid choice. Please enter a number.\n";
            continue;                    // Restart the loop
        }

        switch (choice) {
            case 1: // Show all Cats
                game.showCats();   // Calls GameState method to list all cats
                break;

            case 2: { // Add a New Cat
                std::string name;
                int age, fullnessLevel;
                std::cout << "Enter Cat Name: ";
                std::cin >> name;
                std::cout << "Enter Age: ";
                std::cin >> age;
                std::cout << "Enter Fullness Level (0-100): ";
                std::cin >> fullnessLevel;

                std::cout << "Choose Cat Type: 1. DomesticCat 2. FatCat 3. StrayCat: ";
                int type;
                std::cin >> type;

                switch (type) {
                    case 1: game.addCat(std::make_shared<DomesticCat>(name, age, fullnessLevel)); 
                        break;
                    case 2: game.addCat(std::make_shared<FatCat>(name, age, fullnessLevel)); 
                        break;
                    case 3: game.addCat(std::make_shared<StrayCat>(name, age, fullnessLevel)); 
                        break;
                    default: std::cout << "Invalid type.\n"; 
                }
                break;
            }

            case 3: { // Feed a Cat
                game.showCats();
                std::cout << "Select Cat Index: ";
                size_t index;
                if (!(std::cin >> index)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Invalid input. Please enter a number.\n";
                    continue;
                }
                
                std::cout << "Choose Food: 1. Fish 2. DryFood 3. Milk: ";
                int foodChoice;
                std::cin >> foodChoice;

                // Creating the chosen food object using smart pointer
                std::shared_ptr<Food> food;
                switch (foodChoice) {
                    case 1: food = std::make_shared<Fish>(); 
                        break;
                    case 2: food = std::make_shared<DryFood>(); 
                        break;
                    case 3: food = std::make_shared<Milk>(); 
                        break;
                    default: 
                        std::cout << "Invalid food choice.\n"; 
                        continue;
                }

                game.feedCat(index, food);
                break;
            }

            case 4: // Show Total Cats
                game.showTotalCats();
                break;

            case 5: { // Make a Cat Sound
                game.showCats();
                std::cout << "Choose a cat to make a sound: ";
                size_t index;
                if (!(std::cin >> index)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Invalid input. Please enter a number.\n";
                    continue;
                }
                game.makeCatSound(index);
                break;
            }

            case 6: // Exit
                running = false;
                std::cout << "Exiting the game. Goodbye!\n";
                break;

            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}





