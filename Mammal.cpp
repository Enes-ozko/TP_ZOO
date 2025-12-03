#include "Mammal.h"
#include "Animal.h"
using namespace std;

Mammal::Mammal() : Animal(), furColor("Unknown") {}

Mammal::Mammal(string nameValue, string colorValue, string dietValue, string habitatValue, string soundsValue, bool isPetValue, int ageValue, double weightValue, double heightValue, string furColorValue)
    : Animal(nameValue, colorValue, dietValue, habitatValue, soundsValue, isPetValue, ageValue, weightValue, heightValue), furColor(furColorValue) {}

Mammal::Mammal(const Mammal& other)
    : Animal(other), furColor(other.furColor) {}


void Mammal::makeSound() const {
    cout << getName() << " says: " << getSounds() << endl;
}

string Mammal::getFurColor() const { return furColor; }

void Mammal::setFurColor(const string& furColorValue) { furColor = furColorValue; }


void Mammal::printInfo() const {
    cout << "Animal of type: Mammal" << endl; 
    cout << "Name: " << getName() << endl; 
    cout << "Fur Color: " << furColor << endl; 
    cout << "Diet: " << getDiet() << endl;
    cout << "Habitat: " << getHabitat() << endl;
    cout << "Age: " << getAge() << "'s old" << endl;
    cout << "This animal is " << (getIsPet() ? "" : "not ") << "a pet" << endl; 
    cout << "Sounds: " << getSounds() << endl;
    cout << "Weight: " << getWeight() << " kg" << endl;
    cout << "Height: " << getHeight() << " cm\n" << endl;
}