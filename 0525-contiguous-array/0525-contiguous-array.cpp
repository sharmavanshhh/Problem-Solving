class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int count0 = 0;
        int count1 = 0;
        int maxLength = 0;

        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                count0++;
            }
            else{
                count1++;
            }

            int diff = count0 - count1;

            if(mp.count(diff)){
                int length = i - mp[diff];
                maxLength = max(length, maxLength);
            }
            else{
                mp[diff] = i;
            }
        }

        return maxLength;
    }
};