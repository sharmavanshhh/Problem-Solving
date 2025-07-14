class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reached = 0;
        for(int i=0; i<nums.size(); i++){
            if(i > reached) return false;
            reached = max(reached, nums[i]+i);
        }
        return true;
    }
};