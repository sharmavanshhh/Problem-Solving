class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mask = 0;
        int l = 0;
        int ans = 1;
        for(int r = 0; r < nums.size(); r++){
            while((mask & nums[r]) != 0){
                mask = mask ^ nums[l];
                l++;
            }

            mask = mask | nums[r];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};