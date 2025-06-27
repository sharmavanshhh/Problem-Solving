class Solution {
public:
    void rotate(vector<int>& nums, int d) {
        int n = nums.size();
        d = d % n;
        reverse(nums.end() - d, nums.end());
        reverse(nums.begin(), nums.end() - d);
        reverse(nums.begin(), nums.end());
    }
};