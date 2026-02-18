class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        backtracking(digits, ans, "", 0);
        return ans;
    }

    void backtracking(string digits, vector<string>& ans, string curr, int index){
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        if(index == digits.size()){
            ans.push_back(curr);
            return;
        }

        string letters = map[digits[index] - '0'];
        for(char ch : letters){
            backtracking(digits, ans, curr + ch, index + 1);
        }
    }
};