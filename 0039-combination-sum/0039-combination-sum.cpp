    class Solution {
    public:

        void backtracking(vector<int>& arr, vector<vector<int>>& res, int target, vector<int>& temp, int sum, int start){
            if(sum == target){
                res.push_back(temp);
                return;
            }
            if(sum > target){
                return;
            }

            for(int i=start; i<arr.size(); i++){
                temp.push_back(arr[i]);
                backtracking(arr, res, target, temp, sum + arr[i], i);
                temp.pop_back();
            }
        }

        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> result;
            vector<int> temp;
            backtracking(candidates, result, target, temp, 0, 0);
            return result;  
        }
    };