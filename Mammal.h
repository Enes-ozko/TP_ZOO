#ifndef MAMMAL_H
#define MAMMAL_H
#include "Animal.h"
#include <string>
#include <iostream>
using namespace std;

class Mammal: public Animal{
    private:
        string furColor;
    public:
        Mammal();
        Mammal(string nameValue, string colorValue, string dietValue, string habitatValue, string soundsValue, bool isPetValue, int ageValue, double weightValue, double heightValue, string furColorValue);
        Mammal(const Mammal& other);
        ~Mammal() override = default;

        void printInfo() const override;
        void makeSound() const override;

        string getFurColor() const;
        void setFurColor(const string& furColorValue);
};

#endif