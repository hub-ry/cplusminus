class Solution {
public:
    string reverseWords(string s) {
        std::vector<std::string> words;
        std::string current;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (!(current.empty())) {
                    words.push_back(current);
                    current.clear();
                }
            }
            else {
                current += s[i];
            }
        }

        if (!current.empty()) words.push_back(current);
        
        std::string output;
        for (int i = words.size() - 1; i >= 0; i--) {
            output += words[i];
            if (i != 0) {
                output += " ";
            }
        }

        return output;




    }

};