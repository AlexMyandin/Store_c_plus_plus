#pragma once
#include <string>
#include <iostream>
using namespace std;
class Product
{
private:
	string m_name;
	float m_price;
	size_t m_quantity_in_store;
public:

	Product();

	Product(string name, float price, size_t quantity_in_store);

	~Product();

	bool operator==(Product& prod);
	Product& operator+=(int amount);
	Product& operator-=(int amount);

	string getName();

	float getPrice();

	size_t getQuantity_in_store();

	void getInfo();

	void setPrice(float price);
	
	void setQuantity_in_store(size_t quantity);

	void display() const;
};

