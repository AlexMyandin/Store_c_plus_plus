#include "Customer.h"


Customer::Customer() :m_name(""), m_balance(0) {};
Customer::Customer(string name, float balance) : m_name(name), m_balance(balance) {};
Customer::~Customer() {};

void Customer::deposit(float summa) {
	m_balance += summa;
}

// Метод для покупки товара
bool  Customer::purchase(Product& product, int quantity) {
    if (quantity <= 0) {
        std::cerr << "Ошибка: количество товара должно быть положительным." << std::endl;
        return false;
    }

    float totalCost = product.getPrice() * quantity;
    if (totalCost > m_balance) {
        std::cerr << "Ошибка: недостаточно средств на счете." << std::endl;
        return false;
    }

    if (product.getQuantity_in_store() < quantity) {
        std::cerr << "Ошибка: недостаточно товара на складе." << std::endl;
        return false;
    }

    m_balance -= totalCost;
    product -= quantity;
    std::cout <<"Покупатель:"<<m_name << ", Покупка совершена: " << quantity << " шт. " << product.getName() << " за " << totalCost << std::endl;
    return true;
}

float Customer::getBalance() {
	return m_balance;
};

void Customer::display() const {
    std::cout << "Клиент: " << m_name << ", Баланс: " << m_balance << std::endl;
}