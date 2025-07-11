class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        long long freeDays = 0;
        int lastCovered = 0;

        for (const auto& m : meetings) {
            int start = m[0], end = m[1];
            if (start > lastCovered + 1) {
                freeDays += start - lastCovered - 1;
            }
            lastCovered = max(lastCovered, end);
        }

        // Add remaining free days after last meeting
        if (lastCovered < days) {
            freeDays += days - lastCovered;
        }

        return (int)freeDays;
    }
};