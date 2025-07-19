class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;

        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    grid[nx][ny] == 0 && dist[nx][ny] > dist[x][y] + 1) {

                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return dist[n - 1][n - 1] == INT_MAX ? -1 : dist[n - 1][n - 1];
    }
};