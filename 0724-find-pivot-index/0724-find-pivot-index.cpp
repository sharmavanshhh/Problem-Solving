class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int x : nums){
            sum += x;
        }

        int lsum = 0;
        for(int i=0; i<nums.size(); i++){
            int rsum = sum - lsum - nums[i];
            if(lsum == rsum){
                return i;
            }
            lsum += nums[i];
        }
        return -1;
    }
};