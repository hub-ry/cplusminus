class Solution {
public:
    int maxVowels(string s, int k) {
        int max_vowel = 0;
        int curr_vowel = 0;
        int front = 0;

        auto isVowel = [](char c) {
            return std::string("AEIOUaeiou").find(c) != std::string::npos;
        };

        for (int i = 0; i < s.length(); i++) {
            if (i < k) {
                if (isVowel(s[i])) {
                    max_vowel++;
                    curr_vowel++;
                }
            }
            else {
                if (isVowel(s[front])) {
                    curr_vowel--;
                }
                if (isVowel(s[i])) {
                    curr_vowel++;
                }
                if (curr_vowel > max_vowel) {
                    max_vowel = curr_vowel;
                }
                front++;
            }
        }
        return max_vowel;
    }
};