// Fish.h
// КЛАСС РЫБЫ - наследник Animal
// ДОПОЛНИТЕЛЬНЫЕ ПОЛЯ: тип питания

#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish : public Animal {  // НАСЛЕДОВАНИЕ от базового класса
private:
    std::string diet_type;    // Тип питания (специфично для рыб)

public:
    // 1. КОНСТРУКТОР ПО УМОЛЧАНИЮ
    Fish();
    
    // 2. КОНСТРУКТОР С ПАРАМЕТРАМИ (порода, окрас, тип питания)
    Fish(const std::string& b, const std::string& c, const std::string& dt);
    
    // 3. КОНСТРУКТОР КОПИРОВАНИЯ
    Fish(const Fish& other);
    
    // ВИРТУАЛЬНЫЙ ДЕСТРУКТОР
    ~Fish() override;
    
    // ПЕРЕГРУЗКА ОПЕРАТОРА ПРИСВАИВАНИЯ
    Fish& operator=(const Fish& other);

    // ПЕРЕОПРЕДЕЛЕНИЕ ВИРТУАЛЬНЫХ МЕТОДОВ
    void print() const override;   // Вывод данных рыбы
    void edit() override;          // Редактирование данных рыбы

    // GET/SET МЕТОДЫ для типа питания
    std::string getDietType() const;
    void setDietType(const std::string& dt);
};

#endif