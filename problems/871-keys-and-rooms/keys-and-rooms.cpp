class Solution {
private:
    void dfs(int key, vector<vector<int>>& rooms, std::vector<bool> &visited) {
        for (auto keys : rooms[key]) {
            if (!visited[keys]) {
                visited[keys] = true;
                dfs(keys, rooms, visited);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        std::vector<bool> visited(n, false);

        visited[0] = true;
        dfs(0, rooms, visited);


        for (bool status : visited) {
            if (!status) {
                return false;
            }
        }
        return true;
    }
};