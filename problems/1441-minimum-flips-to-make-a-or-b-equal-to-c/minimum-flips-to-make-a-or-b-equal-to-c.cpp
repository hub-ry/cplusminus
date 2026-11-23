class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip = 0;
        while (a != 0 | b != 0 | c != 0) {
            int abit = a % 2;
            int bbit = b % 2;
            int cbit = c % 2;

            if (cbit == 1) {
                if (!abit && !bbit) {
                    flip++;
                }
            
            }
            else {
                // we need to flip every 1.
                if (abit) flip++;
                if (bbit) flip++;
        
            }
            a/=2;
            b/=2;
            c/=2;
        }
        return flip;
    }
};