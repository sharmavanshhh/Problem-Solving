class Solution {
public:
    long long n;
    vector<vector<long long>> dp;

    long long solve(long long idx, vector<int>& nums, bool flag){
        if(idx >= n) return 0;

        if(dp[idx][flag] != -1) return dp[idx][flag];

        long long skip = solve(idx + 1, nums, flag);

        long long val = nums[idx];

        if(!flag) val = -val;

        long long take = solve(idx + 1, nums, !flag) + val; 

        return dp[idx][flag] = max(skip, take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();

        dp.assign(n, vector<long long>(2, -1));

        return solve(0, nums, true);
    }
};