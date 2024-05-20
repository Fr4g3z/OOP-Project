#pragma once
#include <string>
#include <iostream>

class Pesticides {
protected:
	std::string name;
	int quantity;
	std::string target;
	std::string application_type;
public:
	//Constructors
	Pesticides(): name(), quantity(), target(), application_type() {}
	Pesticides(std::string _name, int _quantity, std::string _target, std::string _application_type) :
		name(_name), quantity(_quantity), target(_target), application_type(_application_type) {}

	//Setters and getters
	void setName(std::string _name) { name = _name; }
	std::string getName() const { return name; }

	void setQuantity(int _quantity) { quantity = _quantity; }
	int getQuantity() const { return quantity; }

	void setTarget(std::string _target) { target = _target; }
	std::string getTarget() const { return target; }

	void setApplicationType(std::string _application_type) { application_type = _application_type; }
	std::string getApplicationType() const { return application_type; }

	//Output all fields
	void displayInfo() {
		std::cout << "Name: " << getName() << std::endl;
		std::cout << "Quantity: " << getQuantity() << std::endl;
		std::cout << "Target: " << getTarget() << std::endl;
		std::cout << "Application Type: " << getApplicationType() << std::endl;
	}

	virtual void apply() const = 0;
	virtual ~Pesticides() {}
};

class Herbicide : public Pesticides {
public:
	Herbicide(std::string _name, int _quantity) : Pesticides(_name, _quantity, "Weeds", "Spraying") {}
	void apply() const override {
		std::cout << application_type << name << " to decrease ammount of unwanted " << target << std::endl;
	}
};

class Insecticide : public Pesticides {
	Insecticide(std::string _name, int _quantity) : Pesticides(_name, _quantity, "Insects", "Baiting") {}
	void apply() const override {
		std::cout << application_type << name << " to decrease ammount of unwanted " << target << std::endl;
	}
};

class Fungicide : public Pesticides {
	Fungicide(std::string _name, int _quantity) : Pesticides(_name, _quantity, "Fungal diseases", "Soil drenching") {}
	void apply() const override {
		std::cout << application_type << name << " to decrease ammount of unwanted " << target << std::endl;
	}
};