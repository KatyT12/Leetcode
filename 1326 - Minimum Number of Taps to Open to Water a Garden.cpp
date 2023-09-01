#include <vector>
#include <stack>
using namespace std;


//HARD

/* Originally tried DP but problem was that problem can't be neatly split (minimum for section of garden might not be included in minimum for whole garden).
* Then just tried for loop but had problems with keeping track of taps, so used a stack for that, after lots of debugging eventually works.
*/

/*
    gap -> records the *first* gap in all the taps so far , only the first needs
    to be recorded because if the first is corrected all the later ones will be to as we go left to right.
    If there is a gap we won't add any more taps until it is corrected
*/

class Solution {
public:
    stack<int> taps;

    // start, end, number
    int minTaps(int n, vector<int>& ranges) {

        int start = n + 1;
        int end = -1;
        int gap = 0;
        for (int i = 0; i <= n; i++) {
            if (ranges[i] > 0) {
                if (start >= i - ranges[i]) {
                    // If there is a new start then all previous can be removed
                    start = i - ranges[i];
                    end = i + ranges[i];
                    taps = {};
                    taps.push(i);
                    //Check if a gap is corrected
                    if (start <= gap) gap = -1;
                }
                else {
                    // If start after current end and gap not assigned then we have a new gap
                    if (i - ranges[i] > end && gap == -1) {
                        gap = end;
                    }

                    // If new end after old end and no gap so far
                    else if (i + ranges[i] > end && i - ranges[i] <= end && gap == -1 && end < n) {
                        end = min(i + ranges[i], n);
                        //Remove all taps that start before the new one starts
                        if (i - ranges[i] <= 0) {
                            taps = {};
                        }
                        else {
                            while (!taps.empty() && i - ranges[i] <= taps.top() - ranges[taps.top()]) {
                                taps.pop();
                            }
                            //Remove tap if it is not needed (previous tap ends after start of new tap)
                            if (!taps.empty()) {
                                int j = taps.top();
                                taps.pop();
                                if (!taps.empty()) {
                                    if (!(ranges[taps.top()] + taps.top() >= i - ranges[i])) {
                                        taps.push(j);
                                    }
                                }
                                else {
                                    taps.push(j);
                                }
                            }
                        }
                        // Add new tap
                        taps.push(i);
                    }
                }
            }
        }

        //Finally return
        if (gap != -1 || start > 0 || end < n) {
            return -1;
        }
        else {
            return taps.size();
        }
    }
};


/*LESSON: THINK HARD ABOUT THE GREEDY CHOICE: THIS TIME IT IS THE LONGEST TAP THAT COVERS WHAT WE NEED IT TO
This is a more optimal solution. See, first it will generate an array that shows for each index the taps that start
there and how far they can reach to. Then go through it and whenever we reach an end we increment counter. You can see how this covers gaps.
See this recovers no information about the taps used but it doesn't have to.

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> arr(n + 1, 0);
        for(int i = 0; i < ranges.size(); ++i) {
            if(ranges[i] == 0) continue;
            int left = max(0, i - ranges[i]);
            arr[left] = max(arr[left], i + ranges[i]);
        }

        int end = 0, far_can_reach = 0, cnt = 0;
        for(int i = 0; i <= n; ++i) {
            if(i > end) {
                if(far_can_reach <= end) return -1;
                end = far_can_reach;
                ++cnt;
            }
            far_can_reach = max(far_can_reach, arr[i]);
        }

        return cnt + (end < n);
    }
};
*/