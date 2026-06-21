class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int seen[128];
        fill(seen, seen + 128, -1); 
        int left = 0; // is like the current flag basically
        int longest_string = 0;
        for (int i = 0; i < s.length(); i++) {
            if (seen[s[i]] >= left) {
                left = seen[s[i]] + 1;
            }
            
            longest_string = max(longest_string, i - left + 1);
            seen[s[i]] = i; // logs the index where each char is
        }
        return longest_string;
    }
};