#ifndef KNN_H
#define KNN_H
#include <vector>
#include <utility>
#include <string>

using namespace std;

template <typename T>
class KNN {
    private:
        int k;

    public:
        KNN();
        KNN(int kValue);
        virtual ~KNN() = default;

        int getK() const;
        virtual double similarityMeasure(const T& a, const T& b) const = 0;
        vector<int> findNearestNeighbours(const vector<T>& trainData, const T& target) const;
};

#endif