// Animal.h
// БАЗОВЫЙ АБСТРАКТНЫЙ КЛАСС для всех животных (рыбы, птицы, кошки)
// Содержит общие поля: порода и окрас

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>     // Для вывода в консоль
#include <string>       // Для работы со строками
#include <exception>    // Для создания пользовательских исключений

// СОБСТВЕННОЕ ИСКЛЮЧЕНИЕ для обработки ошибок в программе
class MyException : public std::exception {
public:
    // Конструктор исключения с текстовым сообщением
    MyException(const std::string& msg) : message(msg) {}
    
    // Переопределение метода what() для получения текста ошибки
    const char* what() const noexcept override {
        return message.c_str();
    }
private:
    std::string message;  // Текст ошибки
};

// АБСТРАКТНЫЙ БАЗОВЫЙ КЛАСС Animal (чисто виртуальные методы делают его абстрактным)
class Animal {
protected:
    std::string breed;    // Порода (общее поле для всех животных)
    std::string color;    // Окрас (общее поле для всех животных)

public:
    // 1. КОНСТРУКТОР ПО УМОЛЧАНИЮ - инициализирует пустыми строками
    Animal();
    
    // 2. КОНСТРУКТОР С ПАРАМЕТРАМИ - принимает породу и окрас
    Animal(const std::string& b, const std::string& c);
    
    // 3. КОНСТРУКТОР КОПИРОВАНИЯ - создает копию другого объекта Animal
    Animal(const Animal& other);
    
    // ВИРТУАЛЬНЫЙ ДЕСТРУКТОР - обязателен для полиморфизма
    virtual ~Animal();
    
    // ПЕРЕГРУЗКА ОПЕРАТОРА ПРИСВАИВАНИЯ - глубокое копирование
    Animal& operator=(const Animal& other);

    // ЧИСТО ВИРТУАЛЬНЫЕ МЕТОДЫ (делают класс абстрактным)
    virtual void print() const = 0;   // Вывод информации об объекте
    virtual void edit() = 0;          // Редактирование данных объекта

    // GET/SET МЕТОДЫ для породы
    std::string getBreed() const;     // Получить породу
    void setBreed(const std::string& b);  // Установить породу
    
    // GET/SET МЕТОДЫ для окраса
    std::string getColor() const;     // Получить окрас
    void setColor(const std::string& c);  // Установить окрас
};

#endif