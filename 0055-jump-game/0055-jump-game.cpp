class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        vector<bool> dp(n, false);

        dp[n - 1] = true;

        for(int i = n - 2; i >= 0; i--){

            int jump = nums[i];

            for(int j = 1; j <= jump && i + j < n; j++){

                if(dp[i + j]){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};