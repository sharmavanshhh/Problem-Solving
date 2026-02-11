class Solution {
public:
    int longestSubstring(string s, int k) {
        return ans(s, 0, s.size()-1, k);
    }

    int ans(string s, int l, int r, int k){
        if(r - l + 1 < k){
            return 0;
        }

        vector<int> hash(26, 0);
        for(int i = l; i <= r; i++){
            hash[s[i] - 'a']++;
        }

        for(int i = l; i <= r; i++){
            if(hash[s[i] - 'a'] < k){
                int left = ans(s, l, i-1, k);
                int right = ans(s, i+1, r, k);

                return max(left, right);
            }
        }

        return r - l + 1;
    }
};