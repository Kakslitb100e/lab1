// Cat.h
// КЛАСС КОШКИ - наследник Animal
// ДОПОЛНИТЕЛЬНЫЕ ПОЛЯ: ФИО владельца, кличка

#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
private:
    std::string owner_full_name;  // ФИО владельца
    std::string nickname;         // Кличка

public:
    // 1. КОНСТРУКТОР ПО УМОЛЧАНИЮ
    Cat();
    
    // 2. КОНСТРУКТОР С ПАРАМЕТРАМИ
    Cat(const std::string& b, const std::string& c, const std::string& ofn, const std::string& n);
    
    // 3. КОНСТРУКТОР КОПИРОВАНИЯ
    Cat(const Cat& other);
    
    // ДЕСТРУКТОР
    ~Cat() override;
    
    // ОПЕРАТОР ПРИСВАИВАНИЯ
    Cat& operator=(const Cat& other);

    // ПЕРЕОПРЕДЕЛЕНИЕ МЕТОДОВ
    void print() const override;
    void edit() override;

    // GET/SET МЕТОДЫ
    std::string getOwnerFullName() const;
    void setOwnerFullName(const std::string& ofn);
    std::string getNickname() const;
    void setNickname(const std::string& n);
};

#endif