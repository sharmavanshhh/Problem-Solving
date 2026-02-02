class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; i++) {
            groups[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        for (auto& g : groups) {
            vector<int>& indices = g.second;
            if (indices.size() == 1)
                continue;

            long long totalIndexSum = 0;
            for (int idx : indices) {
                totalIndexSum += idx;
            }

            long long leftIndexSum = 0;

            for (int j = 0; j < indices.size(); j++) {
                long long currIndex = indices[j];

                long long rightIndexSum =
                    totalIndexSum - leftIndexSum - currIndex;
 
                long long leftPart = (long long)currIndex * j - leftIndexSum;

                long long rightPart =
                    rightIndexSum -
                    (long long)currIndex * (indices.size() - j - 1);

                ans[currIndex] = leftPart + rightPart;

                leftIndexSum += currIndex;
            }
        }

        return ans;
    }
};