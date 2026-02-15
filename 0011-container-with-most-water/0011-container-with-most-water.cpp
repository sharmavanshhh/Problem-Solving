class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int left = 0;
        int right = n - 1;

        int area = 0;

        while(left < right){
            int w = right - left;
            int h = min(height[left], height[right]);

            area = max(area, w * h);

            height[left] < height[right] ? left++ : right--;
        }

        return area;
    }
};