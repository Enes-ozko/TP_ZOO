#include "Zoo.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "Mammal.h" 
#include "Bird.h"
#include "Reptile.h" 
#include <string>
#include <vector>
#include "KNNDouble.h"
#include "KNNString.h"
#include <map>

using namespace std;

Animal* cloneAnimal(const Animal* animalPtr) {
    if (const Mammal* mammal = dynamic_cast<const Mammal*>(animalPtr)) {
        return new Mammal(*mammal);
    } else if (const Bird* bird = dynamic_cast<const Bird*>(animalPtr)) {
        return new Bird(*bird);
    } else if (const Reptile* reptile = dynamic_cast<const Reptile*>(animalPtr)) {
        return new Reptile(*reptile);
    }
    return nullptr; 
}


const int Zoo::MAX_CAPACITY = 100;

Zoo::Zoo() : name("Unnamed Zoo") {}
Zoo::Zoo(string nameValue) : name(nameValue) {}

Zoo::~Zoo() {
    for (Animal* animalPtr : animals) {
        delete animalPtr; 
    }
}

Zoo::Zoo(const Zoo& other) : name(other.name) {
    for (const Animal* animalPtr : other.animals) {
        if (Animal* newAnimal = cloneAnimal(animalPtr)) {
            animals.push_back(newAnimal);
        }
    }
}

Zoo& Zoo::operator=(const Zoo& other) {
    if (this != &other) {
        for (Animal* animalPtr : animals) {
            delete animalPtr;
        }
        animals.clear();
        
        name = other.name;

        for (const Animal* animalPtr : other.animals) {
            if (Animal* newAnimal = cloneAnimal(animalPtr)) {
                animals.push_back(newAnimal);
            }
        }
    }
    return *this;
}


string Zoo::getName() const { return name; }
void Zoo::setName(const string& nameValue) { name = nameValue; }


void Zoo::addAnimal(Animal* animal) {
    if (!animal || animals.size() >= MAX_CAPACITY) {
        if (animal) delete animal;
        return;
    }

    auto it = lower_bound(animals.begin(), animals.end(), animal->getName(), 
                            [](const Animal* a, const string& name_key) {
                                return a->getName() < name_key;
                            });
    
    if (it != animals.end() && (*it)->getName() == animal->getName()) {
        delete animal;
        return;
    }

    animals.insert(it, animal); 
}

int Zoo::searchAnimalByName(const string& animalName) const {
    auto it = lower_bound(animals.begin(), animals.end(), animalName, 
                                [](const Animal* a, const string& name_key) {
                                    return a->getName() < name_key;
                                });

    if (it != animals.end() && (*it)->getName() == animalName) {
        return std::distance(animals.begin(), it); 
    }

    return -1; 
}

bool Zoo::removeAnimalByName(const string& animalName) {
    int index = searchAnimalByName(animalName); 
    if (index != -1) {
        delete animals[index]; 
        animals.erase(animals.begin() + index);
        return true; 
    }
    return false; 
}

double Zoo::averageAgeForType(const string& animalType) const {
    int totalAge = 0;
    int count = 0;
    for (const Animal* animal : animals) {
        if ((animalType == "Mammal" && dynamic_cast<const Mammal*>(animal)) ||
            (animalType == "Bird" && dynamic_cast<const Bird*>(animal)) ||
            (animalType == "Reptile" && dynamic_cast<const Reptile*>(animal))) {
            totalAge += animal->getAge();
            count++;
        }
    }
    if (count == 0) {
        return 0.0;
    }
    return static_cast<double>(totalAge) / count;
}

void Zoo::listAnimals() const {
    for (const Animal* animalPtr : animals) {
        animalPtr->printInfo(); 
    }
}

string Zoo::predictTypeWithKNN(const Animal& newAnimal, int k, const string& dataType) {
    vector<int> nearestIndices;

    if (dataType == "numerical") {
        KNNDouble knn(k);
        
        vector<pair<double, double>> trainData;
        
        for (const Animal* animal : animals) {
            trainData.push_back(make_pair(animal->getWeight(), animal->getHeight()));
        }
        
        pair<double, double> target = make_pair(newAnimal.getWeight(), newAnimal.getHeight());
        nearestIndices = knn.findNearestNeighbours(trainData, target);

    } else if (dataType == "categorical") {
        KNNString knn(k);
        vector<vector<string>> trainData;
        
        for (const Animal* animal : animals) {
            vector<string> attributes;
            attributes.push_back(animal->getColor());
            attributes.push_back(animal->getDiet());
            attributes.push_back(animal->getHabitat());
            attributes.push_back(animal->getSounds());
            trainData.push_back(attributes);
        }
        
        vector<string> target;
        target.push_back(newAnimal.getColor());
        target.push_back(newAnimal.getDiet());
        target.push_back(newAnimal.getHabitat());
        target.push_back(newAnimal.getSounds());

        nearestIndices = knn.findNearestNeighbours(trainData, target);

    } else {
        return "Error: Invalid dataType";
    }

    map<string, int> typeCounts;
    for (int index : nearestIndices) {
        if (index >= 0 && index < animals.size()) {
            Animal* neighbor = animals[index];
            string type = "Unknown";
            
            if (dynamic_cast<Mammal*>(neighbor)) type = "Mammal";
            else if (dynamic_cast<Bird*>(neighbor)) type = "Bird";
            else if (dynamic_cast<Reptile*>(neighbor)) type = "Reptile";
            
            typeCounts[type]++;
        }
    }

    string bestType = "Unknown";
    int maxCount = -1;
    
    for (auto const& [type, count] : typeCounts) {
        if (count > maxCount) {
            maxCount = count;
            bestType = type;
        }
    }

    return bestType;
}