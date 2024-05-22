#pragma once
#include <string>
#include <iostream>
#include "Plants.h"

class Pesticides {
protected:
	std::string name;
	std::string target;
	double effectiveness;
public:
	//Constructors
	Pesticides(): name(), target(), effectiveness() {}
	Pesticides(std::string _name, std::string _target, double _effectiveness) :
		name(_name), target(_target), effectiveness(_effectiveness) {}

	//Setters and getters
	void setName(std::string _name) { name = _name; }
	std::string getName() const { return name; }

	void setTarget(std::string _target) { target = _target; }
	std::string getTarget() const { return target; }

	void setEffectiveness(double _effectiveness) { effectiveness = _effectiveness; }
	double getEffectiveness() const { return effectiveness; }

	//Output all fields
	void displayInfo() {
		std::cout << std::endl << "Name: " << getName() << std::endl;
		std::cout << "Target: " << getTarget() << std::endl;
		std::cout << "Effectiveness: " << getEffectiveness() * 100 << "%" << std::endl;
	}

	virtual void apply(Plants* plant) = 0;
	virtual ~Pesticides() {}
};

class Herbicide : public Pesticides {
public:
	Herbicide(std::string _name) : Pesticides(_name, "Weeds", 0.90) {}
	void spray(Plants* plant) {
		std::vector<std::string> temp;
		for (int i = 0; i < plant->getLeaves().size(); i++) {
			temp.push_back("Sprayed " + plant->getLeaf(i));
		}
		plant->setLeaves(temp);
		std::cout << name << " sprayed over all leaves of " << plant->getName() << std::endl;
	}
	void apply(Plants* plant) override {
		if (plant->getDisease() == target) {
			spray(plant);
			double new_dis_level = plant->getDiseaseLevel() - plant->getDiseaseLevel() * effectiveness;
			plant->setDiseaseLevel(new_dis_level);
		}
		else {
			std::cout << "Nothing happened" << std::endl;
		}
	}
};

class Insecticide : public Pesticides {
public:
	Insecticide(std::string _name) : Pesticides(_name, "Insects", 0.97) {}
	void bait(Plants* plant) {
		plant->appendTrap("Granular fly bait");
		std::cout << "Fly bait was put to "<< plant->getName() << std::endl;
	}
	void apply(Plants* plant) override {
		if (plant->getDisease() == target) {
			bait(plant);
			double new_dis_level = plant->getDiseaseLevel() - plant->getDiseaseLevel() * effectiveness;
			plant->setDiseaseLevel(new_dis_level);
		}
		else {
			std::cout << "Nothing happened" << std::endl;
		}
	}
};

class Fungicide : public Pesticides {
public:
	Fungicide(std::string _name) : Pesticides(_name, "Fungal diseases", 0.99) {}
	void soil_drench(Plants* plant){
		std::string new_soil = "Phosphorous Acid drenched " + plant->getSoil();
		std::cout << "Soil of " << plant->getName() << " was drenched with Phosphorous Acid" << std::endl;
		plant->setSoil(new_soil);
	}
	void apply(Plants* plant) override {
		if (plant->getDisease() == target) {
			soil_drench(plant);
			double new_dis_level = plant->getDiseaseLevel() - plant->getDiseaseLevel() * effectiveness;
			plant->setDiseaseLevel(new_dis_level);
		}
		else {
			std::cout << "Nothing happened" << std::endl;
		}
	}
};