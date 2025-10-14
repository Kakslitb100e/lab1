// Keeper.cpp
#include "Keeper.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"

Keeper::Keeper() : size(0), capacity(10) {
    animals = new Animal*[capacity];
    std::cout << "Default constructor for Keeper called." << std::endl;
}

Keeper::Keeper(const Keeper& other) : size(other.size), capacity(other.capacity) {
    animals = new Animal*[capacity];
    for (int i = 0; i < size; ++i) {
        if (dynamic_cast<Fish*>(other.animals[i])) {
            animals[i] = new Fish(*dynamic_cast<Fish*>(other.animals[i]));
        } else if (dynamic_cast<Bird*>(other.animals[i])) {
            animals[i] = new Bird(*dynamic_cast<Bird*>(other.animals[i]));
        } else if (dynamic_cast<Cat*>(other.animals[i])) {
            animals[i] = new Cat(*dynamic_cast<Cat*>(other.animals[i]));
        }
    }
    std::cout << "Copy constructor for Keeper called." << std::endl;
}

Keeper::~Keeper() {
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }
    delete[] animals;
    std::cout << "Destructor for Keeper called." << std::endl;
}

Keeper& Keeper::operator=(const Keeper& other) {
    if (this != &other) {
        for (int i = 0; i < size; ++i) {
            delete animals[i];
        }
        delete[] animals;
        size = other.size;
        capacity = other.capacity;
        animals = new Animal*[capacity];
        for (int i = 0; i < size; ++i) {
            if (dynamic_cast<Fish*>(other.animals[i])) {
                animals[i] = new Fish(*dynamic_cast<Fish*>(other.animals[i]));
            } else if (dynamic_cast<Bird*>(other.animals[i])) {
                animals[i] = new Bird(*dynamic_cast<Bird*>(other.animals[i]));
            } else if (dynamic_cast<Cat*>(other.animals[i])) {
                animals[i] = new Cat(*dynamic_cast<Cat*>(other.animals[i]));
            }
        }
    }
    std::cout << "Assignment operator for Keeper called." << std::endl;
    return *this;
}

void Keeper::resize() {
    capacity *= 2;
    Animal** newAnimals = new Animal*[capacity];
    for (int i = 0; i < size; ++i) {
        newAnimals[i] = animals[i];
    }
    delete[] animals;
    animals = newAnimals;
}

void Keeper::add(Animal* animal) {
    if (size >= capacity) {
        resize();
    }
    animals[size++] = animal;
}

void Keeper::remove(int index) {
    if (index < 0 || index >= size) {
        throw MyException("Invalid index for removal.");
    }
    delete animals[index];
    for (int i = index; i < size - 1; ++i) {
        animals[i] = animals[i + 1];
    }
    --size;
}

void Keeper::printAll() const {
    for (int i = 0; i < size; ++i) {
        std::cout << "Index " << i << ": ";
        animals[i]->print();
    }
}

void Keeper::edit(int index) {
    if (index < 0 || index >= size) {
        throw MyException("Invalid index for editing.");
    }
    animals[index]->edit();
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw MyException("Failed to open file for saving.");
    }
    file << size << std::endl;
    for (int i = 0; i < size; ++i) {
        if (dynamic_cast<Fish*>(animals[i])) {
            Fish* f = dynamic_cast<Fish*>(animals[i]);
            file << "Fish " << f->getBreed() << " " << f->getColor() << " " << f->getDietType() << std::endl;
        } else if (dynamic_cast<Bird*>(animals[i])) {
            Bird* b = dynamic_cast<Bird*>(animals[i]);
            file << "Bird " << b->getBreed() << " " << b->getColor() << " " << b->getDiet() << " " << b->getHabitat() << std::endl;
        } else if (dynamic_cast<Cat*>(animals[i])) {
            Cat* c = dynamic_cast<Cat*>(animals[i]);
            file << "Cat " << c->getBreed() << " " << c->getColor() << " " << c->getOwnerFullName() << " " << c->getNickname() << std::endl;
        }
    }
    file.close();
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw MyException("Failed to open file for loading.");
    }
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }
    size = 0;
    int newSize;
    file >> newSize;
    std::string type;
    while (size < newSize) {
        file >> type;
        if (type == "Fish") {
            std::string b, c, dt;
            file >> b >> c >> dt;
            add(new Fish(b, c, dt));
        } else if (type == "Bird") {
            std::string b, c, d, h;
            file >> b >> c >> d >> h;
            add(new Bird(b, c, d, h));
        } else if (type == "Cat") {
            std::string b, c, ofn, n;
            file >> b >> c >> ofn >> n;
            add(new Cat(b, c, ofn, n));
        } else {
            throw MyException("Unknown animal type in file.");
        }
    }
    file.close();
}

int Keeper::getSize() const {
    return size;
}