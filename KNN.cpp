#include "KNN.h"
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
KNN<T>::KNN() : k(1) {}

template <typename T>
KNN<T>::KNN(int kValue) : k(kValue) {}

template <typename T>
int KNN<T>::getK() const {
    return k;
}

template <typename T>
vector<int> KNN<T>::findNearestNeighbours(const vector<T>& trainData, const T& target) const {
    vector<pair<double, int>> distances;
    distances.reserve(trainData.size());

    for (size_t i = 0; i < trainData.size(); ++i) {
        double dist = similarityMeasure(trainData[i], target);
        distances.emplace_back(dist, static_cast<int>(i));
    }

    int limit = min(k, static_cast<int>(distances.size()));
    
    partial_sort(distances.begin(), distances.begin() + limit, distances.end(),
        [](const pair<double, int>& a, const pair<double, int>& b) {
            return a.first < b.first;
        });

    vector<int> indices;
    indices.reserve(limit);
    for (int i = 0; i < limit; ++i) {
        indices.push_back(distances[i].second);
    }

    return indices;
}

//Instanciations pour les types utilisés plus tard
template class KNN<pair<double, double>>;
template class KNN<vector<string>>;