// Animal.h
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <exception>

class MyException : public std::exception {
public:
    MyException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
private:
    std::string message;
};

class Animal {
protected:
    std::string breed;
    std::string color;
public:
    Animal();
    Animal(const std::string& b, const std::string& c);
    Animal(const Animal& other);
    virtual ~Animal();
    Animal& operator=(const Animal& other);

    virtual void print() const = 0;
    virtual void edit() = 0;

    std::string getBreed() const;
    void setBreed(const std::string& b);
    std::string getColor() const;
    void setColor(const std::string& c);
};

#endif