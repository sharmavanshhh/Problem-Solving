class Solution {
public:

    int solve(vector<int>& prices, int idx, int cap, bool canBuy,
              vector<vector<vector<int>>>& dp){

        if(idx == prices.size() || cap == 0) return 0;

        if(dp[idx][cap][canBuy] != -1)
            return dp[idx][cap][canBuy];

        if(canBuy){

            int skip = solve(prices, idx+1, cap, true, dp);

            int buyStock = -prices[idx] + solve(prices, idx+1, cap, false, dp);

            return dp[idx][cap][canBuy] = max(skip, buyStock);
        }
        else{

            int skip = solve(prices, idx+1, cap, false, dp);

            int sellStock = prices[idx] + solve(prices, idx+1, cap-1, true, dp);

            return dp[idx][cap][canBuy] = max(skip, sellStock);
        }
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector dp(n, vector(3, vector<int>(2, -1)));

        return solve(prices, 0, 2, true, dp);
    }
};