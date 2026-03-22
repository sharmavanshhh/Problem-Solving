class Solution {
public:
    void rotate90(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // transpose
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        // reverse each row
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    
    bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        for(int i = 0; i < 4; i++) {
            if(isEqual(mat, target)) return true;
            rotate90(mat);
        }
        
        return false;
    }
};