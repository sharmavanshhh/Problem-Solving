class Solution {
public:
    bool isValid(int i, int j, int m, int n, int& count){
        if(i >= 0 && j < n && i < m && j >= 0){
            count++;
            return true;
        }
        return false;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int sum = img[i][j], count = 1;

                //00 01 10 11 -10 -1-1 0-1 -11 1-1
                sum += isValid(i-1, j-1, m, n, count) ? img[i-1][j-1] : 0;
                                // cout << sum << " " << count << endl;
                isValid(i-1, j, m, n, count) ? sum += img[i-1][j] : sum += 0;
                                // cout << sum << " " << count << endl;
                isValid(i, j-1, m, n, count) ? sum += img[i][j-1] : sum += 0;
                //  cout << sum << " " << count << endl;
                sum += isValid(i+1, j, m, n, count) ? img[i+1][j] : 0;
                // cout << sum << " " << count << endl;
                isValid(i, j+1, m, n, count) ? sum += img[i][j+1] : sum += 0;
                //  cout << sum << " " << count << endl;
                isValid(i+1, j+1, m, n, count) ? sum += img[i+1][j+1] : sum += 0;
                //  cout << sum << " " << count << endl;
                isValid(i-1, j+1, m, n, count) ? sum += img[i-1][j+1] : sum += 0;
                //  cout << sum << " " << count << endl;
                isValid(i+1, j-1, m, n, count) ? sum += img[i+1][j-1] : sum += 0;
                // cout << sum << " " << count << endl;
                // cout << count << " " << endl; 

                ans[i][j] = floor(sum / count);
            }
        }
        return ans;
    }
};