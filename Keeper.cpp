// Keeper.cpp
// РЕАЛИЗАЦИЯ КОНТЕЙНЕРА Keeper

#include "Keeper.h"
#include "Fish.h"   // Включаем для dynamic_cast
#include "Bird.h"
#include "Cat.h"

// КОНСТРУКТОР ПО УМОЛЧАНИЮ
Keeper::Keeper() : size(0), capacity(10) {  // Начальная ёмкость = 10
    animals = new Animal*[capacity];  // ДИНАМИЧЕСКОЕ ВЫДЕЛЕНИЕ массива указателей
    std::cout << "Default constructor for Keeper called." << std::endl;
}

// КОНСТРУКТОР КОПИРОВАНИЯ (ГЛУБОКОЕ КОПИРОВАНИЕ)
Keeper::Keeper(const Keeper& other) : size(other.size), capacity(other.capacity) {
    animals = new Animal*[capacity];  // Новый массив
    for (int i = 0; i < size; ++i) {
        // ОПРЕДЕЛЯЕМ ТИП ОБЪЕКТА через dynamic_cast и создаём копию
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

// ДЕСТРУКТОР - освобождает ВСЮ память
Keeper::~Keeper() {
    for (int i = 0; i < size; ++i) {
        delete animals[i];  // Удаляем каждый объект
    }
    delete[] animals;       // Удаляем массив указателей
    std::cout << "Destructor for Keeper called." << std::endl;
}

// ОПЕРАТОР ПРИСВАИВАНИЯ (глубокое копирование)
Keeper& Keeper::operator=(const Keeper& other) {
    if (this != &other) {
        // 1. Освобождаем старую память
        for (int i = 0; i < size; ++i) {
            delete animals[i];
        }
        delete[] animals;
        
        // 2. Копируем данные
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

// МЕТОД РАСШИРЕНИЯ МАССИВА
void Keeper::resize() {
    capacity *= 2;  // Удваиваем ёмкость
    Animal** newAnimals = new Animal*[capacity];  // Новый больший массив
    for (int i = 0; i < size; ++i) {
        newAnimals[i] = animals[i];  // Копируем указатели
    }
    delete[] animals;      // Удаляем старый массив
    animals = newAnimals;  // Заменяем указатель
}

// ДОБАВЛЕНИЕ ЖИВОТНОГО
void Keeper::add(Animal* animal) {
    if (size >= capacity) {  // Если массив заполнен
        resize();            // Расширяем
    }
    animals[size++] = animal;  // Добавляем в конец
}

// УДАЛЕНИЕ ПО ИНДЕКСУ
void Keeper::remove(int index) {
    if (index < 0 || index >= size) {  // ПРОВЕРКА КОРРЕКТНОСТИ
        throw MyException("Invalid index for removal.");
    }
    delete animals[index];  // УДАЛЯЕМ ОБЪЕКТ
    for (int i = index; i < size - 1; ++i) {  // СДВИГ ЭЛЕМЕНТОВ
        animals[i] = animals[i + 1];
    }
    --size;  // Уменьшаем размер
}

// ВЫВОД ВСЕХ ЖИВОТНЫХ
void Keeper::printAll() const {
    for (int i = 0; i < size; ++i) {
        std::cout << "Index " << i << ": ";  // Показываем индекс
        animals[i]->print();  // ПОЛИМОРФНЫЙ ВЫЗОВ
    }
}

// РЕДАКТИРОВАНИЕ ПО ИНДЕКСУ
void Keeper::edit(int index) {
    if (index < 0 || index >= size) {
        throw MyException("Invalid index for editing.");
    }
    animals[index]->edit();  // ПОЛИМОРФНЫЙ ВЫЗОВ
}

// СОХРАНЕНИЕ В ФАЙЛ
void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);  // Открываем файл для записи
    if (!file.is_open()) {
        throw MyException("Failed to open file for saving.");
    }
    file << size << std::endl;  // Записываем количество
    
    for (int i = 0; i < size; ++i) {
        // ОПРЕДЕЛЯЕМ ТИП и записываем данные
        if (dynamic_cast<Fish*>(animals[i])) {
            Fish* f = dynamic_cast<Fish*>(animals[i]);
            file << "Fish " << f->getBreed() << " " << f->getColor() 
                 << " " << f->getDietType() << std::endl;
        } else if (dynamic_cast<Bird*>(animals[i])) {
            Bird* b = dynamic_cast<Bird*>(animals[i]);
            file << "Bird " << b->getBreed() << " " << b->getColor() 
                 << " " << b->getDiet() << " " << b->getHabitat() << std::endl;
        } else if (dynamic_cast<Cat*>(animals[i])) {
            Cat* c = dynamic_cast<Cat*>(animals[i]);
            file << "Cat " << c->getBreed() << " " << c->getColor() 
                 << " " << c->getOwnerFullName() << " " << c->getNickname() << std::endl;
        }
    }
    file.close();
}

// ЗАГРУЗКА ИЗ ФАЙЛА
void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);  // Открываем для чтения
    if (!file.is_open()) {
        throw MyException("Failed to open file for loading.");
    }
    
    // ОЧИЩАЕМ ТЕКУЩИЙ КОНТЕЙНЕР
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }
    size = 0;
    
    int newSize;
    file >> newSize;  // Читаем количество
    
    std::string type;
    while (size < newSize) {  // Читаем каждый объект
        file >> type;
        if (type == "Fish") {
            std::string b, c, dt;
            file >> b >> c >> dt;
            add(new Fish(b, c, dt));  // СОЗДАЁМ НОВЫЙ ОБЪЕКТ
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