class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen = {};
        const int n = static_cast<int>(nums.size());

        for (int i = 0; i < n; ++i) {
            int v = target - nums[i];
            if (seen.count(v)) {
                return {seen[v], i};
            }
            seen[nums[i]] = i;  
        }
        return {};
    }
};