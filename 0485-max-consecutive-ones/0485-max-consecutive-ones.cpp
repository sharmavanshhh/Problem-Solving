class Solution {
public:

    int maximum(int x, int y){
        if(x > y){
            return x;
        }
        return y;
    }

    int findMaxConsecutiveOnes(vector<int>& arr) {
        int count = 0;
        int max = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == 1){
                count++;
                max = maximum(count, max);
            }
            else if(arr[i] == 0){
                count = 0;
            }
        }
        return max;
    }
};