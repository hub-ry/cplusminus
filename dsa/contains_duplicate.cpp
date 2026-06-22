class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) { 
            if (seen.count(nums[i]) == 1) { //search by the number
                return true;
            }
            seen[nums[i]] = 1; 
        }
        return false;
    }
};


// my first implementation was actually kinda bad, i the = 1; tells that a map is the wrong thing for the job.
// instead, std::unordered_set is better -- i still have to learn the difference between a set and a map for sure



class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int i = 0; i < nums.size(); i++) { 
            if (seen.count(nums[i]) == 1) { //search by the number
                return true;
            }
            seen.insert(nums[i]);
        }
        return false;
    }
};