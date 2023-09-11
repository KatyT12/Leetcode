#include <math.h>
using namespace std;
//1359 [Hard]

/* Supposedly hard but really this is just a maths question and isn't hard to do on paper, just think about it inductively.*/
/* Made curr long on the calculation to be able to then mod it and it will be an integer again*/
class Solution {
public:
    int countOrders(int n) {
        int curr = 1;
        for (int i = 2; i <= n; i++) {
            int num_order = (2 * (i - 1) + 1);
            curr = ((long)curr * (long)(num_order * (num_order + 1)) / 2) % ((int)pow(10, 9) + 7);
        }
        return curr;
    }
};