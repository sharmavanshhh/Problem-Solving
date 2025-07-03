class Solution {
public:

    // void sub(vector<int>& nums, vector<vector<int>>& result, int index, vector<int>& currSub){
    //     if(index == nums.size()){
    //         result.push_back(currSub);
    //         return;
    //     }

    //     currSub.push_back(nums[index]);
    //     sub(nums, result, index+1, currSub);
    //     currSub.pop_back();
    //     sub(nums, result, index+1, currSub);
    // }

    void iteration(vector<int>& nums, vector<vector<int>>& ans, int start, vector<int> temp){
        ans.push_back(temp);
        for(int i=start; i<nums.size(); i++){
            temp.push_back(nums[i]);
            iteration(nums, ans, i+1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;

        // vector<int> currSub;
        // sub(nums, result, 0, currSub);

        vector<int> temp;

        iteration(nums, result, 0, temp);

        return  result;

    }
};