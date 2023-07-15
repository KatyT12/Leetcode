#include <iostream>
#include <vector>
using namespace std;

class Solutions {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (nums[i] > 0) {
                int c = nums[i] - 1;
                if (nums[i] > 0 && c < n && nums[i] != nums[c]) {
                    int temp = nums[c];
                    nums[c] = nums[i];
                    nums[i] = temp;
                }
                else {
                    i++;
                }
            }
            else {
                i++;
            }
        }
        for (int i = 0; i < n; i++) {

            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};