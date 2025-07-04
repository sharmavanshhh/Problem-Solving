class Solution {
public:

     void recursion(vector<int>& nums, vector<vector<int>>& ans, vector<int> temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if (find(temp.begin(), temp.end(), nums[i]) != temp.end()) continue;
            temp.push_back(nums[i]);
            recursion(nums, ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;

        recursion(nums, result, temp);

        return result;
    }
};