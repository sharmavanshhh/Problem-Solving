class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(), envelopes.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });

        vector<int> temp;

        for(auto &env : envelopes){
            int h = env[1];

            auto it = lower_bound(temp.begin(), temp.end(), h);

            if(it == temp.end())
                temp.push_back(h);
            else
                *it = h;
        }

        return temp.size();
    }
};