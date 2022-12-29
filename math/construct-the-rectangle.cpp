class Solution {
public:
    vector<int> constructRectangle(int area) {
        for(int i = sqrt(area); i >= 0; --i) {
            if(area % i == 0) return {area / i, i};
        }
        return {-1,-1};
    }
};
