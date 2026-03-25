class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        long long total = 0;
        
        // total sum
        for(auto &row : grid){
            for(auto &val : row){
                total += val;
            }
        }
        
        // if odd → impossible
        if(total % 2) return false;
        
        long long target = total / 2;
        
        // try horizontal cuts
        long long curr = 0;
        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n; j++){
                curr += grid[i][j];
            }
            if(curr == target) return true;
        }
        
        // try vertical cuts
        vector<long long> colSum(n, 0);
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                colSum[j] += grid[i][j];
            }
        }
        
        curr = 0;
        for(int j = 0; j < n - 1; j++){
            curr += colSum[j];
            if(curr == target) return true;
        }
        
        return false;
    }
};