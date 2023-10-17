#include <iostream>

#include "Animal.h"
#include "Cat.h"
#include "Tiger.h"

int main() {
    setlocale(LC_ALL, "Russian");

    Animal test = Animal();
    Cat testc = Cat("Барсик", "Персидский", 4, {164, 128, 128}, 1, 8.7);
    Tiger testt = Tiger("Барсик", 10, 0);

    std::cout << test.getInt() << std::endl;
    test.printInfo();

    std::cout << testc.getInt() << std::endl;
    testc.printInfo();
    std::cout << testc << std::endl;

    std::cout << testt.getInt() << std::endl;
    testt.printInfo();
    testt++;
    testt.printInfo();
    std::cout << testt << std::endl;
    testt = testt + 10;
    testt.printInfo();
}
