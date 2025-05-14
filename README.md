# **POO-Tema-2**

# **Feeding Hungry Cats Game**

This project is a simple text game where players can create, feed, and interact with different types of cats. The game demonstrates concepts of object-oriented programming (OOP) in C++, including inheritance, polymorphism, smart pointers, and exception handling.

---

## **1. Project Structure**

The project is organized into the following files:

* **`main.cpp`** – Entry point of the program, managing the main game loop and menu.
* **`Cat.hpp` / `Cat.cpp`** – Base class `Cat` and derived classes (`DomesticCat`, `FatCat`, `StrayCat`), implementing polymorphic behavior.
* **`Food.hpp` / `Food.cpp`** – Base class `Food` and derived classes (`Fish`, `DryFood`, `Milk`), providing different types of food for cats.
* **`GameState.hpp` / `GameState.cpp`** – Manages game state, including adding, displaying, and feeding cats.

---

## **2. Program Flow**

### **A. Initialization (`main.cpp`)**

* The main menu is displayed:

  * `1` – Show All Cats
  * `2` – Add a New Cat
  * `3` – Feed a Cat
  * `4` – Show Total Cats Registered
  * `5` – Display a Cat Sound
  * `6` – Exit
* User inputs are validated, and corresponding actions are executed.

### **B. Gameplay (`GameState.cpp`)**

* Cats can be added with specified types (DomesticCat, FatCat, StrayCat).
* Each cat has a fullness level, which can be increased by feeding them.
* Different foods (Fish, DryFood, Milk) have specific effects when fed.
* FatCat has a special bonus effect when fed.

### **C. Feeding Mechanism (`GameState.cpp`)**

* Users choose which cat to feed and what type of food to use.
* The fullness level is adjusted accordingly.
* If a cat's fullness exceeds 100, an exception (`FullnessTooHighException`) is thrown.

---

## **3. Class Details and Inheritance**

### **🔹 Cat Class Hierarchy (`Cat.hpp`)**

```cpp
Cat (abstract)
├── DomesticCat
├── FatCat
└── StrayCat
```

* **`Cat`** is an abstract base class with pure virtual functions for polymorphism.
* Derived classes override virtual methods like `sound()`, `getType()`, and `clone()`.

### **🔹 Food Class Hierarchy (`Food.hpp`)**

```cpp
Food (abstract)
├── Fish
├── DryFood
└── Milk
```

* **`Food`** is an abstract base class with pure virtual methods for polymorphic behavior.
* Derived classes provide specific feeding messages and sounds.

---

## **4. Example of Gameplay and Output**

```
=============================================
          FEEDING HUNGRY CATS GAME
=============================================
| 1. Show All Cats                          |
| 2. Add a New Cat                          |
| 3. Feed a Cat                             |
| 4. Show Total Cats Registered             |
| 5. Display a Cat Sound                    |
| 6. Exit                                   |
=============================================

Choose an option (1-6): 3

Feeding Chonky with Fish...

        *==== FISH =====*

             /`·.¸
            /¸...¸`:·
        ¸.·´  ¸   `·.¸.·´)
        : © ):´;      ¸  {
        `·.¸ `·  ¸.·´\`·¸)
            `\\´´\¸.·´

    This is a FatCat! Extra fullness bonus applied!
    Fullness after feeding: 90
      
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
  "I'm okay. I can eat more!"

Choose an option (1-6): 3

Feeding Chonky with Milk...

           *==== Milk =====*
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

Error: Fullness Level cannot exceed 100! Overfeeding alert.



Choose an option (1-6): 5

[ Domestic Cat - Mimi, Age: 3 ]

             /\_____/\
            /  o   o  \
           ( ==  ^  == )
            )         (
           (           )
          ( (  )   (  ) )
         (__(__)___(__)__)

       Sound: Purrr... meow!
```

---
## **5. Libraries Used**

| Library      | Purpose                        |
| ------------ | ------------------------------ |
| `<iostream>` | Console input and output.      |
| `<memory>`   | Smart pointers (`shared_ptr`). |
| `<vector>`   | Dynamic storage of objects.    |

---
## **6. Project Requirement**

## **1. Virtual Functions and Polymorphism**

### **A. Abstract Base Class with Pure Virtual Functions**

```cpp
class Cat {
public:
    virtual ~Cat() = default;

    // Pure Virtual Functions (Polymorphism)
    virtual std::shared_ptr<Cat> clone() const = 0;  // Pure Virtual Constructor
    virtual std::string getType() const = 0;         // Pure Virtual Function
    virtual void sound() const = 0;                  // Pure Virtual Function
};
```

### **B. Virtual Functions Called Through Base Pointer**

```cpp
std::shared_ptr<Cat> myCat = std::make_shared<DomesticCat>("Mimi", 3, 80);
myCat->sound(); // Outputs: Purrr... meow!
```

### **C. Virtual Constructor (Clone)**
```cpp
std::shared_ptr<Cat> DomesticCat::clone() const {
    return std::make_shared<DomesticCat>(*this);
}
```
### **D. Attributes as Base Class Pointers in Another Class (GameState)**

```cpp
class GameState {
private:
    std::vector<std::shared_ptr<Cat>> cats; 

public:
    void addCat(const std::shared_ptr<Cat>& cat);
    void makeCatSound(size_t index) const;
};
```

---
## **2. Copy Constructor**

```cpp
Cat::Cat(const Cat& other)
    : name(other.name), age(other.age), fullnessLevel(other.fullnessLevel) {}
```
---

## **3. Dynamic Cast**

```cpp
std::shared_ptr<Cat> myCat = std::make_shared<DomesticCat>("Mimi", 3, 80);
if (auto domesticCat = std::dynamic_pointer_cast<DomesticCat>(myCat)) {
    std::cout << "This is a Domestic Cat named " << domesticCat->getType() << "\n";
} else {
    std::cout << "This is NOT a Domestic Cat.\n";
}
```

---

## **4. Smart Pointers and Dynamic Memory Management**

```cpp
std::vector<std::shared_ptr<Cat>> cats;
```
```cpp
void GameState::addCat(const std::shared_ptr<Cat>& cat) {
    cats.push_back(cat); 
}
```

## **5. Exception Handling**

### **A. Custom Exception Class**

```cpp
class FullnessTooHighException : public std::runtime_error {
public:
    FullnessTooHighException() : std::runtime_error("Fullness Level cannot exceed 100! Overfeeding alert.") {}
};
```

### **B. Throwing and Catching Exceptions**

```cpp
void Cat::update(int value) {
    fullnessLevel += value;
    if (fullnessLevel > 100)
        throw FullnessTooHighException();
}

try {
    cats[index]->update(20);
} catch (const FullnessTooHighException& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}
```

---

## **6. Static Methods and Attributes**

```cpp
// Static method to get total Cat count
int Cat::getCatCount() { 
    return catCount; 
}
```

---

## **7. Use of STL and Const Correctness**

```cpp
std::vector<std::shared_ptr<Cat>> cats;
cats.push_back(std::make_shared<DomesticCat>("Mimi", 3, 80));

// Const Correctness
class Cat {
public:
    std::string getName() const { return name; }
    virtual void sound() const = 0;
};
```
## **7. Bibliography**

* **ASCII Art**  
  * [https://www.asciiart.eu/animals/cats](https://www.asciiart.eu/animals/cats)
  * [https://youtu.be/mbTMNME6Wak?si=co0XarY1UScX-Zqs](https://youtu.be/mbTMNME6Wak?si=co0XarY1UScX-Zqs)
