class Solution {
private: 
    void backtrack(int start, vector<int>& path, int path_sum, int k , int n, vector<vector<int>>& result) {
        
        if (path.size() == k) {
            if (path_sum == n) {
                result.push_back(path);
            }
            return;
        }


        for (int i = start; i <= 9; i++) {
            path.push_back(i);
            path_sum += i;

            backtrack(i + 1, path, path_sum, k, n, result);

            path.pop_back();
            path_sum -= i;
        }
    }
        

public:
    vector<vector<int>> combinationSum3(int k, int n) {

        // k is the amount of nums 1 - 9
        // n is what they will sum up to
        vector<int> path;
        vector<vector<int>> result;

        backtrack(1, path, 0, k, n, result);
        return result;
    }
};