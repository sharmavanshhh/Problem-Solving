class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int sum = 0;
        int maxLen = 0;

        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            
            while((right - left + 1) - sum > k){
                sum -= nums[left];
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};