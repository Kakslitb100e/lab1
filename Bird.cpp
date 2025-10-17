// Bird.cpp
// РЕАЛИЗАЦИЯ КЛАССА Bird

#include "Bird.h"

// КОНСТРУКТОРЫ, ДЕСТРУКТОР, ОПЕРАТОР ПРИСВАИВАНИЯ - аналогично Fish
Bird::Bird() : Animal(), diet(""), habitat("") {
    std::cout << "Default constructor for Bird called." << std::endl;
}

Bird::Bird(const std::string& b, const std::string& c, const std::string& d, const std::string& h)
    : Animal(b, c), diet(d), habitat(h) {
    std::cout << "Parametrized constructor for Bird called." << std::endl;
}

Bird::Bird(const Bird& other) : Animal(other), diet(other.diet), habitat(other.habitat) {
    std::cout << "Copy constructor for Bird called." << std::endl;
}

Bird::~Bird() {
    std::cout << "Destructor for Bird called." << std::endl;
}

Bird& Bird::operator=(const Bird& other) {
    if (this != &other) {
        Animal::operator=(other);
        diet = other.diet;
        habitat = other.habitat;
    }
    std::cout << "Assignment operator for Bird called." << std::endl;
    return *this;
}

// МЕТОД ВЫВОДА
void Bird::print() const {
    std::cout << "Bird: Breed=" << breed << ", Color=" << color 
              << ", Diet=" << diet << ", Habitat=" << habitat << std::endl;
}

// МЕТОД РЕДАКТИРОВАНИЯ
void Bird::edit() {
    std::string input;
    std::cout << "Edit Bird. Enter new breed (or empty to skip): ";
    std::getline(std::cin, input);
    if (!input.empty()) breed = input;
    
    std::cout << "Enter new color (or empty to skip): ";
    std::getline(std::cin, input);
    if (!input.empty()) color = input;
    
    std::cout << "Enter new diet (or empty to skip): ";
    std::getline(std::cin, input);
    if (!input.empty()) diet = input;
    
    std::cout << "Enter new habitat (or empty to skip): ";
    std::getline(std::cin, input);
    if (!input.empty()) habitat = input;
}

// GET/SET МЕТОДЫ
std::string Bird::getDiet() const { return diet; }
void Bird::setDiet(const std::string& d) { diet = d; }
std::string Bird::getHabitat() const { return habitat; }
void Bird::setHabitat(const std::string& h) { habitat = h; }