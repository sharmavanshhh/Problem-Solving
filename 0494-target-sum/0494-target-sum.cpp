class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int total = 0;
        for(int x : nums) total += x;

        if((target + total < 0 ) || ((target + total) & 1)) return 0;

        int sum = (target + total) / 2;

        vector<vector<int>> dp(n+1, vector<int>(sum + 1, 0));

        dp[0][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                int skip = dp[i-1][j];
                int take = 0;
                if(nums[i-1] <= j){
                    take = dp[i-1][j - nums[i-1]];
                }
                dp[i][j] = skip + take;
            }
        }

        return dp[n][sum];
    }
};