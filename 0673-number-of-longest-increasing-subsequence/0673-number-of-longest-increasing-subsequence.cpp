class Solution {
public:
    pair<int, int> solve(vector<int>& nums, int index, int prevIndex,
                         vector<vector<pair<int,int>>>& dp) {

        if(index == nums.size()) return {0, 1};

        if(dp[index][prevIndex + 1].first != -1)
            return dp[index][prevIndex + 1];

        auto skip = solve(nums, index + 1, prevIndex, dp);

        pair<int, int> take = {0, 0};

        if(prevIndex == -1 || nums[index] > nums[prevIndex]){
            auto next = solve(nums, index + 1, index, dp);
            take.first = 1 + next.first;
            take.second = next.second;
        }

        if(take.first > skip.first)
            return dp[index][prevIndex + 1] = take;

        if(skip.first > take.first)
            return dp[index][prevIndex + 1] = skip;

        return dp[index][prevIndex + 1] =
            make_pair(take.first, take.second + skip.second);
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n+1, {-1, -1}));

        return solve(nums, 0, -1, dp).second;
    }
};