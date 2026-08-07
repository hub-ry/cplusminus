class Solution {
private:
    void dfs(int city, int road, std::vector<bool> &visited, int &flipped, vector<vector<pair<int,int>>> &adj) {
        // i is the random city we are exploring
        for (auto& [nb, dir] : adj[city]) {
            if (!visited[nb]) {
                visited[nb] = true;
                if (dir == 1) {
                    flipped++;
                }
                dfs(nb, road, visited, flipped, adj);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int a = 0; // set 0 to be the very first city
        int road = connections.size(); 
        int flipped = 0;
        std::vector<bool> visited(n, false);
        visited[0] = true;
        vector<vector<pair<int,int>>> adj(n);
        for (auto& c : connections) {
            adj[c[0]].push_back({c[1], 1});   // real road, points away from c[0]
            adj[c[1]].push_back({c[0], 0});   // the reverse, only for walking
        }
        // loop through each road to find where the first city is a: 
        dfs(a, road, visited, flipped, adj);

        return flipped;
        
    }
};