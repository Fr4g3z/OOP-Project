#pragma once
#include <iostream>
#include "Pesticides.h"

inline static void test() {
	Herbicide herbicide("herbicide");
	herbicide.displayInfo();
	herbicide.apply();

	Insecticide insect("ins");
	insect.displayInfo();
	insect.apply();

	Fungicide fungi("fung");
	fungi.displayInfo();
	fungi.apply();
}
