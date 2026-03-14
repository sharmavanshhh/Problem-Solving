class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> happy;
        generate(happy, "", 0, n);

        sort(happy.begin(), happy.end());

        if(k > happy.size()) return "";

        return happy[k-1];
    }

    void generate(vector<string>& happy, string curr, int index, int n){
        if(index == n){
            happy.push_back(curr);
            return;
        }

        for(char ch : {'a', 'b', 'c'}){
            if(curr.empty() || curr.back() != ch){
                generate(happy, curr + ch, index + 1, n);
            }
        }
    }

};