class Solution {
private:
    /*
     * This function returns the index of the first potions with the min strength needed
     */
    int bst(long long success, vector<int> &potions, int s_strength, int left, int right) {
        if (right < left) {
            return left;
        }

        int mid = left + (right - left) / 2;

        if ((long long)potions[mid] * s_strength >= success) {
            return bst(success, potions, s_strength, left, mid - 1);
        }
        else  {
            return bst(success, potions, s_strength, mid + 1, right);
        }

    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        std::sort(potions.begin(), potions.end());
        int pots = potions.size();


        // for each spell, find how many potions have their spell strength
        std::vector<int> result;
        for (int s_strength : spells) {
            int num = bst(success, potions, s_strength, 0, pots - 1);
            result.push_back(pots - num);
        }
        return result;
    }
};