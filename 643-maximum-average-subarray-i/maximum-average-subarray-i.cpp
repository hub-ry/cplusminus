class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int front = 0;
        int back = 0;
        int total = 0;
        double max_mean = 0;
        double kd = k;
        for (size_t i = 0; i < nums.size(); i++) {
            if (i < k) {
                total += nums[i];
                max_mean = total / kd;
            }
            else {
                total = total - nums[front++];
                total = total + nums[i];
                if ((total / kd) > max_mean) {
                    max_mean = total / kd;
                }

            }
        }
        return max_mean;
    }
};