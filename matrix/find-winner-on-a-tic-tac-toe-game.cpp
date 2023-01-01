class Solution {
public:
    bool checkRowWin(int i, int j, vector<vector<char>> &board, char c) {
        int count {};
        for(int k = 0; k < 3; ++k) {
            if(board[i][k] == c) count++;
        }
        return count == 3;
    }
    bool checkColWin(int i, int j, vector<vector<char>> &board, char c) {
        int count {};
        for(int k = 0; k < 3; ++k) {
            if(board[k][j] == c) count++;
        }
        return count == 3;
    }
    bool checkDiagWin(int i, int j, vector<vector<char>> &board, char c) {
        if(i != j && i + j != board.size() - 1) return false;
        int primaryDiagCount {};
        for(int k = 0; k < 3; ++k) {
            if(board[k][k] == c) primaryDiagCount++;
        }

        int secondaryDiagCount {};
        for(int k = 0; k < 3; ++k) {
            if(board[k][3 - k - 1] == c) secondaryDiagCount++;
        }
        return primaryDiagCount == 3 || secondaryDiagCount == 3;
    }

    string tictactoe(vector<vector<int>>& moves) {
        int n = moves.size();
        vector<vector<char>> board(vector(3, vector(3, '-')));
        
        int idx = 0;
        for(auto& move: moves) {
            int i = move[0], j = move[1];
            char c = idx%2 == 0 ? 'X' : 'O';
            board[i][j] = c;
            if(checkRowWin(i,j,board, c) || checkColWin(i,j,board, c) || checkDiagWin(i,j,board, c)) {
                return idx%2 == 0 ? "A" : "B";
            }
            idx++;
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
