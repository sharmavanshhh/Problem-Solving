class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        if (intervals.empty()) {
            return ans;
        }

        sort(intervals.begin(), intervals.end());  // Sort by start time

        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            // Compare with last interval in ans
            if (intervals[i][0] <= ans.back()[1]) {
                // Merge with last interval
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
