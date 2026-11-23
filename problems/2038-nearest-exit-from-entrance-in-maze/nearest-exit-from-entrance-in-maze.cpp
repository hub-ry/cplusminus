class Solution {

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        std::queue<pair<int, int>> q;
        
        int numRows = maze.size();
        int numCols = maze[0].size();

        q.push({entrance[0], entrance[1]});

        auto ok = [&](int r, int c) {
            return r >= 0 && r < numRows && c >= 0 && c < numCols && maze[r][c] == '.';
        };

        auto isExit = [&](int r, int c) {
            return (r == 0 || r == numRows - 1 || c == 0 || c == numCols - 1);
        };
        int dist = 0;
        while (!q.empty()) {

            int n = q.size();
            for (int i = 0; i < n; i++)
            {// pop
            auto [row, col] = q.front();
            q.pop();

            if (isExit(row, col)) {
                if (!(row == entrance[0] && col == entrance[1])) {
                    return dist;
                }
            }

            if (ok(row + 1, col)) {
                maze[row + 1][col] = '+';
                q.push({row + 1, col});
            }
            if (ok(row - 1, col)) {
                maze[row - 1][col] = '+';
                q.push({row - 1, col});
            }
            if (ok(row, col + 1)) {
                maze[row][col + 1] = '+';
                q.push({row, col + 1});
            }
            if (ok(row, col - 1)) {
                maze[row][col - 1] = '+';
                q.push({row, col - 1});
            }}

            dist++;
        }
        
        return -1;
        
    }
};