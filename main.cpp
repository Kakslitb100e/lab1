// main.cpp
// ГЛАВНАЯ ФУНКЦИЯ - пользовательский интерфейс с меню

#include "Keeper.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"
#include <iostream>
#include <string>

int main() {
    Keeper keeper;  // СОЗДАЁМ КОНТЕЙНЕР
    int choice;
    
    // ОСНОВНОЙ ЦИКЛ МЕНЮ
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Fish\n";
        std::cout << "2. Add Bird\n";
        std::cout << "3. Add Cat\n";
        std::cout << "4. Remove animal by index\n";
        std::cout << "5. Edit animal by index\n";
        std::cout << "6. Print all animals\n";
        std::cout << "7. Save to file\n";
        std::cout << "8. Load from file\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();  // ОЧИЩАЕМ БУФЕР для getline

        // ОБРАБОТКА ВЫБОРА ПОЛЬЗОВАТЕЛЯ в try-catch
        try {
            if (choice == 1) {  // ДОБАВИТЬ РЫБУ
                std::string breed, color, diet_type;
                std::cout << "Enter breed: ";
                std::getline(std::cin, breed);
                std::cout << "Enter color: ";
                std::getline(std::cin, color);
                std::cout << "Enter diet type: ";
                std::getline(std::cin, diet_type);
                keeper.add(new Fish(breed, color, diet_type));  // СОЗДАЁМ И ДОБАВЛЯЕМ
            } 
            else if (choice == 2) {  // ДОБАВИТЬ ПТИЦУ
                std::string breed, color, diet, habitat;
                std::cout << "Enter breed: "; std::getline(std::cin, breed);
                std::cout << "Enter color: "; std::getline(std::cin, color);
                std::cout << "Enter diet: "; std::getline(std::cin, diet);
                std::cout << "Enter habitat: "; std::getline(std::cin, habitat);
                keeper.add(new Bird(breed, color, diet, habitat));
            } 
            else if (choice == 3) {  // ДОБАВИТЬ КОШКУ
                std::string breed, color, owner, nickname;
                std::cout << "Enter breed: "; std::getline(std::cin, breed);
                std::cout << "Enter color: "; std::getline(std::cin, color);
                std::cout << "Enter owner full name: "; std::getline(std::cin, owner);
                std::cout << "Enter nickname: "; std::getline(std::cin, nickname);
                keeper.add(new Cat(breed, color, owner, nickname));
            } 
            else if (choice == 4) {  // УДАЛИТЬ
                int index;
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                keeper.remove(index);
            } 
            else if (choice == 5) {  // РЕДАКТИРОВАТЬ
                int index;
                std::cout << "Enter index to edit: ";
                std::cin >> index;
                std::cin.ignore();
                keeper.edit(index);
            } 
            else if (choice == 6) {  // ВЫВЕСТИ ВСЕ
                keeper.printAll();
            } 
            else if (choice == 7) {  // СОХРАНИТЬ
                std::string filename;
                std::cout << "Enter filename to save: ";
                std::getline(std::cin, filename);
                keeper.saveToFile(filename);
                std::cout << "Saved successfully!" << std::endl;
            } 
            else if (choice == 8) {  // ЗАГРУЗИТЬ
                std::string filename;
                std::cout << "Enter filename to load: ";
                std::getline(std::cin, filename);
                keeper.loadFromFile(filename);
                std::cout << "Loaded successfully!" << std::endl;
            } 
            else if (choice == 0) {
                std::cout << "Exiting..." << std::endl;
            } 
            else {
                throw MyException("Invalid menu choice.");
            }
        } 
        
        // ЛОВИМ ВСЕ ИСКЛЮЧЕНИЯ
        catch (const MyException& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Standard exception: " << e.what() << std::endl;
        }
    } while (choice != 0);  // ПОВТОРЯЕМ, ПОКА НЕ 0

    return 0;  // ДЕСТРУКТОР Keeper вызовется АВТОМАТИЧЕСКИ
}