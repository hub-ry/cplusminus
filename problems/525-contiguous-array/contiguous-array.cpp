class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        std::unordered_map<int, int> m;
        m[0] = -1;
        int n = static_cast<int>(nums.size());
        int run_sum = 0;
        int longest = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
               run_sum += 1; 
            }
            else {
                run_sum -= 1;
            }

            if (!m.contains(run_sum)) {
               m[run_sum] = i; 
            }
            else {
                if (longest < i - (m[run_sum])) {
                    longest = i - (m[run_sum]);

                }
            }
        }
        return longest;
    }
};