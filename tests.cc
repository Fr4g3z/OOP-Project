#pragma once
#include <iostream>
#include "Pesticides.h"
#include "Plants.h"

inline static void test() {
	Plants* t = new Trees("Oak");
	Plants* g = new Grass("Wheat");
	Plants* f = new Flower("Rosa");
	t->gain_disease();
	g->gain_disease();
	f->gain_disease();
	t->displayInfo();
	g->displayInfo();
	f->displayInfo();
	Herbicide h("herbicide");
	Insecticide i("ins");
	Fungicide fu("fung");
	h.apply(g);
	i.apply(f);
	fu.apply(t);
	t->displayInfo();
	g->displayInfo();
	f->displayInfo();

	std::vector<std::string> vec = f->getTraps();
	std::cout << "Traps: ";
	display_vector(vec);
	vec = g->getLeaves();
	display_vector(vec);
}
