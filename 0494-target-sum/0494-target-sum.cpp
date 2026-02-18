class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        backtrack(nums, target, ans, 0, 0);
        return ans;
    }

    void backtrack(vector<int>& nums, int target, int& ans, long long sum, int index){
        if(index == nums.size()){
            if(sum == target) ans++;
            return;
        }

        backtrack(nums, target, ans, sum + (long long)nums[index], index + 1);
        backtrack(nums, target, ans, sum - (long long)nums[index], index + 1);
    }
};