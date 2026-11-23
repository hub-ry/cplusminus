/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
private:
    int helpr(int min, int max) {
        int n = min + (max - min) / 2;
        int g = guess(n);

        if (g == -1) return helpr(min, n - 1);
        if (g == 1) return helpr(n + 1, max);
        return n;
    }
public:
    int guessNumber(int n) {
        return helpr(1, n);
    }
};