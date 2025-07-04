class Solution {
public:

    bool isPalindrome(string s, int low, int high){
        while(low < high){
            if(s[low] != s[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }

    void backtracking(string& s, vector<string>& temp, vector<vector<string>>& result, int start){
        if(start == s.length()){
            result.push_back(temp);
            return;
        }

        for(int i=start; i<s.length(); i++){
            if(isPalindrome(s, start, i)){
                temp.push_back(s.substr(start, i-start+1));
                backtracking(s, temp, result, i+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;

        backtracking(s, temp, result, 0);

        return result;
    }   
};