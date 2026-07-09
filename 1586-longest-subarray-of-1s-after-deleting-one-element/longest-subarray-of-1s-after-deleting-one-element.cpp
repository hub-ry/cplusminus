class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeros = 0;
        int left = 0;
        int best = 0;
        for (size_t right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                zeros++;
            }
            while (zeros > 1) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;

            }
            if (best < (right - left)) {
                best = (right - left);
            }
        }
        return best;
    }
};