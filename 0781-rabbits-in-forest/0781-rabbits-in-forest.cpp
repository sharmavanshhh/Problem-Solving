class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;

        for(int x : answers){
            mp[x]++;
        }

        int total = 0;

        for(auto[x, freq] : mp){
            int groupSize = x + 1;
            int groups = (freq + groupSize - 1) / groupSize;
            total += groups * groupSize;
        }

        return total;
    }
};