class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= intervals[i-1][1]){
                ans.push_back({intervals[i-1][0], intervals[i][1]});
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};