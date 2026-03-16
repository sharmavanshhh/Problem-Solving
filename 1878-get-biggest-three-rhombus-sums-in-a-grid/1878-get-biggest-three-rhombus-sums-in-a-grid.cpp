class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<int> st;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                st.insert(grid[i][j]);

                for(int k = 1; ; k++){
                    if(i + 2*k >= m || j - k < 0 || j + k >= n) break;

                    int sum = 0;

                    int r = i, c = j;

                    for(int t = 0; t < k; t++) sum += grid[r+t][c+t];
                    r = i + k, c = j + k;

                    for(int t = 0; t < k; t++) sum += grid[r+t][c-t];
                    r = i + 2*k, c = j;

                    for(int t = 0; t < k; t++) sum += grid[r-t][c-t];
                    r = i + k, c = j - k;

                    for(int t = 0; t < k; t++) sum += grid[r-t][c+t];

                    st.insert(sum);
                }
            }
        }

        vector<int> res;

        for(auto it = st.rbegin(); it != st.rend() && res.size() < 3; it++){
            res.push_back(*it);
        }

        return res;
    }
};