class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;
        dp.push_back({1});
        if(numRows == 1) return dp; 
        dp.push_back({1,1}); 
        if(numRows == 2) return dp;

        for(int i=2; i<numRows; i++){
            vector<int> temp(i+1, 1);
            for(int j=1; j<i; j++){
                temp[j] = dp[i-1][j-1] + dp[i-1][j];
            }
            dp.push_back(temp); 
        }
        return dp;
    }
};