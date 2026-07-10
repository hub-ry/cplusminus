class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> one(nums1.begin(), nums1.end());
        unordered_set<int> two(nums2.begin(), nums2.end());

        vector<int> first;
        vector<int> second;

        for (int x : one) {
            if (!two.count(x)) {
                first.push_back(x);
            }
        }

        for (int x : two) {
            if (!one.count(x)) {
                second.push_back(x);
            }
        }

        return {first, second};
    }
};