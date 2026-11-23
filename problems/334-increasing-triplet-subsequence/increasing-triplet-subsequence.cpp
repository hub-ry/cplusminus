class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = nums[0];
        int b = 0;
        int c = 0;
        int b_set = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= a) {
                a = nums[i];
                continue;
            }
            if (!b_set) {
                if (nums[i] > a) {
                    b = nums[i];
                    b_set = 1;
                    continue; 
                }
            }
            if (nums[i] > a && nums[i] < b) {
                b = nums[i];
                continue;
            }
            if (nums[i] > b) {
                return true;
            }
            
            
        }
        return false;
    }
};