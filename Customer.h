#pragma once
#include<string>
#include <iostream>
#include "Store.h"
using namespace std;
class Customer
{
private:
	string m_name;
	float m_balance;
public:
	Customer();

	Customer(string name, float balance);

	~Customer();

	void deposit(float summa);

	bool purchase(Product& product, int quantity);

	float getBalance();

	void display() const;

	friend void Store::getInfoCust(Customer& cust);

};
