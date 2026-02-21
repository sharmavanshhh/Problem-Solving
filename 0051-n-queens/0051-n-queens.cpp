class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));
        backtrack(n, ans, temp, 0);
        return ans;
    }

    void backtrack(int n, vector<vector<string>>& ans, vector<string>& temp, int row){
        if(row == n){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < n; i++){
            if(canPlace(row, i, temp, n)){
                temp[row][i] = 'Q';
                backtrack(n, ans, temp, row + 1);
                temp[row][i] = '.';
            }
        }
    }

    bool canPlace(int row, int col, vector<string>& temp, int n){
        for(int i = 0; i < n; i++){
            if(temp[i][col] == 'Q') return false; 
        }

        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if(temp[i][j] == 'Q') return false;
        }

        for(int i = row, j = col; i >= 0 && j < n; i--, j++){
            if(temp[i][j] == 'Q') return false;
        }

        return true;
    }
};