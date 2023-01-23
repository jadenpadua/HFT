class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bot = matrix.size() - 1;
        int dir = 1;

        vector<int> res {};
        while(res.size() < n * m) {
            switch(dir) {
                case 1:
                    for(int i = left; i <= right; i++) res.push_back(matrix[top][i]);
                    ++top;
                    dir = 2;
                    break;
                case 2:
                    for(int i = top; i <= bot; i++) res.push_back(matrix[i][right]);
                    dir = 3;
                    --right;
                    break;
                case 3:
                    for(int i = right; i >= left; i--) res.push_back(matrix[bot][i]);
                    dir = 4;
                    --bot;
                    break;
                case 4:
                    for(int i = bot; i >= top; i--) res.push_back(matrix[i][left]);
                    dir = 1;
                    ++left;
                    break;
            }
        }
        return res;
    }
};
