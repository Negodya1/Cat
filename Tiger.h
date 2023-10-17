#pragma once
#include "Animal.h"
#include <string>
#include <iostream>

class Tiger : public Animal {
protected:
	std::string name;
	bool gender;
	int age;
public:
	Tiger(std::string _name, int _age, bool _gender) {
		name = _name;
		age = _age;
		gender = _gender;
	}
	~Tiger();

	virtual void printInfo();
	virtual int getInt();

	Tiger& operator++();
	Tiger operator++(int);

	friend std::ostream& operator<<(std::ostream& stream, const Tiger& _tiger) {
		stream << "Tiger ";
		stream << "Name: ";
		stream << _tiger.name;
		stream << " Age: ";
		stream << _tiger.age;
		stream << " Gender: ";
		if (_tiger.gender) stream << "female";
		else stream << "male";
		return stream;
	}

	friend std::istream& operator >> (std::istream& in, Tiger& _tiger) {
		std::string _name;
		int _age;
		std::string _gender;
		in >> _name >> _age >> _gender;
		_tiger.name = _name;
		_tiger.age = _age;
		if (_gender == "female") _tiger.gender = true;
		else _tiger.gender = false;
		return in;
	}

	Tiger operator+(const int add);
};

