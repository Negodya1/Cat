#include "Animal.h"
#include <iostream>

void Animal::printInfo() {
	std::cout << "Type: Animal\n\n";
}

int Animal::getInt() {
	return 0;
}

std::string Animal::getString() {
	return "Animal";
}

int Animal::getCount() {
	if (count == NULL) count = new int(0);
	return *count;
}

void Animal::addCount(int add) {
	if (count == NULL) count = new int(0);
	*count += add;
}