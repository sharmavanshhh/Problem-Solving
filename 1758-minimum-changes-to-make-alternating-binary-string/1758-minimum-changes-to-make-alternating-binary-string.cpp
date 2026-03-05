class Solution {
public:
    int minOperations(string s) {
        // int ones = 0;
        // int zeros = 0;
        // for(int i = 0; i < s.size(); i += 2){
        //     if(s[i] == '0') zeros++;
        // }
        // for(int i = 1; i < s.size(); i += 2){
        //     if(s[i] == '1') ones++;
        // }
        // int c1 = s.size() - ones + zeros;
        // zeros = 0;
        // ones = 0;
        // for(int i = 0; i < s.size(); i += 2){
        //     if(s[i] == '1') ones++;
        // }
        // for(int i = 1; i < s.size(); i += 2){
        //     if(s[i] == '0') zeros++;
        // }
        // cout << zeros << " " << ones;
        // int c2 = s.size() - ones + zeros;
        // return min(c1, c2);

        

        int pattern1 = 0; // start with 0 -> 010101
        int pattern2 = 0; // start with 1 -> 101010
        for(int i = 0; i < s.size(); i++){
            if(s[i] != (i % 2 ? '1' : '0')) pattern1++;
            if(s[i] != (i % 2 ? '0' : '1')) pattern2++;
        }
        return min(pattern1, pattern2);
    }
};