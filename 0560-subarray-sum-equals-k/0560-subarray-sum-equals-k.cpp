class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int count = 0;
        for(int x : nums){
            sum += x;
            int need = sum - k;
            if(mp.count(need)){
                count += mp[need];
            }
            mp[sum]++;
        }
        return count;
    }
};