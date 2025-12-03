#include <iostream>
#include "Zoo.h"
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"
using namespace std;

int main() {
    Zoo zoo("Zoo TP");

    zoo.addAnimal(new Mammal("Lion", "Jaune", "Carnivore", "Savane", "Rugissement", false, 6, 190.0, 120.0, "Doree"));
    zoo.addAnimal(new Mammal("Elephant", "Gris", "Herbivore", "Jungle", "Barrit", false, 25, 5000.0, 300.0, "Grise"));
    
    zoo.addAnimal(new Bird("Perroquet", "Vert", "Omnivore", "Foret", "Parle", true, 50, 1.0, 30.0, 0.4));
    zoo.addAnimal(new Bird("Aigle", "Noir", "Carnivore", "Montagne", "Cri", false, 5, 6.0, 70.0, 2.0));

    zoo.addAnimal(new Reptile("Crocodile", "Vert", "Carnivore", "Marais", "Sifflement", false, 15, 400.0, 50.0, "Ecailles Dures"));
    zoo.addAnimal(new Reptile("Serpent", "Gris", "Carnivore", "Foret", "Sifflement", false, 3, 2.0, 5.0, "Ecailles Lisses"));

    zoo.listAnimals();

    cout << "\nTests Gestion" << endl;
    cout << "Recherche 'Elephant' (index): " << zoo.searchAnimalByName("Elephant") << endl;
    cout << "Age moyen des Oiseaux: " << zoo.averageAgeForType("Bird") << " ans" << endl;

    if (zoo.removeAnimalByName("Perroquet")) {
        cout << "'Perroquet' supprime avec succes." << endl;
    }

    cout << "\nTests KNN " << endl;
    int k = 3;

    Mammal testLourd("TestLourd", "", "", "", "", false, 0, 4000.0, 280.0, "");
    cout << "Prediction 1 (Poids/Taille) : " << zoo.predictTypeWithKNN(testLourd, k, "numerical") << endl;

    Reptile testAttributs("TestReptile", "Vert", "Carnivore", "Marais", "Sifflement", false, 0, 0, 0, "");
    cout << "Prediction 2 (Attributs)    : " << zoo.predictTypeWithKNN(testAttributs, k, "categorical") << endl;

    return 0;
}