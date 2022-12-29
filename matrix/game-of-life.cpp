class Solution {
public:

    int calcNextState(int i, int j, vector<vector<int>>& board, int n, int m) {
        int neighborCount {};
        for(int I = max(i-1, 0); I < min(i+2, n); ++I) {
            for(int J = max(j-1,0); J < min(j+2, m); ++J) {
                if(I == i && J == j) continue;
                if(board[I][J] == 1 || board[I][J] == 2) neighborCount++;
            }
        }
        if(board[i][j] == 1 && (neighborCount < 2 || neighborCount > 3)) return 2;    
        if(board[i][j] == 0 && neighborCount == 3) return 3;

        return board[i][j];
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                board[i][j] = calcNextState(i,j,board,n,m);
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                board[i][j] %= 2;
            }
        }
    }
};
