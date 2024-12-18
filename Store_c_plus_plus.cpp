// Store_c_plus_plus.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

#include "Store.h"
#include "Customer.h"
#include "Product.h"

size_t Store::m_product_counter = 0;


// Шаблонный класс для управления учетными записями сотрудников
template<typename T>
class EmployeeAccount {
private:
    std::string name;
    T salary;
    bool active;

public:
    EmployeeAccount(const std::string& name, T salary)
        : name(name), salary(salary), active(true) {}

    // Метод для изменения статуса сотрудника
    void setStatus(bool status) {
        active = status;
    }

    // Метод для изменения зарплаты сотрудника
    void setSalary(T newSalary) {
        if (newSalary >= 0) {
            salary = newSalary;
        }
        else {
            std::cerr << "Ошибка: зарплата не может быть отрицательной." << std::endl;
        }
    }

    // Метод для вывода информации о сотруднике
    void display() const {
        std::cout << "Сотрудник: " << name << ", Зарплата: " << salary << ", Активен: " << (active ? "Да" : "Нет") << std::endl;
    }
};


using namespace std;
int main()
{

	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    cout << "Hello World!\n";

    Store store;

    // Добавление товаров
    store.addProduct(Product("Книга", 10.0, 5));
    store.addProduct(Product("Ноутбук", 1000.0, 2));
    store.addProduct(Product("Телефон", 500.0, 3));

    // Добавление клиентов
    store.addCustomer(Customer("Иван", 2000.0));
    store.addCustomer(Customer("Мария", 1500.0));

    // Вывод информации о товарах и клиентах
    store.displayProducts();
    store.displayCustomers();

    // Покупка товара клиентом
    store.purchaseProduct(0, "Ноутбук", 1);

    // Вывод обновленной информации о товарах и клиентах
    store.displayProducts();
    store.displayCustomers();

    // Вывод общего количества товаров в магазине
    std::cout << "Общее количество товаров в магазине: " << Store::getTotalProducts() << std::endl;

    // Создание учетных записей сотрудников
    EmployeeAccount<float> emp1("Алексей", 5000.0);
    EmployeeAccount<float> emp2("Ольга", 6000.0);

    // Вывод информации о сотрудниках
    emp1.display();
    emp2.display();

    // Изменение статуса и зарплаты сотрудника
    emp1.setStatus(false);
    emp1.setSalary(5500.0);

    // Вывод обновленной информации о сотруднике
    emp1.display();

    return 0;
}

