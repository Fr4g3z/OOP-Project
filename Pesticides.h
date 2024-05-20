#pragma once
#include <string>
#include <iostream>

class Pesticides {
protected:
	std::string name;
	std::string target;
	std::string application_type;
public:
	//Constructors
	Pesticides(): name(), target(), application_type() {}
	Pesticides(std::string _name, std::string _target, std::string _application_type) :
		name(_name), target(_target), application_type(_application_type) {}

	//Setters and getters
	void setName(std::string _name) { name = _name; }
	std::string getName() const { return name; }

	void setTarget(std::string _target) { target = _target; }
	std::string getTarget() const { return target; }

	void setApplicationType(std::string _application_type) { application_type = _application_type; }
	std::string getApplicationType() const { return application_type; }

	//Output all fields
	void displayInfo() {
		std::cout << std::endl << "Name: " << getName() << std::endl;
		std::cout << "Target: " << getTarget() << std::endl;
		std::cout << "Application Type: " << getApplicationType() << std::endl;
	}

	virtual void apply() const = 0;
	virtual ~Pesticides() {}
};

class Herbicide : public Pesticides {
public:
	Herbicide(std::string _name) : Pesticides(_name, "Weeds", "Spraying") {}
	void apply() const override {
			std::cout << application_type <<" " << name << " to decrease amount of unwanted " << target << std::endl;
	}
};

class Insecticide : public Pesticides {
public:
	Insecticide(std::string _name) : Pesticides(_name, "Insects", "Baiting") {}
	void apply() const override {
			std::cout << application_type <<" " << name << " to decrease amount of unwanted " << target << std::endl;
	}
};

class Fungicide : public Pesticides {
public:
	Fungicide(std::string _name) : Pesticides(_name, "Fungal diseases", "Soil drenching") {}
	void apply() const override {
			std::cout << application_type <<" " << name << " to decrease amount of unwanted " << target << std::endl;
	}
};