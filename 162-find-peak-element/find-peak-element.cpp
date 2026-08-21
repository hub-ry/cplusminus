class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int s = nums.size();


        int l = 0;
        int h = s - 1;

        while (l < h) {
            int m = l + (h - l) / 2;
            if (nums[m] < nums[m + 1]) l = m + 1;
            else {
                h = m;
            }
        }
        return l;
    }
};