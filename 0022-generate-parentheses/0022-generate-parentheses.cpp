class Solution {
public:

    void backtrack(int n, string current, vector<string>&ans, int open, int close){
        if(open == n && close == n){
            ans.push_back(current);
            return;
        }

        if(open < n){
            backtrack(n, current+"(", ans, open+1, close);
        }
        if(open > close){
            backtrack(n, current+")", ans, open, close+1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;

        backtrack(n, "", result, 0, 0);

        return result;
    }
};