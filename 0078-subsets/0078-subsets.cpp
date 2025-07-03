class Solution {
public:

    void sub(vector<int>& nums, vector<vector<int>>& result, int index, vector<int>& currSub){
        if(index == nums.size()){
            result.push_back(currSub);
            return;
        }

        currSub.push_back(nums[index]);
        sub(nums, result, index+1, currSub);
        currSub.pop_back();
        sub(nums, result, index+1, currSub);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currSub;
        sub(nums, result, 0, currSub);

        return  result;

    }
};