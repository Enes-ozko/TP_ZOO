#include "Animal.h"
using namespace std;

Animal::Animal() : name("Unknown"), color("Unknown"), diet("Unknown"), habitat("Unknown"), sounds("Unknown"), isPet(false), age(0), weight(0.0), height(0.0) {}

Animal::Animal(string nameValue, string colorValue, string dietValue, string habitatValue, string soundsValue, bool isPetValue, int ageValue, double weightValue, double heightValue)
    : name(nameValue), color(colorValue), diet(dietValue), habitat(habitatValue), sounds(soundsValue), isPet(isPetValue), age(ageValue), weight(weightValue), height(heightValue) {}

Animal::Animal(const Animal& other)
    : name(other.name), color(other.color), diet(other.diet), habitat(other.habitat), sounds(other.sounds), isPet(other.isPet), age(other.age), weight(other.weight), height(other.height) {}   

void Animal::printInfo() const {
    cout << "Animal of unknown type" << endl;
    cout << "Name: " << name << endl;
    cout << "Color: " << color << endl;
    cout << "Diet: " << diet << endl;
    cout << "Habitat: " << habitat << endl;
    cout << "Age: " << age << "'s old" << endl;
    cout << "This animal is " << (isPet ? "" : "not ") << "a pet" << endl; 
    cout << "Sounds: " << sounds << endl;
    cout << "Weight: " << weight << " kg" << endl;
    cout << "Height: " << height << "cm \n" << endl;
}

string Animal::getName() const { return name; }
string Animal::getColor() const { return color; }
string Animal::getDiet() const { return diet; }
string Animal::getHabitat() const { return habitat; }
string Animal::getSounds() const { return sounds; }
bool Animal::getIsPet() const { return isPet; }
int Animal::getAge() const { return age; }
double Animal::getWeight() const { return weight; }
double Animal::getHeight() const { return height; }

void Animal::setName(const string& nameValue) { name = nameValue; }
void Animal::setColor(const string& colorValue) { color = colorValue; }
void Animal::setDiet(const string& dietValue) { diet = dietValue; }
void Animal::setHabitat(const string& habitatValue) { habitat = habitatValue; }
void Animal::setSounds(const string& soundsValue) { sounds = soundsValue; }
void Animal::setIsPet(const bool& isPetValue) { isPet = isPetValue; }
void Animal::setAge(const int& ageValue) { age = ageValue; }
void Animal::setWeight(const double& weightValue) { weight = weightValue; }
void Animal::setHeight(const double& heightValue) { height = heightValue; }
