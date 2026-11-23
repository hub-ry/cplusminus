class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t match_index = 0;
        for (size_t i = 0; i < t.length() && match_index < s.length(); i++) {
            if (s[match_index] == t[i]) {
                match_index++;
            }
        }
        return match_index == s.length();
    }
};