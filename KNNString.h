#ifndef KNNSTRING_H
#define KNNSTRING_H
#include "KNN.h"
#include <vector>
#include <string>
using namespace std;


class KNNString : public KNN<vector<string>> {
    private:
        int levenshteinDistance(const string& s1, const string& s2) const;

    public:
        KNNString(int kValue) : KNN<vector<string>>(kValue) {}
        double similarityMeasure(const vector<string>& a, const vector<string>& b) const override;
};

#endif 