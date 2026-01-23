class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        int i = 0;
        int n = nums.size();
        while(i < n){
            int index = nums[i];
            if(nums[i] != nums[index]){
                swap(nums[i], nums[index]);
            }
            else{
                i++;
            }
        }
        for(int k=0; k<n; k++){
            if(nums[k] != k){
                ans.push_back(nums[k]);
            }
        }
        return ans;
    }
};