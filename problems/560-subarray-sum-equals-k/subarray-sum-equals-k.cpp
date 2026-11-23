class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> prefix;
        int sum = 0;
        int ret = 0;
        prefix[0] = 1;
        for (size_t i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int find = sum - k;
            if (prefix.count(find)) {
                ret += prefix[find];
            }
            prefix[sum]++;
        }
        return ret;
    }
};