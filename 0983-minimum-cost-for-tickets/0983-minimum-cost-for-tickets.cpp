class Solution {
public:
    int solve(int index, vector<int>& days, vector<int>& costs, vector<int>& dp){
        if(index >= days.size()) return 0;

        if(dp[index] != -1) return dp[index];

        int daily = costs[0] + solve(index + 1, days, costs, dp);

        int j = index;
        while(j < days.size() && days[j] < days[index] + 7) j++;
        int weekly = costs[1] + solve(j, days, costs, dp);

        j = index;
        while(j < days.size() && days[j] < days[index] + 30) j++;
        int monthly = costs[2] + solve(j, days, costs, dp);

        return dp[index] = min({daily, weekly, monthly});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int d = days.size();
        int c = costs.size();
        vector<int> dp(d, -1);
        return solve(0, days, costs, dp);
    }
};