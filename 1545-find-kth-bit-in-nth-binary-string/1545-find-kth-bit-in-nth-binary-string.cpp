// class Solution {
// public:
//     void findString(int i, int n, string curr, string& ans){
//         if(i == n){
//             ans = curr;
//             return;
//         }
//         string inverted = "";
//         for(char c : curr){
//             inverted += (c == '0' ? '1' : '0');
//         }
//         reverse(inverted.begin(), inverted.end());
//         return findString(i + 1, n, curr + "1" + inverted, ans); 
//     }

//     char findKthBit(int n, int k) {
//         string ans = "";
//         findString(1, n, "0", ans);
//         cout << ans;
//         return ans[k-1];
//     }
// };

class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case
        if(n == 1) return '0';

        int length = (1 << n) - 1;      // 2^n - 1
        int mid = (length / 2) + 1;     // 2^(n-1)

        if(k == mid) return '1';

        if(k < mid)
            return findKthBit(n - 1, k);

        // k > mid (mirror case)
        char res = findKthBit(n - 1, length - k + 1);
        return (res == '0') ? '1' : '0';  // invert
    }
};