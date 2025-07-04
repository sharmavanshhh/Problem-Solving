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
                if(i > start && arr[i] == arr[i-1]) continue;
                temp.push_back(arr[i]);
                backtracking(arr, res, target, temp, sum + arr[i], i+1);
                temp.pop_back();
            }
        }

        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int>> result;
            vector<int> temp;
            sort(candidates.begin(), candidates.end());
            backtracking(candidates, result, target, temp, 0, 0);
            return result;  
        }
    };