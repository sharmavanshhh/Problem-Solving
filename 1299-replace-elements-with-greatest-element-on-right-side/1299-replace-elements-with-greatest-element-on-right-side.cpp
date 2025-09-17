class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int rmax = -1;

        for(int i=arr.size()-1; i>=0; i--){
            int current = arr[i];
            arr[i] = rmax;
            rmax = max(rmax, current);
        }
        return arr;
    }
};