class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        backtrack(s, ans, temp, 0);
        return ans;
    }

    bool isPalindrome(string s, int low, int high){
        while(low < high){
            if(s[low] != s[high]) return false;
            low++;
            high--;
        }
        return true;
    }

    void backtrack(string s, vector<vector<string>>& ans, vector<string>& temp, int index){
        if(index == s.size()){
            ans.push_back(temp);
        }

        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s, index, i)){
                temp.push_back(s.substr(index, i - index + 1));
                backtrack(s, ans, temp, i + 1);
                temp.pop_back();
            }
        }
    }
};