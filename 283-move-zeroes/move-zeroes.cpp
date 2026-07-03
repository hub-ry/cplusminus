class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int place_i = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                continue;
            }
            else {
                nums[place_i] = nums[i];
                place_i++; 
            }
        }
        for (int i = place_i; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};