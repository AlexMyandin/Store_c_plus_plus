
#include "Store.h"
#include "Customer.h"

#include <type_traits>


Store::Store() {};
Store::Store(vector<Product>& products, vector<Customer>& customers): m_products(products), m_customers(customers) {};
Store::Store(Store& other_store) : m_products(other_store.m_products), m_customers(other_store.m_customers) {};
Store::~Store() {};

void Store::getInfoCust(Customer& cust) {
	cout <<"Имя клиента: " << cust.m_name << "Баланс:" << cust.m_balance<<endl;
};

// Метод для добавления товара
void Store::addProduct(const Product& product) {
    m_products.push_back(product);
    m_product_counter += 1;
}

// Метод для добавления клиента
void Store::addCustomer(const Customer& customer) {
    m_customers.push_back(customer);
}

// Метод для покупки товара клиентом
bool Store::purchaseProduct(int customer_id, const std::string& productName, int quantity) {
    for (auto& product : m_products) {
        if (product.getName() == productName) {
            return m_customers[customer_id].purchase(product, quantity);
        }
    }
    std::cerr << "Ошибка: товар не найден." << std::endl;
    return false;
}


// Метод для вывода информации о товарах
void Store::displayProducts() const {
    std::cout << "Товары в магазине:" << std::endl;
    for (const auto& product : m_products) {
        product.display();
    }
}

// Метод для вывода информации о клиентах
void Store::displayCustomers() const {
    std::cout << "Клиенты в магазине:" << std::endl;
    for (const auto& customer : m_customers) {
        customer.display();
    }
}

// Метод для получения общего количества товаров в магазине
size_t Store::getTotalProducts() {
    return m_product_counter;
}

// Шаблонный метод для возврата информации о товарах или клиентах
template<typename T>
std::vector<T> Store::getList() const {
    return std::vector<T>();
}

// Специализация шаблонного метода для товаров
template<>
std::vector<Product> Store::getList() const {
    return m_products;
}

// Специализация шаблонного метода для клиентов
template<>
std::vector<Customer> Store::getList() const {
    return m_customers;
}

