#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>
using namespace std;



class Animal{
    private:
        string name;
        string color;
        string diet;
        string habitat;
        string sounds;
        bool isPet;
        int age;
        double weight;
        double height;

    public:
        Animal();
        Animal(string nameValue, string colorValue, string dietValue, string habitatValue, string soundsValue, bool isPetValue, int ageValue, double weightValue, double heightValue);
        Animal(const Animal& other);
        virtual ~Animal() = default;
        
        virtual void printInfo() const;
        virtual void makeSound() const = 0;

        string getName() const;
        string getColor() const;
        string getDiet() const;
        string getHabitat() const;
        string getSounds() const;
        bool getIsPet() const;
        int getAge() const;
        double getWeight() const;
        double getHeight() const;

        void setName(const string& nameValue);
        void setColor(const string& colorValue);
        void setDiet(const string& dietValue);
        void setHabitat(const string& habitatValue);
        void setSounds(const string& soundsValue);
        void setIsPet(const bool& isPetValue);
        void setAge(const int& ageValue);
        void setWeight(const double& weightValue);
        void setHeight(const double& heightValue);
};

#endif