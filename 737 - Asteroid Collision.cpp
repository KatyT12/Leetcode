#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool step(vector<int>& asteroids) {
        unordered_map<int, int> m = {};
        vector<int> erased = {};
        bool ret = false;
        for (int i = 0; i < asteroids.size(); i++) {
            int j = asteroids[i] / abs(asteroids[i]) + i;
            if (m.find(i) != m.end() && asteroids[m[i]] / abs(asteroids[m[i]]) != j - i) {
                //Collision
                ret = true;
                if (abs(asteroids[m[i]]) < abs(asteroids[i])) {
                    erased.push_back(m[i]);
                    m.erase(i);
                    m[i] = i;
                }
                else if (abs(asteroids[m[i]]) > abs(asteroids[i])) {
                    erased.push_back(i);
                }
                else {
                    erased.push_back(m[i]);
                    erased.push_back(i);
                    m.erase(i);
                }
            }
            else {
                m[j] = i;
            }
        }
        for (int i = erased.size() - 1; i >= 0; i--) {
            asteroids.erase(asteroids.begin() + erased[i]);
        }
        return ret;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        bool carryon = true;
        while (carryon) {
            carryon = step(asteroids);
        }
        return asteroids;
    }
};