#pragma once
#include <string>
#include <iostream>
#include "Pesticides.h"
#include <random>

inline static double random_double() {
	std::random_device r;
	std::default_random_engine random(r());
	std::uniform_real_distribution<double> distr(1, 50);
	double random_double = distr(random);
	return random_double;
}

class Plants {
protected:
	std::string name;
	std::string disease;
	double disease_level;
public:
	Plants(std::string _name="", std::string _disease=""):
		name(_name), disease(_disease), disease_level(0) {}

	void setName(std::string _name) { name = _name; }
	std::string getName() const { return name; }

	void setDisease(std::string _disease) { disease = _disease; }
	std::string getDisease() const { return disease; }

	void setDiseaseLevel(double _disease_level) {
		if (_disease_level >= 0 && _disease_level <= 100) { disease_level = _disease_level; }
	}
	double getDiseaseLevel() const { return disease_level; }

	void displayInfo() {
		std::cout << std::endl << "Name: " << getName() << std::endl;
		std::cout << "Disease: " << getDisease() << std::endl;
		std::cout << "Disease Level: " << getDiseaseLevel() << std::endl;
	}

	void gain_disease() {
		double temp = disease_level + random_double();
		if (temp <= 100) { disease_level = temp; }
	}
	virtual void interact() const = 0;
	virtual ~Plants() {}
};

class Trees : public Plants {
public:
	Trees(std::string _name = "") : Plants (_name, "Fungal diseases") {}
	void interact() const override {
		std::cout << "You feel massive " << name << " bark" << std::endl;
	}
	~Trees() {}
};

class Grass : public Plants {
public:
	Grass(std::string _name = "") : Plants(_name, "Weeds") {}
	void interact() const override {
		std::cout << "You run your hand along " << name << "'s stems" << std::endl;
	}
	~Grass() {}
};

class Flower : public Plants {
public:
	Flower(std::string _name = "") : Plants(_name, "Insects") {}
	void interact() const override {
		std::cout << "You inhale the wonderful aroma of " << name << std::endl;
	}
	~Flower() {}
};