#include <vector>
using namespace std;

/* Probably a much faster and fancier way of doing it, but this is enough. Uses the position of the first zero
to count how many new ones there will be compared to the last number*/


/* Maths for calculating first zero: n & (n-1) will get rid of the rightmost 1,
so ~(~n & ~(n+1)) gets rid of the rightmost 0, then take away the origional number to get the rightmost zero*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans = vector<int>(n + 1, 0);
        int m = 0; //Number of bits
        int count = 0;
        for (int i = 0; i < n; i++) {
            int first_zero = log2(~(~i & ~(i + 1)) - i);
            if (first_zero == m) {
                count = 1;
                m++;
            }
            else {
                count = count - first_zero + 1;
            }
            ans[i + 1] = count;
        }
        return ans;
    }
};