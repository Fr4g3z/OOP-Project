#pragma once
#include <iostream>
#include "Pesticides.h"
#include "Plants.h"

inline static void test() {
	Plants* p = new Trees("Oak");
	Plants* g = new Grass("Wheat");
	Plants* f = new Flower("Rosa");
	p->gain_disease();
	g->gain_disease();
	f->gain_disease();
	p->displayInfo();
	g->displayInfo();
	f->displayInfo();
	Herbicide herbicide("herbicide");
	herbicide.apply(g);

	Insecticide insect("ins");
	insect.apply(f);

	Fungicide fungi("fung");
	fungi.apply(p);

	p->interact();
	g->interact();
	f->interact();
}
