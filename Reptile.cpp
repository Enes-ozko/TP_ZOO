#include "Animal.h"
#include "Reptile.h"
using namespace std;

Reptile::Reptile() : Animal(), scalePattern("Unknown") {}

Reptile::Reptile(string nameValue, string colorValue, string dietValue, string habitatValue, string soundsValue, bool isPetValue, int ageValue, double weightValue, double heightValue, string scalePatternValue)
    : Animal(nameValue, colorValue, dietValue, habitatValue, soundsValue, isPetValue, ageValue, weightValue, heightValue), 
      scalePattern(scalePatternValue) {}

Reptile::Reptile(const Reptile& other)
    : Animal(other), scalePattern(other.scalePattern) {}

string Reptile::getScalePattern() const {
    return scalePattern;
}

void Reptile::setScalePattern(const string& scalePatternValue) {
    scalePattern = scalePatternValue;
}

void Reptile::makeSound() const {
    cout << getName() << " says: " << getSounds() << endl;
}

void Reptile::printInfo() const {
    cout << "Animal of type: Reptile" << endl; 
    cout << "Name: " << getName() << endl; 
    cout << "Color: " << getColor() << endl;
    cout << "Scale Pattern: " << scalePattern << endl;
    cout << "Diet: " << getDiet() << endl;
    cout << "Habitat: " << getHabitat() << endl;
    cout << "Age: " << getAge() << "'s old" << endl;
    cout << "This animal is " << (getIsPet() ? "" : "not ") << "a pet" << endl; 
    cout << "Sounds: " << getSounds() << endl;
    cout << "Weight: " << getWeight() << " kg" << endl;
    cout << "Height: " << getHeight() << " cm\n" << endl;
}
