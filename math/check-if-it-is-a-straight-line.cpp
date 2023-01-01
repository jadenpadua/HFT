class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        int x0 = coordinates[0][0], x1 = coordinates[1][0], dX = x1 - x0;
        int y0 = coordinates[0][1], y1 = coordinates[1][1], dY = y1 - y0;
        
        for(int i=2; i<n; ++i) {
            int x = coordinates[i][0], y = coordinates[i][1];
            if(dX*(y-y1) != dY*(x-x1)) return false;
        }
        return true;
    }
};
