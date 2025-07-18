class Solution {
public:
    void DFS(vector<vector<int>>& grid, int i, int j, int r, int c, int& area){
        if(i==r || j==c || i<0 || j<0 || grid[i][j]==0){
            return;
        }
        grid[i][j] = 0;
        area++;
        DFS(grid, i, j+1, r, c, area);
        DFS(grid, i-1, j, r, c, area);
        DFS(grid, i, j-1, r, c, area);
        DFS(grid, i+1, j, r, c, area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
                int r = grid.size();
        int c = grid[0].size();
        int ans = 0;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    DFS(grid, i, j, r, c, area);
                    ans = max(area, ans);
                }
            }
        }
        return ans;
    }
};