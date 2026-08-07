class Solution {
private: 
    void dfs(int city, vector<vector<int>>& isConnected,  std::vector<bool>& visited) {
        visited[city] = true;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (isConnected[city][i] && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        std::vector<bool> visited(n,false);

        for (int i = 0; i < isConnected.size(); ++i) {
            if (!visited[i]) {
                provinces++;
                dfs(i, isConnected, visited);
            }
        }
        return provinces;

    }
};