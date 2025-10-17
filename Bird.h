// Bird.h
// КЛАСС ПТИЦЫ - наследник Animal
// ДОПОЛНИТЕЛЬНЫЕ ПОЛЯ: чем питается, где обитает

#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

class Bird : public Animal {
private:
    std::string diet;     // Чем питается
    std::string habitat;  // Где обитает

public:
    // 1. КОНСТРУКТОР ПО УМОЛЧАНИЮ
    Bird();
    
    // 2. КОНСТРУКТОР С ПАРАМЕТРАМИ (порода, окрас, питание, место обитания)
    Bird(const std::string& b, const std::string& c, const std::string& d, const std::string& h);
    
    // 3. КОНСТРУКТОР КОПИРОВАНИЯ
    Bird(const Bird& other);
    
    // ВИРТУАЛЬНЫЙ ДЕСТРУКТОР
    ~Bird() override;
    
    // ОПЕРАТОР ПРИСВАИВАНИЯ
    Bird& operator=(const Bird& other);

    // ПЕРЕОПРЕДЕЛЕНИЕ ВИРТУАЛЬНЫХ МЕТОДОВ
    void print() const override;
    void edit() override;

    // GET/SET МЕТОДЫ
    std::string getDiet() const;
    void setDiet(const std::string& d);
    std::string getHabitat() const;
    void setHabitat(const std::string& h);
};

#endif