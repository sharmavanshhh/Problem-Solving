class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> prefixX(m, vector<int>(n, 0));
        vector<vector<int>> prefixY(m, vector<int>(n, 0));

        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                prefixX[i][j] = (grid[i][j] == 'X');
                prefixY[i][j] = (grid[i][j] == 'Y');

                if(i > 0){
                    prefixX[i][j] += prefixX[i-1][j];
                    prefixY[i][j] += prefixY[i-1][j];
                }
                if(j > 0){
                    prefixX[i][j] += prefixX[i][j-1];
                    prefixY[i][j] += prefixY[i][j-1];
                }
                if(i > 0 && j > 0){
                    prefixX[i][j] -= prefixX[i-1][j-1];
                    prefixY[i][j] -= prefixY[i-1][j-1];
                }

                if(prefixX[i][j] == prefixY[i][j] && prefixX[i][j] > 0){
                    ans++;
                }
            }
        }

        return ans;
    }
};