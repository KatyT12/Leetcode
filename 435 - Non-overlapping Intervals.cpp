using namespace std;

bool compare(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] < v2[0];
}

class Solution {
public:
    bool overlaps(vector<int> v1, vector<int> v2) {        
        if (v1[0] < v2[1] && v1[1] > v2[0]) {
            return true;
        }
        else if (v2[0] < v1[1] && v2[1] > v1[0]) {
            return true;
        }
        else {
            return false;
        }
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() < 2){
            return 0;
        }       
        sort(intervals.begin(), intervals.end(), compare);

        bool finished = false;
        int i = 1;
        int total = 0;
        vector<int> last = intervals[0];
        while (!finished) {
            vector<int> t = intervals[i];
            //Check if overlapping
            if (overlaps(last, t)) {
                //Get rid of one that finished earlier
                total++;
                if (last[1] > t[1]) {
                    last = t;
                }
            }
            else {
                last = intervals[i];
            }
            i++;
            if (i > intervals.size() - 1) {
                finished = true;
            }
        }
        return total;
    }
};