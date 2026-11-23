class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        /* do the equivalent of s.string */
        std::istringstream input(s);
        std::vector<std::string> words;
        std::string word;

        while (input >> word) {
            words.push_back(word);
        }

        if (words.size() != pattern.length()) {
            return false;
        }

        std::unordered_map<char, std::string> m;
        std::unordered_map<std::string, char> m1;
        
        int n = static_cast<int>(pattern.size());

        for (int i = 0; i < n; ++i) {
            char c = pattern[i];
            std::string &w = words[i];

            if (!m.contains(c)) {
                if (m1.contains(w)) {
                    return false;
                }
                m[c] = w;
                m1[w] = c;
            }
            else {
                if (m[c] != w) {
                    return false;
                }
            }
        }
        return true;
    }
};