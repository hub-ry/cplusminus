class Solution {
private:
    double dfs(string q1, string q2, double mult, unordered_map<string, vector<pair<string, double>>> &adj, std::unordered_set<string>& visited) {
        if (q1 == q2) return mult;

        visited.insert(q1);

        for (auto& [nxt, w] : adj[q1]) {
            if (visited.count(nxt)) continue;
            double res = dfs(nxt, q2, mult * w, adj, visited);
            if (res != -1.0) return res;
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        unordered_map<string, vector<pair<string, double>>> adj;

        // for each a->b , just show they are neighbors and make two to show the path direction
        for (int i = 0; i < equations.size(); ++i) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        vector<double> ans;
        for (auto &q : queries) {
            if (!adj.count(q[0]) || !adj.count(q[1])) {
                ans.push_back(-1.0);
            }
            else {
                std::unordered_set<string> visited;
                ans.push_back(dfs(q[0], q[1], 1.0, adj, visited));
            }
        }
        return ans;
    }
};