class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int d = days.size();
        int c = costs.size();
        vector<int> dp(d + 1, 0);

        for(int i = d - 1; i >= 0; i--){
            int daily = costs[0] + dp[i+1];

            int j = i;
            while(j < d && days[j] < days[i] + 7) j++;
            int weekly = costs[1] + dp[j];

            j = i;
            while(j < d && days[j] < days[i] + 30) j++;
            int monthly = costs[2] + dp[j];

            dp[i] = min({daily, weekly, monthly});
        }

        return dp[0];
    }
};