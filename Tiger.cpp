#include "Tiger.h"
#include <iostream>
#include <random>

void Tiger::printInfo() {
	std::cout << "Type: Tiger\nName: " << name
		<< "\nAge: " << age << "\nGender: ";
	if (gender) std::cout << "female";
	else std::cout << "male";
	std::cout << std::endl << std::endl;
}

int Tiger::getInt() {
	return rand();
}

Tiger::~Tiger() {
	name.clear();
}

Tiger& Tiger::operator++() {
	age += 1;
	return *this;
}
Tiger Tiger::operator++(int) {
	Tiger copy{ *this };
	++(*this);
	return copy;
}

Tiger Tiger::operator+(const int add) {
	age += add;
	return *this;
}