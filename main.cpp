#include <iostream>
#include <vector>
#include "Animal.h"
#include "Cat.h"
#include "Tiger.h"
#include <fstream>

int main() {
    setlocale(LC_ALL, "Russian");

    //Раннее связывание, тестирование методов
    Animal test = Animal();

    Cat testc = Cat("Барсик", "Персидский", 4, {164, 128, 128}, 1, 87);

    Tiger testt = Tiger("Барсик", 10, 0);
    std::cout << "Количество экземпляров класса: " << Animal::getCount() << std::endl;

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

    //Позднее связывание
    Animal* late = NULL;
    int type = 0;
    std::cout << "Выберите тип данных для позднего связывания (0 - Animal, 1 - Tiger, 2 - Cat): ";
    std::cin >> type;

    //Создание экземпляра выбранного типа данных и вывод информации
    if (type == 0) late = new Animal();
    else if (type == 1) late = new Tiger("Барсик", 8, 0);
    else late = new Cat("Барсик", "Персидский", 4, { 164, 128, 128 }, 1, 87);

    late->printInfo();

    delete late;

    std::cout << "Загрузить из файла - 1\nЗагрузить в файл - 0: ";
    std::cin >> type;

    if (type == 0) {
        std::vector<Tiger *> vect;
        //Добавлять в вектор новые экземпляры классов, пока пользователь не введёт 0
        do {
            std::cout << "Выберите тип данных (0 - выход, 1 - Tiger, 2 - Cat): ";
            std::cin >> type;

            if (type == 1) {
                Tiger *buft = new Tiger("Барсик", 8, 0);
                std::cout << "Введите параметры нового объекта (Имя, Возраст, Пол): ";
                std::cin >> *buft;
                vect.push_back(buft);
                std::cout << vect[vect.size() - 1]->getString() << std::endl; //Вывод строки полученного класса
            }
            else if (type == 2) {
                Cat* buft = new Cat("Барсик", "Персидский", 4, { 164, 128, 128 }, 1, 87);
                std::cout << "Введите параметры нового объекта (Имя, Порода, Возраст, Цвет (красный, зелёный, синий), Пол, Вес): ";
                std::cin >> *buft;
                vect.push_back(buft);
                std::cout << vect[vect.size() - 1]->getString() << std::endl; //Вывод строки полученного класса
            }

        } while (type != 0);

        //Сохранение полученного вектора в файл
        std::ofstream f("result.txt");
        for (Tiger * cur: vect) {
            f << cur->getString() << std::endl;
            delete cur;
        }
        f.close();
    }
    else {
        std::vector<Animal*> vect;

        //Загрузка экземпляров класса из файла
        std::ifstream f("result.txt");
        while (!f.eof()) {
            std::string type;
            f >> type; //Определение типа, затем создание экземпляра и вставка его в вектор
            if (type == "Animal") vect.push_back(new Animal());
            else if (type == "Tiger") {
                Tiger* buf = new Tiger();
                f >> *buf;
                vect.push_back(buf);
            }
            else if (type == "Cat") {
                Cat* buf = new Cat();
                f >> *buf;
                vect.push_back(buf);
            }
            else {
                break;
            }
        }
        f.close();

        //Вывод всех экземпляров на экран
        for (Animal* cur : vect) {
            std::cout << cur->getString() << std::endl;
            delete cur;
        }
    }
}
