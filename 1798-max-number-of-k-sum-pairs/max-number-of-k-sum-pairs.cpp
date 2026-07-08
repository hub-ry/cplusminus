class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> seen;   // value -> count of unmatched copies
        int result = 0;
        for (int num : nums) {
            int check = k - num;
            if (seen[check] > 0) {
                seen[check]--;
                result++;
            } else {
                seen[num]++;
            }
        }
        return result;
    }
};