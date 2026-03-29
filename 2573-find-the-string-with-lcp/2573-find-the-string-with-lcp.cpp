class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, '#');

        char curr = 'a';

        // Step 1: build string
        for(int i = 0; i < n; i++){
            if(s[i] == '#'){
                s[i] = curr;
                if(curr < 'z') curr++;
            }

            for(int j = i + 1; j < n; j++){
                if(lcp[i][j] > 0){
                    s[j] = s[i];
                }
            }
        }

        // Step 2: validate
        for(int i = n - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(s[i] == s[j]){
                    int expected = 1;
                    if(i + 1 < n && j + 1 < n){
                        expected += lcp[i + 1][j + 1];
                    }
                    if(lcp[i][j] != expected) return "";
                } else {
                    if(lcp[i][j] != 0) return "";
                }
            }
        }

        return s;
    }
};