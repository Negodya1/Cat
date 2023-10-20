#include "Tiger.h"
#include <iostream>
#include <random>

//Виртуальные функции
//Вывод на экран информации
void Tiger::printInfo() {
	std::cout << "Type: Tiger\nName: " << name
		<< "\nAge: " << age << "\nGender: ";
	if (gender) std::cout << "female";
	else std::cout << "male";
	std::cout << std::endl << std::endl;
}

//Получение числа: случайное
int Tiger::getInt() {
	return rand();
}

//Получение строки класса
std::string Tiger::getString() {
	return "Tiger " + name + " " + std::to_string(age) + " " + std::to_string(gender);
}
//*****

//Деструктор
Tiger::~Tiger() {
	name.clear();
}

//Оператор ++
//Увеличивает возраст на единицу
Tiger& Tiger::operator++() {
	age += 1;
	return *this;
}
Tiger Tiger::operator++(int) {
	Tiger copy{ *this };
	++(*this);
	return copy;
}

//Оператор +
//Увеличивает возраст на значение
Tiger Tiger::operator+(const int add) {
	age += add;
	return *this;
}