class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> minHeap1;
        priority_queue<int, vector<int>, greater<int>> minHeap2;

        // we want to populate minHeap with the first candidates candidates
        int front = 0;
        int back = (int)costs.size() - 1;
        for (int i = 0; i < candidates; i++) {
            
            if (front <= back) minHeap1.push(costs[front++]);
            if (back >= front) minHeap2.push(costs[back--]);
        }

        long long hiring_cost = 0;
        for (int i = 0; i < k; i++) {
            if (minHeap2.empty() || !minHeap1.empty() && minHeap1.top() <= minHeap2.top()) {
                hiring_cost += minHeap1.top();
                minHeap1.pop();
                if (front <= back) minHeap1.push(costs[front++]);
            }
            else {
                hiring_cost += minHeap2.top();
                minHeap2.pop();
                if (back >= front) minHeap2.push(costs[back--]);
            }
        }
        return hiring_cost;
    }
};