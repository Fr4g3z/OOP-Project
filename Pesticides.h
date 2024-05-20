#pragma once
#include <string>
#include <iostream>
#include "Plants.h"

class Pesticides {
protected:
	std::string name;
	std::string target;
	std::string application_type;
	double effectiveness;
public:
	//Constructors
	Pesticides(): name(), target(), application_type(), effectiveness() {}
	Pesticides(std::string _name, std::string _target, std::string _application_type, double _effectiveness) :
		name(_name), target(_target), application_type(_application_type), effectiveness(_effectiveness) {}

	//Setters and getters
	void setName(std::string _name) { name = _name; }
	std::string getName() const { return name; }

	void setTarget(std::string _target) { target = _target; }
	std::string getTarget() const { return target; }

	void setApplicationType(std::string _application_type) { application_type = _application_type; }
	std::string getApplicationType() const { return application_type; }

	void setEffectiveness(double _effectiveness) { effectiveness = _effectiveness; }
	double getEffectiveness() const { return effectiveness; }

	//Output all fields
	void displayInfo() {
		std::cout << std::endl << "Name: " << getName() << std::endl;
		std::cout << "Target: " << getTarget() << std::endl;
		std::cout << "Application Type: " << getApplicationType() << std::endl;
		std::cout << "Effectiveness: " << getEffectiveness() * 100 << "%" << std::endl;
	}

	virtual void apply(Plants* plant) const = 0;
	virtual ~Pesticides() {}
};

class Herbicide : public Pesticides {
public:
	Herbicide(std::string _name) : Pesticides(_name, "Weeds", "Spraying", 0.90) {}
	void apply(Plants* plant) const override {
		if (plant->getDisease() == target) {
			double new_dis_level = plant->getDiseaseLevel() - plant->getDiseaseLevel() * effectiveness;
			std::cout << application_type << " " << name << " decreased amount of unwanted " << target << " from " << plant->getDiseaseLevel() << "% to " << new_dis_level << "%" << std::endl;
			plant->setDiseaseLevel(new_dis_level);
		}
		else {
			std::cout << "Wrong type of plant!" << std::endl;
		}
	}
};

class Insecticide : public Pesticides {
public:
	Insecticide(std::string _name) : Pesticides(_name, "Insects", "Baiting", 0.97) {}
	void apply(Plants* plant) const override {
		if (plant->getDisease() == target) {
			double new_dis_level = plant->getDiseaseLevel() - plant->getDiseaseLevel() * effectiveness;
			std::cout << application_type << " " << name << " decreased amount of unwanted " << target << " from " << plant->getDiseaseLevel() << "% to " << new_dis_level << "%" << std::endl;
			plant->setDiseaseLevel(new_dis_level);
		}
		else {
			std::cout << "Wrong type of plant!" << std::endl;
		}
	}
};

class Fungicide : public Pesticides {
public:
	Fungicide(std::string _name) : Pesticides(_name, "Fungal diseases", "Soil drenching", 0.99) {}
	void apply(Plants* plant) const override {
		if (plant->getDisease() == target) {
			double new_dis_level = plant->getDiseaseLevel() - plant->getDiseaseLevel() * effectiveness;
			std::cout << application_type << " " << name << " decreased amount of unwanted " << target << " from " << plant->getDiseaseLevel() << "% to " << new_dis_level << "%" << std::endl;
			plant->setDiseaseLevel(new_dis_level);

		}
		else {
			std::cout << "Nothing happened" << std::endl;
		}
	}
};