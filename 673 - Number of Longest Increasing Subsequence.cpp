#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    map<int, int> subseqs = {};
    map<int, int> lengths = {};
    map<int, int> totallengths = {};
    pair<int, int> longestIncreasingSubseq(vector<int>& nums, int index) {
        if (subseqs.find(index) != subseqs.end()) {
            return { subseqs[index], lengths[index] };
        }
        int currLongest = 1;
        lengths[index] = 1;
        for (int i = index; i < nums.size(); i++) {
            if (nums[i] > nums[index]) {
                pair<int, int> ret = longestIncreasingSubseq(nums, i);
                int len = ret.first + 1;
                int n = ret.second;
                if (len > currLongest) {
                    currLongest = len;
                    lengths[index] = n;
                }
                else if (len == currLongest) {
                    lengths[index] += n;
                }
            }
        }
        subseqs[index] = currLongest;
        totallengths[currLongest] += lengths[index];
        return { currLongest,lengths[index] };
    }
    int findNumberOfLIS(vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {
            longestIncreasingSubseq(nums, i);
        }
        int k = (--totallengths.end())->first;

        return totallengths[k];
    }
};