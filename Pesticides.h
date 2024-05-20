#pragma once
#include <string>
#include <iostream>

class Pesticides {
	std::string name;
	int quantity;
	std::string target;
public:
	Pesticides(): name(), quantity(), target() {}
	Pesticides(std::string _name, int _quantity, std::string _target) :
		name(_name), quantity(_quantity), target(_target) {}

	void setName(std::string _name) { name = _name; }
	std::string getName() const { return name; }

	void setQuantity(int _quantity) { quantity = _quantity; }
	int getQuantity() const { return quantity; }

	void setTarget(std::string _target) { target = _target; }
	std::string getTarget() const { return target; }

	void displayInfo() {
		std::cout << "Name: " << getName() << std::endl;
		std::cout << "Quantity: " << getQuantity() << std::endl;
		std::cout << "Target: " << getTarget() << std::endl;
	}

	virtual std::string apply() const = 0;
	virtual ~Pesticides() {}
};