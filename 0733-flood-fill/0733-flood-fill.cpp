class Solution {
public:
    void DFS(vector<vector<int>>& image, int sr, int sc, int r, int c,
             int oldColor, int newColor) {
        if (sr == r || sc == c || sr < 0 || sc < 0 ||
            image[sr][sc] != oldColor) {
            return;
        }

        image[sr][sc] = newColor;
        DFS(image, sr + 1, sc, r, c, oldColor, newColor);
        DFS(image, sr - 1, sc, r, c, oldColor, newColor);
        DFS(image, sr, sc + 1, r, c, oldColor, newColor);
        DFS(image, sr, sc - 1, r, c, oldColor, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int r = image.size();
        int c = image[0].size();

        int oldColor = image[sr][sc];

        if (oldColor == newColor) return image;

        DFS(image, sr, sc, r, c, oldColor, newColor);

        return image;
    }
};