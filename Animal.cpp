// Animal.cpp
#include "Animal.h"

Animal::Animal() : breed(""), color("") {
    std::cout << "Default constructor for Animal called." << std::endl;
}

Animal::Animal(const std::string& b, const std::string& c) : breed(b), color(c) {
    std::cout << "Parametrized constructor for Animal called." << std::endl;
}

Animal::Animal(const Animal& other) : breed(other.breed), color(other.color) {
    std::cout << "Copy constructor for Animal called." << std::endl;
}

Animal::~Animal() {
    std::cout << "Destructor for Animal called." << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        breed = other.breed;
        color = other.color;
    }
    std::cout << "Assignment operator for Animal called." << std::endl;
    return *this;
}

std::string Animal::getBreed() const {
    return breed;
}

void Animal::setBreed(const std::string& b) {
    breed = b;
}

std::string Animal::getColor() const {
    return color;
}

void Animal::setColor(const std::string& c) {
    color = c;
}