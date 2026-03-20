class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                vector<int> temp;

                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        temp.push_back(grid[x][y]);
                    }
                }

                if (temp.size() < 2) {
                    ans[i][j] = 0;
                    continue;
                }

                int mini = INT_MAX;

                for (int a = 0; a < temp.size(); a++) {
                    for (int b = a + 1; b < temp.size(); b++) {
                        if (temp[a] != temp[b]) {
                            mini = min(mini, abs(temp[a] - temp[b]));
                        }
                    }
                }

                ans[i][j] = (mini == INT_MAX ? 0 : mini);
            }
        }

        return ans;
    }
};