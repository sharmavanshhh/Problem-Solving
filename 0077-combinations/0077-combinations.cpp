class Solution {
public:
    void backtracking(int n, int k, vector<int>& temp, vector<vector<int>>& res, int index){
        if(temp.size() == k){
            res.push_back(temp);
            return;
        }
        for(int i=index; i<=n; i++){
            temp.push_back(i);
            backtracking(n, k, temp, res, i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        backtracking(n, k, temp, result, 1);
        return result;
    }
};