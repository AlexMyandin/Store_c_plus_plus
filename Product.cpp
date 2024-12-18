#include "Product.h"
Product::Product() :m_name(""), m_price(0), m_quantity_in_store(0) {};

Product::Product(string name, float price, size_t quantity_in_store) : m_name(name), m_price(price), m_quantity_in_store(quantity_in_store) {};

Product::~Product() {};

bool Product::operator==(Product& prod) {
	 return prod.m_name == m_name && prod.m_price == m_price && prod.m_quantity_in_store == m_quantity_in_store;
}

// Перегрузка оператора += для увеличения количества товара
Product& Product::operator+=(int amount) {
    if (amount > 0) {
        m_quantity_in_store += amount;
    }
    else {
        std::cerr << "Ошибка: количество товара должно быть положительным." << std::endl;
    }
    return *this;
}

// Перегрузка оператора -= для уменьшения количества товара
Product& Product::operator-=(int amount) {
    if (amount > 0 && m_quantity_in_store >= amount) {
        m_quantity_in_store -= amount;
    }
    else {
        std::cerr << "Ошибка: недостаточно товара на складе." << std::endl;
    }
    return *this;
}


string Product::getName() {return m_name;}
float Product::getPrice() {return m_price;}
size_t Product::getQuantity_in_store() { return m_quantity_in_store;};

void Product::getInfo() {
	cout << "Продукт: " << m_name << ", " << "Цена: " << m_price << ", " << "Количество на складе: " << m_quantity_in_store << "\n";
}
void Product::setPrice(float price) {m_price = price;};

void Product::setQuantity_in_store(size_t quantity) {m_quantity_in_store = quantity;};

void Product::display() const {
    std::cout << "Товар: " << m_name << ", Цена: " << m_price << ", Количество: " << m_quantity_in_store << std::endl;
}
