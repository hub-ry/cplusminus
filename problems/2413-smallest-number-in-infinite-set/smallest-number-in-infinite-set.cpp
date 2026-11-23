class SmallestInfiniteSet {
    int nextClean = 1;
    set<int> s;

public:
    SmallestInfiniteSet() {}
    
    int popSmallest() {
        if (!s.empty()) {
            int v = *s.begin();
            s.erase(s.begin());
            return v;
        }
        return nextClean++;
    }
    
    void addBack(int num) {
        if (num < nextClean) s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */