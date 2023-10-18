#pragma once
#include "Tiger.h"
#include <string>

class Cat : public Tiger {
protected:
	std::string kind;
	struct Color {
		int red;
		int green;
		int blue;
	} color;
	int weight;

public:
	Cat(std::string _name, std::string _kind, int _age, struct Color _color, bool _gender, int _weight): Tiger(_name, _age, _gender) {
		color = _color;
		kind = _kind;
		weight = _weight;
	}
	Cat(): Tiger() {
		color = { 0, 0, 0 };
		kind = "";
		weight = 0;
	}
	~Cat();

	virtual void printInfo();
	virtual int getInt();
	virtual std::string getString();

	Cat& operator++();
	Cat operator++(int);

	friend std::ostream& operator<<(std::ostream& stream, const Cat& _cat) {
		stream << "Cat ";
		stream << "Name: ";
		stream << _cat.name;
		stream << " Age: ";
		stream << _cat.age;
		stream << " Kind: ";
		stream << _cat.kind;
		stream << " Color: { red: ";
		stream << _cat.color.red;
		stream << " green: ";
		stream << _cat.color.green;
		stream << " blue: ";
		stream << _cat.color.blue;
		stream << " } Weight: ";
		stream << _cat.weight;
		stream << " Gender: ";
		if (_cat.gender) stream << "female";
		else stream << "male";
		return stream;
	}

	friend std::istream& operator >> (std::istream& in, Cat& _cat) {
		std::string _name;
		std::string _kind;
		int _age, red, green, blue;
		std::string _gender;
		int _weight;
		in >> _name >> _kind >> _age >> red >> green >> blue >> _gender >> _weight;
		_cat.name = _name;
		_cat.age = _age;
		_cat.kind = _kind;
		_cat.weight = _weight;
		_cat.color = {red, green, blue};
		if (_gender == "female") _cat.gender = true;
		else _cat.gender = false;
		return in;
	}

	Cat operator+(const int add);
};
