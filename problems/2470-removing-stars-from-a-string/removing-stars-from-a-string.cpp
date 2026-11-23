class Solution {
public:
    string removeStars(string s) {
        std::stack<char> z;
        for (char x: s) {
            if (x != '*') {
                z.push(x);
            }
            else {
                z.pop();
                continue;
            }
        }
        string result;
        while (!z.empty()) {
            result += z.top();
            z.pop();
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};