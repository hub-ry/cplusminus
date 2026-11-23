class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        std::unordered_map<string, int> row;
        int result = 0;
        // read each row
        for (int i = 0; i < grid[0].size(); i++) {
            std::string kee;
            for (int j = 0; j < grid[0].size(); j++) {
                kee += to_string(grid[i][j]);
                kee += "0";
            }
            row[kee]++;
        }
        // read each row
        for (int i = 0; i < grid[0].size(); i++) {
            std::string kee;
            for (int j = 0; j < grid[0].size(); j++){
                kee += to_string(grid[j][i]);
                kee += "0";
            }
            if (row.count(kee)) {
                result += row[kee];
            }
        }
        return result;
    
    }
};