class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int currMax = 0, maxSum = nums[0];
        int currMin = 0, minSum = nums[0];

        for(int x : nums){
            totalSum += x;
            currMax = max(currMax + x, x);
            maxSum = max(currMax, maxSum);
            currMin = min(currMin + x, x);
            minSum = min(currMin, minSum);
        }

        if(maxSum < 0){
            return maxSum;
        }
        return max(maxSum, totalSum - minSum);
    }
};