class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256, 0);

        for(char c : t) hash[c]++;

        int left = 0, right = 0;
        int count = 0;
        int minLen = INT_MAX;
        int start = -1;

        while(right < s.size()){
            if(hash[s[right]] > 0){
                count++;
            }
            hash[s[right]]--;
            right++;

            while(count == t.size()){
                if(right - left < minLen){
                    minLen = right - left;
                    start = left;
                }

                hash[s[left]]++;

                if(hash[s[left]] > 0){
                    count--;
                }

                left++;
            }
        }

        if(start == -1) return "";
        return s.substr(start, minLen);
    }
};