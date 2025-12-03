#include "KNNDouble.h"
#include <cmath>
using namespace std;

KNNDouble::KNNDouble(int kValue) : KNN<pair<double, double>>(kValue) {}

double KNNDouble::similarityMeasure(const pair<double, double>& a, const pair<double, double>& b) const {    
    return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}