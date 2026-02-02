class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        sort(nums.begin(), nums.end());
    
        int ans = 0;
        while(left < right){
            int sum = nums[left] + nums[right];
            ans = max(sum, ans);
            left++;
            right--;
        }

        return ans;
    }
};