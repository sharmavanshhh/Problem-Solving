class Solution {
public:
    int atMost(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int left = 0;
        int count = 0;
        int sum = 0;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(sum > goal){
                sum -= nums[left];
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int& x : nums){
            x %= 2;
        }

        return atMost(nums, k) - atMost(nums, k-1);
    }
};