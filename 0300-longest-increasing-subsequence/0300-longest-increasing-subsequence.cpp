class Solution {
public:

    int solve(vector<int>& nums, int index, int prevIndex,
              vector<vector<int>>& dp){

        if(index == nums.size())
            return 0;

        if(dp[index][prevIndex+1] != -1)
            return dp[index][prevIndex+1];

        int skip = solve(nums, index+1, prevIndex, dp);

        int take = 0;

        if(prevIndex == -1 || nums[index] > nums[prevIndex])
            take = 1 + solve(nums, index+1, index, dp);

        return dp[index][prevIndex+1] = max(skip, take);
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return solve(nums, 0, -1, dp);
    }
};