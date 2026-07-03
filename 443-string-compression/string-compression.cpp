class Solution {
public:
    int compress(vector<char>& chars) {
        int s = 0;
        char curr = chars[0];
        chars[s++] = chars[0];
        int count = 1;
        for (size_t i = 1; i < chars.size(); i++) {
            if (chars[i] == curr) {
                count ++;
            }
            else {
                if (count != 1) {
                    std::string num = std::to_string(count);
                    for (char c : num) chars[s++] = c;
                }
                chars[s++] = chars[i];
        
                count = 1;
            }
            curr = chars[i];
        }
        if (count != 1) {
            std::string num = std::to_string(count);
            for (char c : num) chars[s++] = c;
        }
        
        return s;
    }
};