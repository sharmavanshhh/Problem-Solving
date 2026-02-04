class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int longest = 0;
        for(int x : set){
            if(!set.count(x -1)){
                int curr = x;
                int len = 1;

                while(set.count(curr + 1)){
                    curr++;
                    len++;
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};