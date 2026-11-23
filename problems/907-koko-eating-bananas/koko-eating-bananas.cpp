class Solution {
private:
    long long test(int k, vector<int>& piles) {
        long long sum = 0;
        for (int i : piles) {
            sum += (i + k - 1) / k;
        }
        return sum;
    }
    int bs(int left, int right, int h, vector<int>& piles) {
        

        if (right < left) {
            return left;
        }

        int mid = left + (right - left) / 2;
        
        // keep trying faster
        if (test(mid, piles) <= h) {
            return bs(left, mid - 1, h, piles);
        }
        else {
    
            return bs(mid + 1, right, h, piles);
        }
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int biggest_pile = 0;
        for (int num : piles) {
            biggest_pile = max(biggest_pile, num);
        }



        // biggest_pile now holds max 
        return bs(1, biggest_pile, h, piles);
    }
};