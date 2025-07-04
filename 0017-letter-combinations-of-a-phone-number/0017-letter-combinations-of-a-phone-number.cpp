class Solution {
public:

    void backtrack(string digits, int index, string current, vector<string>& ans){
        vector<string> map = { "", "", "abc", "def", "ghi",
                                "jkl", "mno", "pqrs", "tuv", "wxyz"};

        if(index == digits.size()){
            ans.push_back(current);
            return;
        }

        string letters = map[digits[index] - '0'];

        for(char ch : letters){
            backtrack(digits, index+1, current+ch, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;

        if(digits == ""){
            return result;
        }

        backtrack(digits, 0, "", result);

        return result;
    }
};