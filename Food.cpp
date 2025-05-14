#include "Food.hpp"       
#include <iostream>       
#include <memory>        

// Default constructor - initializes a generic Food object
Food::Food() {}

// Destructor - ensures proper cleanup of Food objects
Food::~Food() {}

// Static Factory Method - creates a shared pointer to a Fish object
std::shared_ptr<Food> Food::createFish() { 
    return std::make_shared<Fish>(); 
}

// Static Factory Method - creates a shared pointer to a DryFood object
std::shared_ptr<Food> Food::createDryFood() { 
    return std::make_shared<DryFood>(); 
}

// Static Factory Method - creates a shared pointer to a Milk object
std::shared_ptr<Food> Food::createMilk() { 
    return std::make_shared<Milk>(); 
}



// Fish Class Methods 

// Default constructor - creates a Fish object and displays a message
Fish::Fish() { 
    std::cout << "Fish created\n"; 
}

// Destructor - destroys the Fish object and displays a message
Fish::~Fish() { 
    std::cout << "Fish destroyed\n"; 
}

// treat() - displays the type of treat (specific to Fish)
void Fish::treat() { 
    std::cout << "Treat: Fish\n"; 
}

// eat() - displays the sound of eating (specific to Fish)
void Fish::eat() { 
    std::cout << R"(


        *==== FISH =====*

             /`·.¸
            /¸...¸`:·
        ¸.·´  ¸   `·.¸.·´)
        : © ):´;      ¸  {
        `·.¸ `·  ¸.·´\`·¸)
            `\\´´\¸.·´



    
    )" << "\n";
}



// DryFood Class Methods 

// Default constructor - creates a DryFood object and displays a message
DryFood::DryFood() { 
    std::cout << "DryFood created\n"; 
}

// Destructor - destroys the DryFood object and displays a message
DryFood::~DryFood() { 
    std::cout << "DryFood destroyed\n"; 
}

// treat() - displays the type of treat (specific to DryFood)
void DryFood::treat() { 
    std::cout << "Treat: DryFood\n"; 
}

// eat() - displays the sound of eating (specific to DryFood)
void DryFood::eat() { 
    std::cout << R"(


        *==== DRY FOOD =====*

                           
          ___,.-------..____
     _,-'' xxxxxxxxxxxxxxxxx`'-.
  ;' xxxxxxxxxxxxxxxxxxxxxxxxx  :  
  (xxxxxxxxxxxxxxxxxxxxxxxxxxxxx  )
   :.xxxxxxxxxxxxxxxxxxxxxxxxx    :
    `.`--.___  xxxxxxxx _____-- .'
      `.     ``-------''     ,'
         -.               ,-
            `-._______.-'


    )" << "\n";
}



// Milk Class Methods 

// Default constructor - creates a Milk object and displays a message
Milk::Milk() { 
    std::cout << "Milk created\n"; 
}

// Destructor - destroys the Milk object and displays a message
Milk::~Milk() { 
    std::cout << "Milk destroyed\n"; 
}

// treat() - displays the type of treat (specific to Milk)
void Milk::treat() { 
    std::cout << "Treat: Milk\n"; 
}

// eat() - displays the sound of eating (specific to Milk)
void Milk::eat() { 
    std::cout << R"(

           *==== MILK =====*

               _________
              | _______ |
             / \         \
            /___\_________\
            |   | \       |
            |   |  \      |
            |   |   \     |
            |   | M  \    |
            |   |     \   |
            |   |\  I  \  |
            |   | \     \ |
            |   |  \  L  \|
            |   |   \     |
            |   |    \  K |
            |   |     \   |
            |   |      \  |
            |___|_______\_|

    
    )" << "\n";
}
