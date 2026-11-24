class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        std::unordered_map<int, int> sums1 = {};
        std::unordered_map<int, int> sums2 = {};

        int n = static_cast<int>(nums1.size());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int s1 = nums1[i] + nums2[j];
                int s2 = nums3[i] + nums4[j];
                sums1[s1] += 1;
                sums2[s2] += 1;
            }
        }
        int result = 0;
        for (const auto& [key, value] : sums1) {
            if (sums2.contains(0 - key)) {
               result += value * sums2[-key];
            }
        }
        return result;
    }
};