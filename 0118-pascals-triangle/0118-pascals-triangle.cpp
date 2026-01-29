class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        /*DP Soln*/
        // vector<vector<int>> pascal;
        // pascal.push_back({1});
        // if(numRows == 1) return pascal;
        // pascal.push_back({1,1});
        // if(numRows == 2) return pascal;

        // for(int i=2; i<numRows; i++){
        //     vector<int> row(i+1, 1);
        //     for(int j=1; j<i; j++){
        //         row[j] = pascal[i-1][j-1] + pascal[i-1][j];
        //     }
        //     pascal.push_back(row);
        // }
        // return pascal;

        /*Mathematical Approach*/
        vector<vector<int>> pascal;
        for (int i = 0; i < numRows; i++) {
            vector<int> rows;
            long long ele = 1;
            for (int j = 0; j <= i; j++) {
                rows.push_back(ele);
                ele = ele * (i - j) / (j + 1);
            }
            pascal.push_back(rows);
        }
        return pascal;
    }
};