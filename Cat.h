// Cat.h
#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
private:
    std::string owner_full_name;
    std::string nickname;
public:
    Cat();
    Cat(const std::string& b, const std::string& c, const std::string& ofn, const std::string& n);
    Cat(const Cat& other);
    ~Cat() override;
    Cat& operator=(const Cat& other);

    void print() const override;
    void edit() override;

    std::string getOwnerFullName() const;
    void setOwnerFullName(const std::string& ofn);
    std::string getNickname() const;
    void setNickname(const std::string& n);
};

#endif