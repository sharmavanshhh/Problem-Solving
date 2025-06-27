class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        vector<int>ans;
        while(i < n){
            int index = nums[i];
            if(nums[i] != nums[index]){
                swap(nums[i], nums[index]);
            }
            else{
                i++;
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] != i){
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};