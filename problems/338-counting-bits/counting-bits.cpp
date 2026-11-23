class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> x;

        for (int i = 0; i <= n; i++) {
            // we need to see how many times it is divisible by 2.
            int k = 0;
            int m = i;
            while (m != 0) {
                if (m % 2 == 1) k++;
                m = m/2;
            }
            x.push_back(k);
        }
        return x;
    }
};