#include <iostream>
#include <vector>
using namespace std;
/*
Question about trapping rain water given a height map. Solution
much simpler than I thought but eventualy got there. Had the right idea of finding maximums.
But only the maximum mattered really.
*/
class TrappingWater {
public:
    int trap(vector<int>& height) {
        //Find max
        int n = height.size();
        int max = height[0];
        int maxi = 0;
        int i = 1;
        while (i < n) {
            if (max < height[i]) {
                max = height[i];
                maxi = i;
            }
            i++;
        }
        //From start
        i = 1;
        int total = 0;
        int leftMax = height[0];
        int rightMax = height[n - 1];
        while (i < maxi) {
            if (height[i] < leftMax) {
                total += leftMax - height[i];
            }
            else if (height[i] > leftMax) {
                leftMax = height[i];
            }
            i++;
        }
        i = n - 2;
        while (i > maxi) {
            if (height[i] < rightMax) {
                total += rightMax - height[i];
            }
            else if (height[i] > rightMax) {
                rightMax = height[i];
            }
            i--;
        }
        return total;
    }
};