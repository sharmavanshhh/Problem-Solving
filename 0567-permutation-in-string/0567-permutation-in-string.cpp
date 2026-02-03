class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();

        if(k > s2.size()) return false;

        vector<int> f1(26, 0), f2(26, 0);

        for(int i = 0; i < k; i++){
            f1[s1[i] - 'a']++;
            f2[s2[i] - 'a']++;
        }

        if(f1 == f2) return true;

        for(int right = k; right < s2.size(); right++){
            f2[s2[right] - 'a']++;
            f2[s2[right - k] - 'a']--;

            if(f1 == f2) return true;
        }

        return false;
    }
};