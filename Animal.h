#pragma once
#include <string>

//Статическоне поле для подсчёта экземпляров класса
static int* count;

//Абстрактный класс Животное
class Animal {
private:
	
public:
	Animal() {
		Animal::addCount(1);
	}
	~Animal() {
		Animal::addCount(-1);
	}

	virtual void printInfo();
	virtual int getInt();
	virtual std::string getString();

	static void addCount(int add);
	static int getCount();
};

