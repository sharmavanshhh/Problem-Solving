class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        int ans = 0;
        for(int x : nums){
            freq[x]++;
            if(freq[x] > maxFreq){
                maxFreq = freq[x];
                ans = maxFreq;
            }
            else if(freq[x] == maxFreq){
                ans += maxFreq;
            }
        }
        return ans;
    }
};