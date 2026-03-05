class Solution {
public:
    int minOperations(string s) {
        int ones = 0;
        int zeros = 0;

        for(int i = 0; i < s.size(); i += 2){
            if(s[i] == '0') zeros++;
        }

        for(int i = 1; i < s.size(); i += 2){
            if(s[i] == '1') ones++;
        }

        cout << zeros << " " << ones << endl;

        int c1 = s.size() - abs(ones + zeros);

        zeros = 0;
        ones = 0;

        for(int i = 0; i < s.size(); i += 2){
            if(s[i] == '1') ones++;
        }

        for(int i = 1; i < s.size(); i += 2){
            if(s[i] == '0') zeros++;
        }

        cout << zeros << " " << ones;

        int c2 = s.size() - abs(ones + zeros);


        return min(c1, c2);
    }
};