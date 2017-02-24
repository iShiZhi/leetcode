class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9) return false;
        for (int i = 0; i < 9; i++) {
            if (board[i].size() != 9) return false;
        }
        
        bool used[9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                used[j] = false;
            }
            
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (used[board[i][j] - '1']) {
                    return false;
                } else {
                    used[board[i][j] - '1'] = true;
                }
            }
            
            for (int j = 0; j < 9; j++) {
                used[j] = false;
            }
            
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                if (used[board[j][i] - '1']) {
                    return false;
                } else {
                    used[board[j][i] - '1'] = true;
                }
            }
        }
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 9; k++) {
                   used[k] = false;
                }
                
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (board[i * 3 + k][j * 3 + l] == '.') continue;
                        if (used[board[i * 3 + k][j * 3 + l] - '1']) {
                            return false;
                        } else {
                            used[board[i * 3 + k][j * 3 + l] - '1'] = true;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};