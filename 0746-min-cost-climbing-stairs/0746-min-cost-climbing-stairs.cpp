// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n + 1);
//         dp[0] = dp[1] = 0;
//         for(int i = 2; i <= n; i++){
//             dp[i] = min((dp[i - 1] + cost[i - 1]), (dp[i - 2] + cost[i - 2]));
//         }
//         return dp[n];
//     }
// };


class Solution {
public:

    int solve(int i, vector<int>& cost){
        if(i <= 1) return 0;

        int oneStep = solve(i - 1, cost) + cost[i - 1];
        int twoStep = solve(i - 2, cost) + cost[i - 2];

        return min(oneStep, twoStep);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(n, cost);
    }
};