// Cat.cpp
// РЕАЛИЗАЦИЯ КЛАССА Cat

#include "Cat.h"

// КОНСТРУКТОРЫ, ДЕСТРУКТОР, ОПЕРАТОР - аналогично другим классам
Cat::Cat() : Animal(), owner_full_name(""), nickname("") {
    std::cout << "Default constructor for Cat called." << std::endl;
}

Cat::Cat(const std::string& b, const std::string& c, const std::string& ofn, const std::string& n)
    : Animal(b, c), owner_full_name(ofn), nickname(n) {
    std::cout << "Parametrized constructor for Cat called." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), owner_full_name(other.owner_full_name), nickname(other.nickname) {
    std::cout << "Copy constructor for Cat called." << std::endl;
}

Cat::~Cat() {
    std::cout << "Destructor for Cat called." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        owner_full_name = other.owner_full_name;
        nickname = other.nickname;
    }
    std::cout << "Assignment operator for Cat called." << std::endl;
    return *this;
}

// МЕТОД ВЫВОДА
void Cat::print() const {
    std::cout << "Cat: Breed=" << breed << ", Color=" << color 
              << ", Owner=" << owner_full_name << ", Nickname=" << nickname << std::endl;
}

// МЕТОД РЕДАКТИРОВАНИЯ
void Cat::edit() {
    std::string input;
    std::cout << "Edit Cat. Enter new breed (or empty to skip): ";
    std::getline(std::cin, input);
    if (!input.empty()) breed = input;
    
    std::cout << "Enter new color (or empty to skip): ";
    std::getline(std::cin, input);
    if (!input.empty()) color = input;
    
    std::cout << "Enter new owner full name (or empty to skip): ";
    std::getline(std::cin, input);
    if (!input.empty()) owner_full_name = input;
    
    std::cout << "Enter new nickname (or empty to skip): ";
    std::getline(std::cin, input);
    if (!input.empty()) nickname = input;
}

// GET/SET МЕТОДЫ
std::string Cat::getOwnerFullName() const { return owner_full_name; }
void Cat::setOwnerFullName(const std::string& ofn) { owner_full_name = ofn; }
std::string Cat::getNickname() const { return nickname; }
void Cat::setNickname(const std::string& n) { nickname = n; }