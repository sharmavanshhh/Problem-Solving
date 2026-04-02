class Solution {
public:
    bool solve(int index, int target, vector<int>& nums,
               vector<vector<int>>& dp){

        if(target == 0) return true;
        if(index == nums.size()) return false;

        if(dp[index][target] != -1) return dp[index][target];

        bool skip = solve(index + 1, target, nums, dp);

        bool take = false;
        if(nums[index] <= target){
            take = solve(index + 1, target - nums[index], nums, dp);
        }

        return dp[index][target] = skip || take;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x : nums) sum += x;

        if(sum % 2 != 0) return false;

        int target = sum / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return solve(0, target, nums, dp);
    }
};