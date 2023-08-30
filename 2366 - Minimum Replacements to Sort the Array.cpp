#include <vector>
using namespace std;

class Solution {
public:

    //Position, max
    long long minimumReplacement(vector<int>& nums) {
        int max = nums[nums.size() - 1];
        long long ops = 0;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] > max) {
                int m = nums[i];
                long long op = m / max;

                if (m % max != 0) {
                    ops += op;
                    max = m / (op + 1);
                }
                else {
                    ops += op - 1;
                }
                /* It is a fact that if a number (17) is going to be divided into some number of pieces (4) pieces,
                the maximum minimum of the split numbers is going to be the number of peices (4) -> 4445, and
                this is going to be below the max as it is the number of pieces needed in order to be below or equal to
                the max*/
            }
            else if (nums[i] < max) {
                max = nums[i];
            }
        }
        return ops;
    }
};