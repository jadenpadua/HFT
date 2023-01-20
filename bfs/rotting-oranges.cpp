class Solution {
private:
    bool isInBounds(int n, int m, int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = -1;
        int freshCount {};

        queue<pair<int,int>> q {};
        vector<pair<int,int>> dirs = {{0,-1}, {-1,0}, {0,1}, {1,0}};

        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
                else if(grid[i][j] == 1) {
                    ++freshCount;
                }
            }
        }

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                pair<int,int> popped = q.front(); q.pop();
                int i = popped.first, j = popped.second;
                for(auto d: dirs) {
                    int newI = i + d.first, newJ = j + d.second;
                    if(isInBounds(n,m,newI, newJ) && grid[newI][newJ] == 1) {
                        grid[newI][newJ] = 2;
                        q.push({newI, newJ});
                        --freshCount;
                    }
                } 
            }
            ++res;
        }
        if(freshCount > 0) return -1;
        else if(res == -1) return 0;
        return res;

    }
};
