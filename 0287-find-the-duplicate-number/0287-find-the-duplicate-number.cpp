class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while(i < n){
            int index = nums[i] - 1;
            if(nums[i] != nums[index]){
                swap(nums[i], nums[index]);
            }
            else{
                i++;
            }
        }
        for(int k=0; k<n; k++){
            if(nums[k] != k+1){
                return nums[k];
            }
        }
        return n;
    }
};