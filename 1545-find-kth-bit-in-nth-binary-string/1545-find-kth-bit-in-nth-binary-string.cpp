class Solution {
public:
    void findString(int i, int n, string curr, string& ans){
        if(i == n){
            ans = curr;
            return;
        }
        string inverted = "";
        for(char c : curr){
            inverted += (c == '0' ? '1' : '0');
        }
        reverse(inverted.begin(), inverted.end());
        return findString(i + 1, n, curr + "1" + inverted, ans); 
    }

    char findKthBit(int n, int k) {
        string ans = "";
        findString(1, n, "0", ans);
        cout << ans;
        return ans[k-1];
    }
};