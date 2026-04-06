class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int total = 0;
        for(int x : nums) total += x;

        if((target + total < 0 ) || ((target + total) & 1)) return 0;

        int sum = (target + total) / 2;

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return solve(0, sum, nums, dp);
    }

    int solve(int index, int sum, vector<int>& nums, vector<vector<int>>& dp){
        if(index == nums.size()){
            return (sum == 0) ? 1 : 0;
        }

        if(dp[index][sum] != -1) return dp[index][sum];

        int skip = solve(index + 1, sum, nums, dp);
        int take = 0;
        if(nums[index] <= sum){
            take = solve(index + 1, sum - nums[index], nums, dp);
        }

        return dp[index][sum] = skip + take;
    }
};