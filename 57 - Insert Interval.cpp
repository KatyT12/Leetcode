#include <vector>
#include<iostream>
using namespace std;


class Intervals {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        while (i < intervals.size()) {
            vector<int> j = intervals[i];
            if (newInterval[0] <= j[0]) {
                if (newInterval[1] < j[0]) {
                    std::cout << "Insert " << newInterval[0] << " " << newInterval[1] << "\n";
                    intervals.insert(intervals.begin() + i, newInterval);
                    return intervals;
                }
            }
            if (!((newInterval[0] < j[0] && newInterval[1] < j[0]) || (newInterval[0] > j[1] && newInterval[1] > j[1])))
            {
                vector<int> n = { min(newInterval[0], j[0]), max(newInterval[1],j[1]) };
                intervals.erase(intervals.begin() + i);
                std::cout << n[0] << " " << n[1] << "\n";
                return insert(intervals, n);
            }
            i++;
        }
        intervals.push_back(newInterval);
        return intervals;
    }

};