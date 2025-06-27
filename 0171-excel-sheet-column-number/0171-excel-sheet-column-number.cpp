class Solution {
public:
    int titleToNumber(string columnTitle) {
        int len = columnTitle.length();
        int ans = 0;
        for(int i=0; i<len; i++){
            int a = columnTitle[i] - 'A' + 1;
            ans = ans * 26 + a;
        }
        return ans;
    }
};