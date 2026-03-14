// class Solution {
// public:
//     int solve(vector<int>& prices, int idx, int cap, bool canBuy,
//               vector<vector<vector<int>>>& dp){

//         if(idx == prices.size() || cap == 0) return 0;

//         if(dp[idx][cap][canBuy] != -1)
//             return dp[idx][cap][canBuy];

//         if(canBuy){

//             int skip = solve(prices, idx+1, cap, true, dp);

//             int buyStock = -prices[idx] + solve(prices, idx+1, cap, false, dp);

//             return dp[idx][cap][canBuy] = max(skip, buyStock);
//         }
//         else{

//             int skip = solve(prices, idx+1, cap, false, dp);

//             int sellStock = prices[idx] + solve(prices, idx+1, cap-1, true, dp);

//             return dp[idx][cap][canBuy] = max(skip, sellStock);
//         }
//     }

//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();

//         vector dp(n, vector(3, vector<int>(2, -1)));

//         return solve(prices, 0, 2, true, dp);
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector dp(n+1, vector(3, vector<int>(2, 0)));

        for(int idx = n-1; idx >= 0; idx--){

            for(int cap = 1; cap <= 2; cap++){

                for(int buy = 0; buy <= 1; buy++){

                    if(buy){

                        int skip = dp[idx+1][cap][1];

                        int buyStock =
                            -prices[idx] + dp[idx+1][cap][0];

                        dp[idx][cap][1] = max(skip, buyStock);
                    }

                    else{

                        int skip = dp[idx+1][cap][0];

                        int sellStock =
                            prices[idx] + dp[idx+1][cap-1][1];

                        dp[idx][cap][0] = max(skip, sellStock);
                    }
                }
            }
        }

        return dp[0][2][1];
    }
};



