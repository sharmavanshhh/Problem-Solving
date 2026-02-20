class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0)
            return false;

        int target = total / k;
        sort(nums.rbegin(), nums.rend());

        vector<bool> used(nums.size(), false);

        return backtrack(nums, used, k, 0, 0, target);
    }

    bool backtrack(vector<int>& nums, vector<bool>& used, int k, int currSum,
                   int start, int target) {
        
        if(k == 1) return true;

        if(currSum == target){
            return backtrack(nums, used, k - 1, 0, 0, target);
        }

        for(int i = start; i < nums.size(); i++){
            if(used[i] || currSum + nums[i] > target){
                continue;
            }
            used[i] = true;

            if(backtrack(nums, used, k, currSum + nums[i], i + 1, target)){
                return true;
            }

            used[i] = false;
        }

        return false;
    }
};