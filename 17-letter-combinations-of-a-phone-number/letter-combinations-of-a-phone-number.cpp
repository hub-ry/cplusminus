class Solution {
private: 
    void backtrack(int index,  string& digits, vector<string>& pad, string& path, vector<string>& result) {
        // if base condition
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }

        string letters = pad[digits[index] - '0'];
        for (char c : letters) {
            path.push_back(c);
            backtrack(index + 1, digits, pad, path, result);
            path.pop_back();
        }
        

        // for choice : choices
        //make choice 
        //backtrack -- updated
        // undo -- usually a pop
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string path;
        backtrack(0, digits, pad, path, result);
       
        return result;
    }
};