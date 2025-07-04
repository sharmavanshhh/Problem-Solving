class Solution {
public:
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

    void backtrack(string s, vector<vector<string>>& ans, vector<string>&temp, int start){
        if(start == s.length()){
            ans.push_back(temp);
            return;
        }

        for(int end = start; end < s.length(); end++){
            if(isPalindrome(s, start, end)){
                temp.push_back(s.substr(start, end-start+1));
                backtrack(s, ans, temp, end+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        backtrack(s, ans, temp, 0);
        return ans;
    }
};