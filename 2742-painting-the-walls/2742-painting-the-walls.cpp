class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 1e9));

        for(int i = 0; i <= n; i++) dp[i][0] = 0;

        for(int index = n - 1; index >= 0; index--){
            for(int walls = 1; walls <= n; walls++){
                int skip = dp[index + 1][walls];

                int take = cost[index];
                int newWalls = max(0, walls - 1 - time[index]);
                take += dp[index + 1][newWalls];

                dp[index][walls] = min(take, skip);
            }
        }

        return dp[0][n];
    }
};