class Solution {
public:
    void recursion(vector<int>& nums, vector<vector<int>>& ans, int start, vector<int> temp){
        ans.push_back(temp);

        for(int i = start; i < nums.size(); i++){
            // Skip duplicates
            if(i > start && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);
            recursion(nums, ans, i + 1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;

        sort(nums.begin(), nums.end()); // sort to bring duplicates together
        recursion(nums, result, 0, temp);

        return result;
    }
};
