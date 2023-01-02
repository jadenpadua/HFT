class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle {};
        for(int i = 0; i < numRows; ++i) {
            vector<int> newRow(i+1, 1);
            for(int j = 1; j < i; ++j) {
                newRow[j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
            triangle.push_back(newRow);
        }
        return triangle;
    }
};
