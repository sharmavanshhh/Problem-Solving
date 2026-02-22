class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }

    bool backtrack(vector<vector<char>>& board){
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.'){
                    for(char digit = '1'; digit <= '9'; digit++){
                        if(isValid(board, row, col, digit)){
                            board[row][col] = digit;
                            if(backtrack(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char digit){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == digit) return false;
            if(board[i][col] == digit) return false;
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[startRow + i][startCol + j] == digit){
                    return false;
                }
            }
        }
        return true;
    }
};