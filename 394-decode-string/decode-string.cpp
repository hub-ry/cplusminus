class Solution {
public:
    string decodeString(string s) {
        std::stack<int> numbers;
        std::stack<string> strings;
        int currNum = 0;
        std::string currString = "";
        for (char x : s) {
            if (isdigit(x)) {
                currNum = currNum * 10 + (x - '0');
            }
            else if (x == '[') {
                numbers.push(currNum);
                strings.push(currString);
                currNum = 0;
                currString = "";
            }
            else if (x == ']') {
                //write strings.top() numbers.top() times
                string repeated = "";
                for (int i = 0; i < numbers.top(); i++) {
                    repeated += currString;
                }
                string prev = strings.top();
                strings.pop();
                currString = prev + repeated;
                numbers.pop();

            }
            else {
                currString += x;
            }
            
        }
        return currString;
    }
};