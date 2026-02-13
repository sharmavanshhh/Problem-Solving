class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(
            envelopes.begin(), envelopes.end(),
            [](vector<int> &a, vector<int> &b){
                if(a[0] == b[0]){
                    return a[1] > b[1];
                }
                return a[0] < b[0];
            }
        );

        vector<int> lis;
       
       for(auto &env : envelopes){
        int h = env[1];

        int left = 0;
        int right = lis.size() - 1;
        int pos = lis.size();  
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(lis[mid] >= h){
                pos = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        if(pos == lis.size())
            lis.push_back(h);
        else
            lis[pos] = h;
        }

        return lis.size();
    }
};