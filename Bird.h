// Bird.h
#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

class Bird : public Animal {
private:
    std::string diet;
    std::string habitat;
public:
    Bird();
    Bird(const std::string& b, const std::string& c, const std::string& d, const std::string& h);
    Bird(const Bird& other);
    ~Bird() override;
    Bird& operator=(const Bird& other);

    void print() const override;
    void edit() override;

    std::string getDiet() const;
    void setDiet(const std::string& d);
    std::string getHabitat() const;
    void setHabitat(const std::string& h);
};

#endif