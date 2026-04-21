class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> dp(n + 3, 0);

        for(int i = n - 1; i >= 0; i--){
            long long cost = max(0, k - nums[i]);

            dp[i] = cost + min({dp[i+1], dp[i+2], dp[i+3]});
        }

        return min({dp[0], dp[1], dp[2]});
    }
};