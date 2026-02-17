class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        sort(nums.begin(), nums.end());

        backtrack(nums, ans, curr, 0);

        return ans;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int start){
        ans.push_back(curr);

        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            backtrack(nums, ans, curr, i+1);
            curr.pop_back();
        }
    }
};