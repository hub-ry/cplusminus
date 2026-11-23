class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> z;
    
        for (int i : asteroids) {
            bool alive = true;

            // if they are moving towards each other
            while (alive && i < 0 && !z.empty() && z.top() > 0) {
                // if new needs to crush old 
                if (std::abs(i) > std::abs(z.top())) {
                    z.pop();
                }
                // if old needs to crush new
                else if (std::abs(i) < std::abs(z.top())) {
                    alive = false;
                }
                // if equal
                else {
                    z.pop();
                    alive = false;
                }
            }
            if (alive) {
                z.push(i);
            }
            
        }
        std::vector<int> result;
        while (!z.empty()) {
            result.push_back(z.top());
            z.pop();
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};