class Solution {
public:
    static const int MOD = 1000000000 + 7;
    int n;
    vector<vector<int>> dp;

    int makeState(bool t1, bool t2) { return (t1 ? 2 : 0) | (t2 ? 1 : 0); }


    int f(int i, bool t1, bool t2) {
        if (i == n) {
            return 1;
        }

        int state = makeState(t1,t2);
        if (dp[i][state] != -1) {
            return dp[i][state];
        }

        bool t3 = i + 1 < n, t4 = i + 1 < n;
        long long count = 0;
        if ( t1 &&  t2 && t3)             count += f(i + 1, false, true);
        if ( t1 &&  t2 && t4)             count += f(i + 1, true,  false);
        if ( t1 && !t2 && t3 && t4)       count += f(i + 1, false, false);
        if (!t1 &&  t2 && t3 && t4)       count += f(i + 1, false, false);
        if ( t1 &&  t2)                   count += f(i + 1, true,  true);
        if ( t1 &&  t2 && t3 && t4)       count += f(i + 1, false, false);
        if ( t1 && !t2 && t3)             count += f(i + 1, false, true);
        if (!t1 &&  t2 && t4)             count += f(i + 1, true,  false);
        if (!t1 && !t2)                   count += f(i + 1, true,  true);

        return dp[i][state] = count % MOD;
    }


    int numTilings(int n) {
        this->n = n;
        dp.assign(n, vector<int>(4, -1));
        return f(0, true, true);


    }
};