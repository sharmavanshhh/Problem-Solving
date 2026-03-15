class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;

        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        dp[0] = matrix[0];

        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                int up = dp[i-1][j];
                int leftD = (j > 0) ? dp[i-1][j-1] : INT_MAX;
                int rightD = (j < n - 1) ? dp[i-1][j+1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({up, leftD, rightD});
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};