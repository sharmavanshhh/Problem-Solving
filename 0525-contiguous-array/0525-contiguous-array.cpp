class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        int maxLength = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) sum--;
            else sum++;

            if(mp.count(sum)){
                int length = i - mp[sum];
                maxLength = max(length, maxLength);
            }
            else{
                mp[sum] = i;
            }
        }
        return maxLength;
    }
};