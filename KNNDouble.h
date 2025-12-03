#ifndef KNNDOUBLE_H
#define KNNDOUBLE_H
#include "KNN.h"
#include <utility>
using namespace std;


class KNNDouble : public KNN<pair<double, double>> {
    public:
        KNNDouble(int kValue);
        double similarityMeasure(const pair<double, double>& a, const pair<double, double>& b) const override;
};

#endif