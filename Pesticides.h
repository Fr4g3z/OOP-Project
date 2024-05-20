#pragma once
#include <string>
#include <iostream>

class Pesticides {
protected:
	std::string name;
	int amount;
	std::string target;
	std::string application_type;
public:
	//Constructors
	Pesticides(): name(), amount(), target(), application_type() {}
	Pesticides(std::string _name, int _amount, std::string _target, std::string _application_type) :
		name(_name), amount(_amount), target(_target), application_type(_application_type) {}

	//Setters and getters
	void setName(std::string _name) { name = _name; }
	std::string getName() const { return name; }

	void setAmount(int _amount) { amount = _amount; }
	int getAmount() const { return amount; }

	void setTarget(std::string _target) { target = _target; }
	std::string getTarget() const { return target; }

	void setApplicationType(std::string _application_type) { application_type = _application_type; }
	std::string getApplicationType() const { return application_type; }

	//Output all fields
	void displayInfo() {
		std::cout << "Name: " << getName() << std::endl;
		std::cout << "Can spread over " << getAmount() << " hectares" << std::endl;
		std::cout << "Target: " << getTarget() << std::endl;
		std::cout << "Application Type: " << getApplicationType() << std::endl;
	}

	bool enough_amount(){
		if (amount < 1) {
			std::cout << "Not enough even for 1 hectare" << std::endl;
			return false;
		}
	return true;
	}

	virtual void apply() const = 0;
	virtual ~Pesticides() {}
};

class Herbicide : public Pesticides {
public:
	Herbicide(std::string _name, int _quantity) : Pesticides(_name, _quantity, "Weeds", "Spraying") {}
	void apply() const override {
		if (enough_amount) {
			std::cout << application_type << name << " to decrease amount of unwanted " << target << std::endl;
		}
	}
};

class Insecticide : public Pesticides {
	Insecticide(std::string _name, int _quantity) : Pesticides(_name, _quantity, "Insects", "Baiting") {}
	void apply() const override {
		if (enough_amount) {
			std::cout << application_type << name << " to decrease amount of unwanted " << target << std::endl;
		}
	}
};

class Fungicide : public Pesticides {
	Fungicide(std::string _name, int _quantity) : Pesticides(_name, _quantity, "Fungal diseases", "Soil drenching") {}
	void apply() const override {
		if (enough_amount) {
			std::cout << application_type << name << " to decrease amount of unwanted " << target << std::endl;
		}
	}
};