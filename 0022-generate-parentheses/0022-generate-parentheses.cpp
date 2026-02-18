    class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> ans;
            backtrack(n, ans, 0, 0, "");
            return ans;
        }
        
        void backtrack(int n, vector<string>& ans, int open, int close, string curr){
            if(open == n && close == n){
                ans.push_back(curr);
                return;
            }

            if(open < n) backtrack(n, ans, open + 1, close , curr + '(');
            if(open > close) backtrack(n, ans, open, close + 1, curr + ')');
        }
    };