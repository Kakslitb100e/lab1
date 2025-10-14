// Fish.cpp
#include "Fish.h"

Fish::Fish() : Animal(), diet_type("") {
    std::cout << "Default constructor for Fish called." << std::endl;
}

Fish::Fish(const std::string& b, const std::string& c, const std::string& dt)
    : Animal(b, c), diet_type(dt) {
    std::cout << "Parametrized constructor for Fish called." << std::endl;
}

Fish::Fish(const Fish& other) : Animal(other), diet_type(other.diet_type) {
    std::cout << "Copy constructor for Fish called." << std::endl;
}

Fish::~Fish() {
    std::cout << "Destructor for Fish called." << std::endl;
}

Fish& Fish::operator=(const Fish& other) {
    if (this != &other) {
        Animal::operator=(other);
        diet_type = other.diet_type;
    }
    std::cout << "Assignment operator for Fish called." << std::endl;
    return *this;
}

void Fish::print() const {
    std::cout << "Fish: Breed=" << breed << ", Color=" << color << ", Diet Type=" << diet_type << std::endl;
}

void Fish::edit() {
    std::string input;
    std::cout << "Edit Fish. Enter new breed (or empty to skip): ";
    std::getline(std::cin, input);
    if (!input.empty()) breed = input;
    std::cout << "Enter new color (or empty to skip): ";
    std::getline(std::cin, input);
    if (!input.empty()) color = input;
    std::cout << "Enter new diet type (or empty to skip): ";
    std::getline(std::cin, input);
    if (!input.empty()) diet_type = input;
}

std::string Fish::getDietType() const {
    return diet_type;
}

void Fish::setDietType(const std::string& dt) {
    diet_type = dt;
}