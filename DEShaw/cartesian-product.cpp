#include <iostream>
#include <set>
#include <vector>

template <typename T>
vector<pair<T,T>> cartesian_product(const set<T>& set1, const set<T>& set2) {
    vector<pair<T,T>> res;
    for(const T &x: set1) {
        for(const T &y: set2) {
            res.emplace_back(x,y);
        }
    }
    return res;
}

int main() {
    set<int> set1 = {1,2,3};
    set<int> set2 = {4, 5, 6};
    auto result = cartesian_product(set1, set2);
    
    for(const auto& pair: result) {
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }
    return 0;
    
}
