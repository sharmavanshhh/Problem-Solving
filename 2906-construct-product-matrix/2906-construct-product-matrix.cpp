class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int size = m * n;
        int mod = 12345;

        vector<int> arr(size);
        
        // flatten
        int k = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                arr[k++] = grid[i][j] % mod;
            }
        }

        vector<int> prefix(size, 1), suffix(size, 1);

        // prefix
        for(int i = 1; i < size; i++){
            prefix[i] = (prefix[i-1] * arr[i-1]) % mod;
        }

        // suffix
        for(int i = size - 2; i >= 0; i--){
            suffix[i] = (suffix[i+1] * arr[i+1]) % mod;
        }

        // result build
        vector<vector<int>> ans(m, vector<int>(n));
        k = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[i][j] = (prefix[k] * suffix[k]) % mod;
                k++;
            }
        }

        return ans;
    }
};