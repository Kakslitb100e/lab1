// Keeper.h
// КОНТЕЙНЕРНЫЙ КЛАСС для хранения и управления объектами животных
// РЕАЛИЗУЕТ ДИНАМИЧЕСКИЙ МАССИВ указателей на Animal*

#ifndef KEEPER_H
#define KEEPER_H

#include "Animal.h"
#include <fstream>  // Для работы с файлами

class Keeper {
private:
    Animal** animals;   // ДИНАМИЧЕСКИЙ МАССИВ указателей на объекты Animal
    int size;           // ТЕКУЩЕЕ количество элементов
    int capacity;       // ЁМКОСТЬ массива (для динамического расширения)
    
    // ПРИВАТНЫЙ МЕТОД для увеличения размера массива
    void resize();

public:
    // 1. КОНСТРУКТОРЫ И ДЕСТРУКТОР
    Keeper();                           // По умолчанию
    Keeper(const Keeper& other);        // Копирования
    ~Keeper();                          // Освобождение памяти
    Keeper& operator=(const Keeper& other);  // Присваивания

    // ОСНОВНЫЕ МЕТОДЫ РАБОТЫ С КОНТЕЙНЕРОМ
    void add(Animal* animal);           // Добавить животное
    void remove(int index);             // Удалить по индексу
    void printAll() const;              // Вывести все
    void edit(int index);               // Редактировать по индексу
    
    // РАБОТА С ФАЙЛАМИ
    void saveToFile(const std::string& filename) const;  // Сохранить в файл
    void loadFromFile(const std::string& filename);      // Загрузить из файла

    // GET МЕТОД
    int getSize() const;                // Получить текущее количество
};

#endif