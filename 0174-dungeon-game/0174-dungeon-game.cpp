class Solution {
public:

    int solve(vector<vector<int>>& dungeon, int i, int j, int m, int n, vector<vector<int>>& dp){

        if(i >= m || j >= n)
            return INT_MAX;
        
        if(dp[i][j] != -1) return dp[i][j];

        if(i == m-1 && j == n-1)
            return max(1, 1 - dungeon[i][j]);

        int right = solve(dungeon, i, j+1, m, n, dp);
        int down  = solve(dungeon, i+1, j, m, n, dp);

        int need = min(right, down) - dungeon[i][j];

        return dp[i][j] = max(1, need);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(dungeon, 0, 0, m, n, dp);
    }
};