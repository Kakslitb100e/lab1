// Keeper.h
#ifndef KEEPER_H
#define KEEPER_H

#include "Animal.h"
#include <fstream>

class Keeper {
private:
    Animal** animals;
    int size;
    int capacity;
    void resize();

public:
    Keeper();
    Keeper(const Keeper& other);
    ~Keeper();
    Keeper& operator=(const Keeper& other);

    void add(Animal* animal);
    void remove(int index);
    void printAll() const;
    void edit(int index);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    int getSize() const;
};

#endif