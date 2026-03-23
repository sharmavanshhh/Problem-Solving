class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<long long, long long>>> dp(m, vector<pair<long long, long long>>(n));

        // Base case
        dp[0][0] = {grid[0][0], grid[0][0]};

        // First row
        for(int j = 1; j < n; j++) {
            long long val = grid[0][j];
            long long prevMax = dp[0][j-1].first;
            long long prevMin = dp[0][j-1].second;

            dp[0][j].first = max(val * prevMax, val * prevMin);
            dp[0][j].second = min(val * prevMax, val * prevMin);
        }

        // First column
        for(int i = 1; i < m; i++) {
            long long val = grid[i][0];
            long long prevMax = dp[i-1][0].first;
            long long prevMin = dp[i-1][0].second;

            dp[i][0].first = max(val * prevMax, val * prevMin);
            dp[i][0].second = min(val * prevMax, val * prevMin);
        }

        // Fill rest
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                long long val = grid[i][j];

                auto top = dp[i-1][j];
                auto left = dp[i][j-1];

                vector<long long> vals = {
                    val * top.first,
                    val * top.second,
                    val * left.first,
                    val * left.second
                };

                dp[i][j].first = *max_element(vals.begin(), vals.end());
                dp[i][j].second = *min_element(vals.begin(), vals.end());
            }
        }

        long long ans = dp[m-1][n-1].first;

        if(ans < 0) return -1;

        return ans % 1000000007;
    }
};