class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int most = 0;
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] > most) {
                most = candies[i];
            }
        }
        std::vector<bool> result;
        bool x;
        for (int i = 0; i < candies.size(); i++) {
            x = (candies[i] + extraCandies >= most) ? true : false;
            result.push_back(x);
        }
        return result;
    }
};