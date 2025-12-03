#ifndef ZOO_H
#define ZOO_H
#include <string>
#include <vector>
#include <algorithm> 
#include <iostream>
#include "Animal.h"
using namespace std;


class Zoo {
    private:
        string name;
        static const int MAX_CAPACITY; 
        vector<Animal*> animals;

    public:
        Zoo(); 
        Zoo(string nameValue); 
        Zoo(const Zoo& other); 
        Zoo& operator=(const Zoo& other);
        ~Zoo();

        string getName() const;
        void setName(const string& nameValue);
    
        void listAnimals() const;
        void addAnimal(Animal* animal); 
        int searchAnimalByName(const string& animalName) const; 
        bool removeAnimalByName(const string& animalName);
        double averageAgeForType(const string& animalType) const;
        const vector<Animal*>& getAnimals() const { return animals; }

        string predictTypeWithKNN(const Animal& newAnimal, int k, const string& dataType); //4
    
};

#endif 