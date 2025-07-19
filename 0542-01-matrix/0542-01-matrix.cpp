class Solution {
public:
     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] = INT_MAX;  // ✅ Set all 1s to a large value
                }
            }
        }

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < r && ny < c && mat[nx][ny] > mat[x][y] + 1) {
                    mat[nx][ny] = mat[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return mat;
    }
};