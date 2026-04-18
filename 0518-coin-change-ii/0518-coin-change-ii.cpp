class Solution {
public:
    int change(int amount, vector<int>& coins) {

        const int MOD = 1e9 + 7;
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for(int coin : coins){
            for(int j = coin; j <= amount; j++){
                dp[j] = (dp[j] + dp[j - coin]) % MOD;
            }
        }

        return dp[amount];
    }
};