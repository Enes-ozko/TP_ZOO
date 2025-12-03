#include "Bird.h"
#include "Animal.h"
#include <iostream>
using namespace std; 

Bird::Bird() : Animal(), wingspan(0.0) {}

Bird::Bird(string nameValue, string colorValue, string dietValue, string habitatValue, string soundsValue, bool isPetValue, int ageValue, double weightValue, double heightValue, double wingspanValue)
    : Animal(nameValue, colorValue, dietValue, habitatValue, soundsValue, isPetValue, ageValue, weightValue, heightValue), 
      wingspan(wingspanValue) {}

Bird::Bird(const Bird& other)
    : Animal(other), wingspan(other.wingspan) {}

double Bird::getWingspan() const {
    return wingspan;
}

void Bird::setWingspan(const double& wingspanValue) {
    wingspan = wingspanValue;
}

void Bird::makeSound() const {
    cout << getName() << " says: " << getSounds() << endl;
}

void Bird::printInfo() const {
    cout << "Animal of type: Bird" << endl; 
    cout << "Name: " << getName() << endl; 
    cout << "Color: " << getColor() << endl;
    cout << "Wingspan: " << wingspan << " m" << endl;
    cout << "Diet: " << getDiet() << endl;
    cout << "Habitat: " << getHabitat() << endl;
    cout << "Age: " << getAge() << "'s old" << endl;
    cout << "This animal is " << (getIsPet() ? "" : "not ") << "a pet" << endl; 
    cout << "Sounds: " << getSounds() << endl;
    cout << "Weight: " << getWeight() << " kg" << endl;
    cout << "Height: " << getHeight() << " cm\n" << endl;
}