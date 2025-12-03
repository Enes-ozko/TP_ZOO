#include "KNNString.h"
#include <algorithm>

int KNNString::levenshteinDistance(const string& s1, const string& s2) const {
    int m = s1.length();
    int n = s2.length();
    
    if (m == 0) return n;
    if (n == 0) return m;

    vector<int> prev(n + 1);
    vector<int> curr(n + 1);

    for (int j = 0; j <= n; j++) prev[j] = j;
    for (int i = 1; i <= m; i++) {
        curr[0] = i;
        for (int j = 1; j <= n; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            curr[j] = min({ prev[j] + 1, curr[j - 1] + 1, prev[j - 1] + cost });
        }
        prev = curr;
    }
    return prev[n];
}

double KNNString::similarityMeasure(const vector<string>& a, const vector<string>& b) const {
    double totalDist = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        totalDist += levenshteinDistance(a[i], b[i]);
    }
    return totalDist;
}