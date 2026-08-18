class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        std::vector<pair<int,int>> v;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0;
        long long best = 0;
        for (int i = 0; i < (int)nums1.size(); i++) {
            v.push_back({nums2[i], nums1[i]});
        }

        sort(v.rbegin(), v.rend());

        for (int i = 0; i < (int)v.size(); i++) {
            minHeap.push(v[i].second);
            sum += v[i].second;
            if ((int)minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if ((int)minHeap.size() == k) {
                best = max(best, sum * v[i].first);

            }
            
        }

        return best;
        
    }
};