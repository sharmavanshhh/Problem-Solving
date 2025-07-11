class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int days_worked = 0;
        vector<vector<int>> result;
        if (meetings.empty())
            return 0;
        result.push_back(meetings[0]);

        for (int i = 1; i < meetings.size(); i++) {
            vector<int>& last = result.back();

            if (meetings[i][0] <= last[1]) {
                last[1] = max(last[1], meetings[i][1]);
            } else {
                result.push_back(meetings[i]);
            }
        }

        for (int i = 0; i < result.size(); i++) {
            days_worked += ((result[i][1] + 1) - result[i][0]);
        }
        return days - days_worked;
    }
};