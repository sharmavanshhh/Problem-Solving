class Solution {
public:
    int solve(int index, int walls, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp){
        if(walls <= 0) return 0;
        if(index == cost.size()) return 1e9;

        if(dp[index][walls] != -1) return dp[index][walls];

        int skip = solve(index + 1, walls, cost, time, dp);

        int take = cost[index] + solve(index + 1, walls - 1 - time[index], cost, time, dp);

        return dp[index][walls] = min(skip, take);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, n, cost, time, dp);
    }
};