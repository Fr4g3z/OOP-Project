#pragma once
#include <string>

class Gardening_Equipment {
	std::string name;
	int quantity;
public: 
	Gardening_Equipment() : name(), quantity() {}
	Gardening_Equipment(int _id, std::string _name, int _price, int _quantity) :
		name(_name), quantity(_quantity) {}

	void setName(std::string _name) { name = _name; }
	std::string getName() const { return name; }

	void setQuantity(int _quantity) { quantity = _quantity; }
	int getQuantity() const { return quantity; }

	virtual std::string utilize() const = 0;
	virtual ~Gardening_Equipment(){}
};


class Pesticides : public Gardening_Equipment {
	
};

class Instruments : public Gardening_Equipment {

};