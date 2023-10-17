#include "Cat.h"
#include <iostream>
#include <ctime>

void Cat::printInfo() {
	std::cout << "Type: Cat\nName: " << name
		<< "\nAge: " << age << "\nKind: " << kind
		<< "\nWeight: " << weight << "\nGender: ";
	if (gender) std::cout << "female";
	else std::cout << "male";
	std::cout << "\nColor:\n\tRed: " << color.red << "\n\tGreen: " << color.green << "\n\tBlue: " << color.blue << std::endl << std::endl;
}

int Cat::getInt() {
	return std::time(0);
}

Cat::~Cat() {
	kind.clear();
}

Cat& Cat::operator++() {
	age += 1;
	return *this;
}
Cat Cat::operator++(int) {
	Cat copy{ *this };
	++(*this);
	return copy;
}

Cat Cat::operator+(const int add) {
	age += add;
	return *this;
}