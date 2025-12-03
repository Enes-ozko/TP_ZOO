#ifndef BIRD_H
#define BIRD_H
#include "Animal.h" 
using namespace std;


class Bird : public Animal {
    private:
        double wingspan; 

    public:
        Bird();
        Bird(string nameValue, string colorValue, string dietValue, string habitatValue, string soundsValue, bool isPetValue, int ageValue, double weightValue, double heightValue, double wingspanValue);
        Bird(const Bird& other);
        virtual ~Bird() = default;

        double getWingspan() const;
        void setWingspan(const double& wingspanValue);

        void printInfo() const override; 
        void makeSound() const override; 
};

#endif 