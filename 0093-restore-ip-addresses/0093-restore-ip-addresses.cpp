class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        backtrack(s, ans, "", 0, 0);
        return ans;
    }

    void backtrack(string s, vector<string>& ans, string curr, int index, int parts){
        if(parts == 4 && index == s.size()){
            ans.push_back(curr.substr(0, curr.size() - 1));
            return;
        }

        if(parts == 4 || index == s.size()){
            return;
        }

        for(int i = 1; i <= 3 && index + i <= s.size(); i++){
            string segment = s.substr(index, i);

            if((segment[0] == '0' && i > 1) || stoi(segment) > 255){
                continue;
            }
            backtrack(s, ans, curr + segment + ".", index + i, parts + 1);
        }
    }
};