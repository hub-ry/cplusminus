class Solution {
public:
    string decodeString(string s) {
        std::stack<pair<int, string>> x;
        int num = 0;
        string temp = "";
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                x.push({num, temp});
                num = 0;
                temp = "";
            } else if (c == ']') {
                auto [mult, msg] = x.top();
                x.pop();

                string chunk = temp;
                temp = msg;
                for (int i = 0; i < mult; i++) {
                    temp += chunk;
                }
                
            } else {
                temp += c;
            }
        }
        return temp;
    }
};