class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();

        int im = 0;
        int in = 0;
        int ir = 0;
                
        vector<int> result(m+n);

        while(im < m && in < n){
            if(nums1[im] <= nums2[in]){
                result[ir] = nums1[im];
                            im++;
            }
            else{
                result[ir] = nums2[in];
                            in++;
            }


            ir++;
        }

        while(im < m){
            result[ir] = nums1[im];
            im++;
            ir++;
        }

        while(in < n){
            result[ir] = nums2[in];
            in++;
            ir++;
        }

        int r = result.size();
        double median;
        if(r % 2 == 0){
            median = (result[r/2] + result[(r/2) -1])/2.0;
        }
        else{
            median = result[r/2];
        }

        return median;

    }
};