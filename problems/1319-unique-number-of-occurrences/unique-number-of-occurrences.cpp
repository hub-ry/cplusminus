class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int, int> count;
        for (int x : arr) {
            count[x]++;
        }
        
        std::unordered_set<int> tracker;
        for (auto [key, value] : count) {
            if (!(tracker.insert(value).second)) {
                return false;
            }
        }
        return true;
    }
};