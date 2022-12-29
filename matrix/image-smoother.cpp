class Solution {
public:

    int calcNeighborAvg(int i, int j, vector<vector<int>>& img, int n, int m) {
        int neighborSum {}, neighborCount {};
        for(int I = max(i-1, 0); I < min(i + 2, n); ++I) {
            for(int J = max(j-1, 0); J < min(j + 2, m); ++J) {
                neighborSum += img[I][J]; neighborCount += 1;
            }
        }
        return neighborSum / neighborCount;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                res[i][j] = calcNeighborAvg(i,j,img,n,m);
            }
        }
        return res;
    }
};
