class Solution {
public:
    int maxArea(vector<int>& height) {
        int r = size(height) - 1;
        int l = 0;
        int max_area = -1;
        while (r != l) {
            int y = min(height[r], height[l]);
            int x = r - l;

            if (max_area < x * y) {
                max_area = x*y;
            }

            if (height[r] > height[l]) {
                l++;
            }
            else {
                r--;
            }
        }
        return max_area;
    }
};