class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int best_area = (right - left) * min(height[left], height[right]);
        while (left != right) {
            if (height[left] > height[right]) {
                right--;
            }
            else {
                left++;
            }
            int test_area = (right - left) * min(height[left], height[right]);
            if (test_area > best_area) best_area = test_area;
        }
        return best_area;
    }
};