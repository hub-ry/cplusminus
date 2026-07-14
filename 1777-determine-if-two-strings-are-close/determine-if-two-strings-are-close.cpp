class Solution {
public:
    bool closeStrings(string word1, string word2) { 
        std::unordered_map<char, int> count1;
        std::unordered_map<char, int> count2;

        if (word1.length() != word2.length()) return false;

        for (int i = 0; i < word1.length(); i++) {
            char a = word1[i];
            char b = word2[i];

            count1[a]++;
            count2[b]++;


        }

        // make sure every key in the one matches a key in the otherrrrr
        std::vector<int> counts1;
        std::vector<int> counts2;
        for (auto [key, value] : count1) {
            if (!(count2.contains(key))) {
                return false;
            }
            counts1.push_back(value);
            counts2.push_back(count2[key]);
         
        }
        sort(counts1.begin(), counts1.end());
        sort(counts2.begin(), counts2.end());

        return counts1 == counts2;
    }
};