#include <iostream>
#include <string>
#include <windows.h>
#include <locale>

class Product {
private:
    std::string name;
    double price;
    std::string location;
protected:
    std::string description;
    double expiration_date;
public:
    //конструктор полного заполнения
    Product(std::string a, std::string b, double c, double d, std::string e) {
        name = a;
        description = b;
        if (c < 0) {
            std::cout << "Ошибка: цена не может быть отрицательной" << std::endl;
            price = 0.0;
        }
        else {
            price = c;
        }
        if (d < 0) {
            std::cout << "Ошибка" << std::endl;
            d = 0.0;
        }
        else {
            expiration_date = d;
        }
        location = e;
    }
    //Конструктор по умолчанию
    Product() {
        name = "Не указано";
        description = "Нет описания";
        price = 0.0;
        expiration_date = 0.0;
        location = "Неизвестно";
    }
    // Конструктор копирования
    Product(const Product& other) {
        name = other.name;
        description = other.description;
        if (other.expiration_date >= 0) {
            expiration_date = other.expiration_date;
        }
        else {
            std::cerr << "Ошибка при копировании" << std::endl;
            expiration_date = 0.0;
        }
        location = other.location;
        if (other.price >= 0) {
            price = other.price;
        }
        else {
            std::cerr << "Ошибка при копировании: отрицательная цена" << std::endl;
            price = 0.0;
        }
    }
    // Деструктор
    ~Product() {
        std::cout << "Объект Product с названием " << name << " уничтожен" << std::endl;
    }
    //геттеры
    std::string getName() const {
        return name;
    }
    double getPrice() const {
        return price;
    }
    std::string getLocation() const {
        return location;
    }
    double getExpiration_date() const {
        return expiration_date;
    }
    //сеттер на цену
    void setPrice(double newPrice) {
        if (newPrice >= 0) {
            price = newPrice;
        }
        else {
            std::cout << "Неккоректная цена" << std::endl;
        }
    }
    //вывод всей информации
    void displayInfo() const {
        std::cout << name << std::endl;
        std::cout << price << std::endl;
        std::cout << location << std::endl;
        std::cout << description << std::endl;
        std::cout << expiration_date << std::endl;
    }
    //вывод,где получить товар
    void locationInfo() {
        std::cout << location << std::endl;
    }
    void setExpirationDate(double newExpirationDate) {
        if (newExpirationDate < 0) {
            std::cout << "Ошибка: дата не может быть отрицательной" << std::endl;
            return;
        }

        if (newExpirationDate > expiration_date) {
            std::cout << "Ошибка" << std::endl;
            return;
        }

        expiration_date = newExpirationDate;
        std::cout << "Срок хранения успешно изменен" << std::endl;
    }


};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUSSIAN");
    Product product1("Молоко","Топлённое",80,8,"склад1");
    product1.setPrice(100);
    product1.setExpirationDate(9);
    product1.displayInfo();

    return 0;
}
