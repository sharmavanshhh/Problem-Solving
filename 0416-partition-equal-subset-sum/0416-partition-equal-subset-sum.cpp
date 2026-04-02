class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x : nums) sum += x;

        if(sum % 2 != 0) return false;

        int target = sum / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));

        // base case
        for(int i = 0; i <= n; i++) dp[i][0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){

                bool skip = dp[i-1][j];
                bool take = false;

                if(nums[i-1] <= j){
                    take = dp[i-1][j - nums[i-1]];
                }

                dp[i][j] = skip || take;
            }
        }

        return dp[n][target];
    }
};