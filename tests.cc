#pragma once
#include <iostream>
#include "Pesticides.h"
#include "Plants.h"

inline static void test() {
	Plants* p = new Trees;
	p->gain_disease();
	p->displayInfo();
	Herbicide herbicide("herbicide");
	herbicide.displayInfo();
	herbicide.apply(p);

	Insecticide insect("ins");
	insect.displayInfo();
	insect.apply(p);

	Fungicide fungi("fung");
	fungi.displayInfo();
	fungi.apply(p);

	p->displayInfo();
	
	
}
