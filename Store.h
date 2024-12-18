#pragma once
using namespace std;
#include "Product.h"
#include <vector>
class Customer;


class Store
{
private:
	vector<Product> m_products;
	vector<Customer> m_customers;
	static size_t m_product_counter;
public:
	Store();
	Store(vector<Product>& products, vector<Customer>& customers);
	Store(Store& other_store);
	~Store();

	//template<class T> vector<T> get_Prod_or_Cust();
	void addProduct(const Product& product);

	void addCustomer(const Customer& customer);

	bool purchaseProduct(int customer_id, const std::string& productName, int quantity);

	void getInfoCust(Customer& cust);

	void displayProducts() const;

	void displayCustomers() const;

	static size_t getTotalProducts();

	template<typename T>
	std::vector<T> getList() const;


};




