class RecentCounter {
    private:
        std::queue<int> q;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        q.push(t);
        // curr - oldest needs to be newer than 3000
        while (t - q.front() > 3000) {
            q.pop();
        }
        return static_cast<int>(q.size());
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */