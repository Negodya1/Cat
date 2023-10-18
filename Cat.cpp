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

std::string Cat::getString() {
	return "Cat " + name + " " + kind + " " + std::to_string(age) + " " + std::to_string(color.red) + " " + std::to_string(color.green) + " " + std::to_string(color.blue) + " " + std::to_string(gender) + " " + std::to_string(weight);
}

Cat::~Cat() {
	kind.clear();
}

Cat& Cat::operator++() {
	if (age < 1) weight *= 10;
	age += 1;
	return *this;
}
Cat Cat::operator++(int) {
	Cat copy{ *this };
	++(*this);
	return copy;
}

Cat Cat::operator+(const int add) {
	if (age < 1 && add > 1) weight *= 10;
	age += add;
	return *this;
}