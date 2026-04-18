class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n+1, vector<long long>(amount+1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= amount; j++){
                int skip = dp[i-1][j];
                int take = 0;
                if(coins[i-1] <= j){
                    take = dp[i][j - coins[i-1]];
                }

                dp[i][j] = (long long)skip + (long long)take;
            }
        }
        return dp[n][amount];
    }
};