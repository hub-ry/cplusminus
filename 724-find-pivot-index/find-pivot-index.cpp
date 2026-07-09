class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;

        for (int x : nums) {
            total += x;
        }

        int lsum = 0;
        int rsum = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            int rsum = total - lsum - nums[i];

            if (rsum == lsum) {
                return i;
            }

            lsum += nums[i];

           
            
        }
        return -1;
    }
};