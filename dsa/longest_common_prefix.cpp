class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string prefix;
        for (int i = 0; i < (strs[0]).length(); i++) { // go through 
            for (int j = 1; j < strs.size(); j++) {
                char match = strs[0][i];
                if (strs[j][i] != match) {
                    return prefix;
                }
            }
            prefix.push_back(strs[0][i]);
        }
        return prefix;
    }
};


/*
 * REVIEW NOTES — longestCommonPrefix (vertical scanning, O(S) total chars)
 *
 * CORRECTNESS: passes all edge cases — empty first string, single-element
 * array, and the "shorter string isn't first" case (["abcd","ab"] -> "ab").
 *   - Survives the boundary because indexing a std::string at exactly size()
 *     is defined and returns '\0'. The '\0' mismatch triggers an early return
 *     before i ever goes PAST size(), so no out-of-bounds access. Safe by luck
 *     of the bail-out, but safe.
 *
 * NITS (no correctness impact):
 *   1. -Wsign-compare: i is int, but .length()/.size() return unsigned size_t.
 *      Fine for normal inputs; idiomatic fix is size_t loop counters
 *      (or cast: int(strs[0].length())).
 *   2. `char match = strs[0][i];` is recomputed every inner iteration but only
 *      depends on i. Hoist it just above the inner loop for cleaner code.
 */