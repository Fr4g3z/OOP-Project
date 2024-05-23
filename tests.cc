#pragma once
#include <iostream>
#include "Pesticides.h"
#include "Plants.h"
#include <cassert>

inline static void treeTest() {
	Plants* t = new Trees("Oak");
	Herbicide H("Herbicide");
	Insecticide I("Insecticide");
	Fungicide F("Fungicide");
	t->setDiseaseLevel(100);
	assert(H.apply(t) == "Nothing happened\n");
	std::cout << "Checkpoint 1 treeTest" << std::endl;
	assert(I.apply(t) == "Nothing happened\n");
	std::cout << "Checkpoint 2 treeTest" << std::endl;
	assert(F.apply(t) == "Soil of Oak was drenched with Phosphorous Acid\n");
	std::cout << "Checkpoint 3 treeTest" << std::endl;
	assert(t->getDiseaseLevel() == 1);
	std::cout << "Checkpoint 4 treeTest" << std::endl;
	assert(t->getSoil() == "Phosphorous Acid drenched Сhernozem");
	std::cout << "treeTest passed\n";
}

inline static void grassTest() {
	Plants* g = new Grass("Wheat");
	Herbicide H("Herbicide");
	Insecticide I("Insecticide");
	Fungicide F("Fungicide");
	g->setDiseaseLevel(100);
	assert(F.apply(g) == "Nothing happened\n");
	std::cout << "Checkpoint 1 grassTest" << std::endl;
	assert(I.apply(g) == "Nothing happened\n");
	std::cout << "Checkpoint 2 grassTest" << std::endl;
	assert(H.apply(g) == "Herbicide sprayed over all leaves of Wheat\n");
	std::cout << "Checkpoint 3 grassTest" << std::endl;
	assert(g->getDiseaseLevel() == 10);
	std::cout << "Checkpoint 4 grassTest" << std::endl;
	assert(g->getSoil() == "Peat");
	std::cout << "Checkpoint 5 grassTest" << std::endl;
	for (int i = 0; i < g->getLeaves().size(); i++) {
		assert(g->getLeaf(i) == "Sprayed leaf");
	}
	std::cout << "grassTest passed\n";
}

inline static void flowerTest() {
	Plants* f = new Flower("Rosa");
	Herbicide H("Herbicide");
	Insecticide I("Insecticide");
	Fungicide F("Fungicide");
	f->setDiseaseLevel(100);
	assert(F.apply(f) == "Nothing happened\n");
	std::cout << "Checkpoint 1 flowerTest" << std::endl;
	assert(H.apply(f) == "Nothing happened\n");
	std::cout << "Checkpoint 2 flowerTest" << std::endl;
	assert(I.apply(f) == "Fly bait was put to Rosa\n");
	std::cout << "Checkpoint 3 flowerTest" << std::endl;
	assert(f->getDiseaseLevel() == 3);
	std::cout << "Checkpoint 4 flowerTest" << std::endl;
	assert(f->getSoil() == "Loam");
	std::cout << "Checkpoint 5 flowerTest" << std::endl;
	assert(f->getTrap(0) == "Granular fly bait");
	std::cout << "flowerTest passed\n";
}