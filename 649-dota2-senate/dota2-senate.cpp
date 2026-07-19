class Solution {
public:
    string predictPartyVictory(string senate) {
        std::queue<int> r;
        std::queue<int> d;
        int n = senate.size();

        for (int i = 0; i < senate.length(); i++) {
            if (senate[i] == 'R') {
                r.push(i);
            }
            if (senate[i] == 'D') {
                d.push(i);
            }
        }
        while (!r.empty() && !d.empty()) {
            int rn = r.front();
            int dn = d.front();
            r.pop();
            d.pop();

            if (rn < dn) {
                r.push(rn + n);
            } 
            else {
                d.push(dn + n);
            }

        }
        
        return (r.empty()) ? "Dire" : "Radiant";
    }
};