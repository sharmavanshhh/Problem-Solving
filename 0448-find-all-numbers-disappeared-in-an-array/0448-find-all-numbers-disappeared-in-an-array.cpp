class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int i = 0;
        int n = nums.size();

        while(i < n){
            int correctedIndex = nums[i] - 1;
            if(nums[i] != nums[correctedIndex]){
                swap(nums[i], nums[correctedIndex]);
            }
            else{
                i++;
            }
        }
        for(int k=0; k<n; k++){
            if(nums[k] != k+1){
                ans.push_back(k+1);
            }
        }
        return ans;
    }
};