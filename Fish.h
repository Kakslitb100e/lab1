// Fish.h
#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish : public Animal {
private:
    std::string diet_type;
public:
    Fish();
    Fish(const std::string& b, const std::string& c, const std::string& dt);
    Fish(const Fish& other);
    ~Fish() override;
    Fish& operator=(const Fish& other);

    void print() const override;
    void edit() override;

    std::string getDietType() const;
    void setDietType(const std::string& dt);
};

#endif