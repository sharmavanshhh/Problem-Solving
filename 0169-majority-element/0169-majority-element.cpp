class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int lead = -1;

        for(int i=0; i<nums.size(); i++){
            if(count == 0){
                lead = nums[i];
            }
            else if(nums[i] == lead){
                count++;
            }
            else{
                count--;
            }
        }

        return lead;
    }
};