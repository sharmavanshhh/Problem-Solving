class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;

        backtrack(ans, temp, n, k, 1);

        return ans;
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& temp, int n, int k, int index){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }

        for(int i = index; i <= n; i++){
            temp.push_back(i);
            backtrack(ans, temp, n, k, i + 1);
            temp.pop_back();
        }
    }
};