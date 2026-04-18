class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int totalSum = 0;
        for(int x : nums) totalSum += x;

        int leftSum = 0;

        for(int i = 0; i < nums.size(); i++){
            long long rightSum = totalSum - leftSum - nums[i];

            int leftPart = (long long) nums[i] * i - leftSum;
            int rightPart = rightSum - (long long) nums[i] * (n - i - 1);

            ans[i] = leftPart + rightPart;

            leftSum += nums[i];
        }
        return ans;
    }
};