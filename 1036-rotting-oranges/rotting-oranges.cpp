class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();

        std::queue<pair<int,int>> q;
        
        auto isOk = [&](int r, int c) {
            return r < numRows && r >= 0 && c < numCols && c >= 0;
        };

        // for each rotten fruit, push them originally, then if they are friends with a fresh
        // fruit change it to rotten adn push it, then at the end loop thorugh and see if there are any fresh remaining

        int fresh = 0; 
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if ((isOk(i, j)) && grid[i][j] == 2) {
                    q.push({i, j});
                }
                if ((isOk(i, j)) && grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if (fresh == 0) {
            return 0;
        }

        int minutes = 0;
        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++){ 
            auto [row, col] = q.front();
            q.pop();

            if (isOk(row + 1, col) && grid[row + 1][col] == 1) {
                grid[row + 1][col] = 2;
                q.push({row + 1, col});
                fresh--;
            }
            if (isOk(row - 1, col) && grid[row - 1][col] == 1) {
                grid[row - 1][col] = 2;
                q.push({row - 1, col});
                fresh--;
            }
            if (isOk(row, col + 1) && grid[row][col + 1] == 1) {
                grid[row][col + 1] = 2;
                q.push({row, col + 1});
                fresh--;
            }
    
            if (isOk(row, col - 1) && grid[row][col - 1] == 1) {
                grid[row][col - 1] = 2;
                q.push({row, col - 1});
                fresh--;
            }}

            if (!q.empty()) minutes++;
        }

        if (fresh != 0) {
            return -1;
        }
        
        return minutes;

    }
};