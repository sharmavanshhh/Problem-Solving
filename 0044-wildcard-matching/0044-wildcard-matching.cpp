class Solution {
public:
    int solve(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i == s.size() && j == p.size()) return 1;
        if(j == p.size()) return 0;

        if(i == s.size()){
            while(j < p.size()){
                if(p[j] != '*') return 0;
                j++;
            }
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solve(i+1, j+1, s, p, dp);
        }

        if(p[j] == '*'){
            return dp[i][j] = solve(i+1, j, s, p, dp) || solve(i, j+1, s, p, dp);
        }

        return dp[i][j] = 0;
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, s, p, dp);
    }
};