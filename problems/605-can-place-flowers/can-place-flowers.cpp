class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int czeros = 1;

        for (size_t i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                czeros++;
            }
            else {
                n -= ((czeros - 1) / 2);
                if (n <= 0) return true;
                czeros = 0;
            }
        }
        n -= (czeros / 2);
        return (n <= 0);
    }

};