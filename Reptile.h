#ifndef REPTILE_H
#define REPTILE_H
#include "Animal.h" 
using namespace std;

class Reptile : public Animal {
    private:
        string scalePattern; 
    public:
        Reptile();
        Reptile(string nameValue, string colorValue, string dietValue, string habitatValue, string soundsValue, bool isPetValue, int ageValue, double weightValue, double heightValue, string scalePatternValue);
        Reptile(const Reptile& other);
        virtual ~Reptile() = default;

        string getScalePattern() const;
        void setScalePattern(const string& scalePatternValue);

        void printInfo() const override; 
        void makeSound() const override; 
};

#endif 