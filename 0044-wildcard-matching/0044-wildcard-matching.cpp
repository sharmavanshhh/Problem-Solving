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
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        
        dp[m][n] = true;

        for(int j = n - 1; j >= 0; j--){
            if(p[j] == '*'){
                dp[m][j] = dp[m][j+1];
            }
            else{
                break;
            }
        }

        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(s[i] == p[j] || p[j] == '?'){
                    dp[i][j] = dp[i+1][j+1];
                }
                else if(p[j] == '*'){
                    dp[i][j] = dp[i][j+1] || dp[i+1][j];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }

        return dp[0][0];
    }
};