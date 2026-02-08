class Solution {
public:
    int trap(vector<int>& height) {
        // int n = height.size();
        // if (n == 0) return 0;

        // int* left = new int[n];
        // int* right = new int[n];

        // left[0] = height[0];
        // for (int i = 1; i < n; i++) {
        //     left[i] = max(left[i - 1], height[i]);
        // }

        // right[n - 1] = height[n - 1];
        // for (int i = n - 2; i >= 0; i--) {
        //     right[i] = max(right[i + 1], height[i]);
        // }

        // int water = 0;
        // for (int i = 0; i < n; i++) {
        //     water += min(left[i], right[i]) - height[i];
        // }

        // delete[] left;
        // delete[] right;

        // return water;

        int n = height.size();
        if (n == 0)
            return 0;

        int leftMax = 0, left = 0;
        int rightMax = 0, right = n - 1;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }
        return water;
    }
};
