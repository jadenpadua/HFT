class Solution {
private:

    void dfs(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || i > n-1 ||  j < 0 || j > m - 1 || grid[i][j] != '1') return;
        grid[i][j] = '#';

        dfs(grid, i, j-1);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i+1, j);
    }  

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int res {};

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == '1') {
                    dfs(grid,i,j);
                    ++res;
                }
               
            }
        }
        return res;
    }
};
