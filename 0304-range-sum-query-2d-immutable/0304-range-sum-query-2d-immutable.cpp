class NumMatrix {
public:
    vector<vector<int>> P;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        P = vector<vector<int>>(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                P[i][j] = matrix[i][j];

                if(i > 0) P[i][j] += P[i-1][j];
                if(j > 0) P[i][j] += P[i][j-1];
                if(i > 0 && j > 0) P[i][j] -= P[i-1][j-1];
            }
        }
    }

    int sumRegion(int r1, int c1, int r2, int c2) {
        int sum = P[r2][c2];

        if(r1 > 0) sum -= P[r1-1][c2];
        if(c1 > 0) sum -= P[r2][c1-1];
        if(r1 > 0 && c1 > 0) sum += P[r1-1][c1-1];

        return sum;
    }
};