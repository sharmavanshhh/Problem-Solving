class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        backtracking(candidates, target, ans, temp, 0, 0);

        return ans;
    }

    void backtracking(vector<int>& candidates, int target,
                      vector<vector<int>>& ans, vector<int> temp, int sum,
                      int index) {
        
        if(sum == target){
            ans.push_back(temp);
            return;
        }

        if(sum > target) return;

        for(int i = index; i < candidates.size(); i++){
            temp.push_back(candidates[i]);
            backtracking(candidates, target, ans, temp, sum + candidates[i], i);
            temp.pop_back();
        }
    }
};