class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        // int sum = (n * (n+1))/2;
        // int temp = 0;
        // for(int i=0; i<n; i++){
        //     temp += nums[i];
        // }
        // return sum - temp;

        int i = 0;
        while(i < n){
            int index = arr[i];
            if(arr[i] < n && arr[i] != arr[index]){
                swap(arr[i], arr[index]);
            }
            else{
                i++;
            }
        }

        for(int i=0; i<n; i++){
            if(arr[i] != i){
                return i;
            }
        }
        return n;
    }
};