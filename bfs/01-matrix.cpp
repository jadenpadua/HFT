class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0)), vis(n, vector<int>(m, 0));
        queue<pair<pair<int,int>, int>> q {};

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(mat[i][j] == 0) {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else { 
                    vis[i][j] = 0;
                }
            }
        }
        int dRow[]={-1,0,1,0};
        int dCol[]={0,1,0,-1};
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            res[r][c] = dist;

            for(int i = 0; i < 4; ++i) {
                int newRow = r + dRow[i], newCol = c + dCol[i];
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && vis[newRow][newCol] == 0) {
                    q.push({{newRow, newCol}, dist + 1});
                    vis[newRow][newCol] = 1;
                }
            }
        }
        return res;
    }
};
