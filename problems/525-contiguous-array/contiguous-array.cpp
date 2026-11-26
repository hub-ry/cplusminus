class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        std::unordered_map<int, int> count = {};
        count[0] = -1;

        int n = static_cast<int>(nums.size());

        int total = 0;
        int longest = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                total += 1;
            }
            else {
                total -= 1;
            } 

            if (count.contains(total)) {
                longest = max(longest, i - count[total]);
            }
            else {
                count[total] = i;
            }
        }
        return longest;
    }
};