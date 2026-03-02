class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);

        // Brute-Force [O(nlog(n))]
        // for(int i=1; i<=n; i++){
        //     int num = i;
        //     int count = 0;
        //     while(num){
        //         count += num % 2;
        //         num /= 2;
        //     }
        //     ans[i] = count;
        // }
        // return ans;

        // Optimal Solution [O(n)]
        for(int i = 1; i <= n; i++){
            if(!(i & 1)){
                ans[i] = ans[i/2];
            }
            else{
                ans[i] = ans[i/2] + 1;
            }
        }

        return ans;
    }
};