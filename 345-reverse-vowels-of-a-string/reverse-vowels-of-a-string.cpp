class Solution {
public:
    string reverseVowels(string s) {
        auto isVowel = [](char c){c = std::tolower(c); return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';};

        int end = s.length() - 1;
        int start = 0;
        
        while (start < end) {
            if (!(isVowel(s[start]))) {start++; continue;}
            if (!(isVowel(s[end]))) {end--; continue;}
            //swap start and end indicies
            std::swap(s[start], s[end]);
            start++;
            end--;
        }
        return s;
    }
};