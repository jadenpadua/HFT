/**
* Given:
* 1. i,j coordinate on matrix
* 2. dfs through neighbor if value of neighbor == val of current coordinate
* 3. color that number and keep recursing
*/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        dfs(image, sr, sc, oldColor, color);
        return image;
    }
private:
    void dfs(vector<vector<int>>& image, int i, int j, int oldColor, int newColor) {
        if(i < 0 || i >= image.size() || j < 0 || 
        j >= image[0].size() || image[i][j] == newColor || image[i][j] != oldColor) return;
        
        image[i][j] = newColor;
        dfs(image, i, j-1, oldColor, newColor);
        dfs(image, i-1, j, oldColor, newColor);
        dfs(image, i, j+1, oldColor, newColor);
        dfs(image, i+1, j, oldColor, newColor);
    }

};
