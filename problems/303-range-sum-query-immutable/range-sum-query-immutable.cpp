class NumArray {
private:
    std::vector<int> psum;
public:
    NumArray(vector<int>& nums) {
        psum.push_back(0);
        for (int num : nums) {
            psum.push_back(psum.back() + num);
        }
    }
    
    int sumRange(int left, int right) {
        return psum[right + 1] - psum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */