class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        std::string blank;
        std::string longest = (str1.length() >= str2.length()) ? str1 : str2;
        std::string shortest = (str1.length() < str2.length()) ? str1 : str2;

        if (!(longest.length() % shortest.length())) {
            int n = longest.length() / shortest.length();
            std::string result;
            for (int i = 0; i < n; i++) result += shortest;
            return result == longest ? shortest : blank;
        }
        else {
            int len = gcd(str1.length(), str2.length());
            std::string result1 = shortest.substr(0, len);
            if (longest.length() % len == 0 && shortest.length() % len == 0) {
                int first = longest.length() / len;
                std::string match1;
                for (int i = 0; i < first; i++) match1 += result1;
                if (match1 != longest) return blank;
                int second = shortest.length() / len;
                std::string match2;
                for (int i = 0; i < second; i++) match2 += result1;
                if (match2 != shortest) return blank;
                return result1;

            }
        }
        return blank;
    }
};