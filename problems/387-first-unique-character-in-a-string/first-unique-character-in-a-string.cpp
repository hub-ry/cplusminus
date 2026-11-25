class Solution {
public:
    int firstUniqChar(string s) {
        std::unordered_map<char, int> seen;
        int n = static_cast<int>(s.length());
        for (int i = 0; i < n; ++i) {
            if (seen.contains(s[i])) {
                seen[s[i]] = -1;
            }
            else {
                seen[s[i]] = i;
            }
        }
        for (const auto& [key, val] : seen) {
            if (val != -1) {
                if (val < n) {
                    n = val;
                }
            }
        }
        if (n == static_cast<int>(s.size())) {
            n = -1;
        }
        return n;
    }
};