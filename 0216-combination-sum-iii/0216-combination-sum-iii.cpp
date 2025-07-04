    class Solution {
    public:

        void backtracking(int k, vector<vector<int>>& res, int target, vector<int>& temp, int sum, int start){
            if(temp.size() == k && sum == target){
                res.push_back(temp);
                return;
            }
            if(sum > target){
                return;
            }

            for(int i=start; i<=9; i++){
                temp.push_back(i);
                backtracking(k, res, target, temp, sum + i, i+1);
                temp.pop_back();
            }
        }

        vector<vector<int>> combinationSum3(int k, int target) {
            vector<vector<int>> result;
            vector<int> temp;
            backtracking(k, result, target, temp, 0, 1);
            return result;  
        }
    };