// Fish.cpp
// РЕАЛИЗАЦИЯ КЛАССА Fish

#include "Fish.h"

// КОНСТРУКТОР ПО УМОЛЧАНИЮ
Fish::Fish() : Animal(), diet_type("") {
    std::cout << "Default constructor for Fish called." << std::endl;
}

// КОНСТРУКТОР С ПАРАМЕТРАМИ
Fish::Fish(const std::string& b, const std::string& c, const std::string& dt)
    : Animal(b, c), diet_type(dt) {  // Вызываем конструктор базового класса
    std::cout << "Parametrized constructor for Fish called." << std::endl;
}

// КОНСТРУКТОР КОПИРОВАНИЯ
Fish::Fish(const Fish& other) : Animal(other), diet_type(other.diet_type) {
    std::cout << "Copy constructor for Fish called." << std::endl;
}

// ДЕСТРУКТОР
Fish::~Fish() {
    std::cout << "Destructor for Fish called." << std::endl;
}

// ОПЕРАТОР ПРИСВАИВАНИЯ
Fish& Fish::operator=(const Fish& other) {
    if (this != &other) {
        Animal::operator=(other);     // Присваиваем поля базового класса
        diet_type = other.diet_type;  // Присваиваем специфическое поле
    }
    std::cout << "Assignment operator for Fish called." << std::endl;
    return *this;
}

// ПЕРЕОПРЕДЕЛЁННЫЙ МЕТОД ВЫВОДА
void Fish::print() const {
    std::cout << "Fish: Breed=" << breed << ", Color=" << color 
              << ", Diet Type=" << diet_type << std::endl;
}

// ПЕРЕОПРЕДЕЛЁННЫЙ МЕТОД РЕДАКТИРОВАНИЯ
void Fish::edit() {
    std::string input;
    std::cout << "Edit Fish. Enter new breed (or empty to skip): ";
    std::getline(std::cin, input);
    if (!input.empty()) breed = input;  // Изменяем только если не пусто
    
    std::cout << "Enter new color (or empty to skip): ";
    std::getline(std::cin, input);
    if (!input.empty()) color = input;
    
    std::cout << "Enter new diet type (or empty to skip): ";
    std::getline(std::cin, input);
    if (!input.empty()) diet_type = input;
}

// GET/SET МЕТОДЫ
std::string Fish::getDietType() const {
    return diet_type;
}

void Fish::setDietType(const std::string& dt) {
    diet_type = dt;
}