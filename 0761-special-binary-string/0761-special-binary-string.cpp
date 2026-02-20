class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> blocks;
        int count = 0;
        int start = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1') count++;
            else count--;

            if(count == 0){
                string inner = s.substr(start + 1, i - start - 1);
                string solvedInner = makeLargestSpecial(inner);
                blocks.push_back("1" + solvedInner + "0");

                start = i + 1;
            }
        }

        sort(blocks.begin(), blocks.end(), greater<string>());

        string result = "";
        for(string &b : blocks){
            result += b;
        }

        return result;
    }
};