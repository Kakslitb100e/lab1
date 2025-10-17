// Animal.cpp
// РЕАЛИЗАЦИЯ МЕТОДОВ БАЗОВОГО КЛАССА Animal

#include "Animal.h"

// КОНСТРУКТОР ПО УМОЛЧАНИЮ
Animal::Animal() : breed(""), color("") {
    // Выводим сообщение о вызове конструктора (требование задания)
    std::cout << "Default constructor for Animal called." << std::endl;
}

// КОНСТРУКТОР С ПАРАМЕТРАМИ
Animal::Animal(const std::string& b, const std::string& c) : breed(b), color(c) {
    std::cout << "Parametrized constructor for Animal called." << std::endl;
}

// КОНСТРУКТОР КОПИРОВАНИЯ
Animal::Animal(const Animal& other) : breed(other.breed), color(other.color) {
    std::cout << "Copy constructor for Animal called." << std::endl;
}

// ВИРТУАЛЬНЫЙ ДЕСТРУКТОР
Animal::~Animal() {
    std::cout << "Destructor for Animal called." << std::endl;
}

// ПЕРЕГРУЗКА ОПЕРАТОРА ПРИСВАИВАНИЯ
Animal& Animal::operator=(const Animal& other) {
    // Защита от самоприсваивания (this != &other)
    if (this != &other) {
        breed = other.breed;      // Копируем породу
        color = other.color;      // Копируем окрас
    }
    std::cout << "Assignment operator for Animal called." << std::endl;
    return *this;  // Возвращаем ссылку на текущий объект
}

// GET/SET МЕТОДЫ для породы
std::string Animal::getBreed() const {
    return breed;
}

void Animal::setBreed(const std::string& b) {
    breed = b;
}

// GET/SET МЕТОДЫ для окраса
std::string Animal::getColor() const {
    return color;
}

void Animal::setColor(const std::string& c) {
    color = c;
}