#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() -1;
        bool done = false;
        while(!done){
            int mid = (right + left) / 2;
            cout << mid << " " << arr.size() << "\n";
            if(mid == arr.size()-1 || arr[mid] > arr[mid + 1]){
                if(mid == 0 || arr[mid] > arr[mid - 1]){
                    return mid;
                }else{
                    right = mid;
                }
            }else{
                left = mid;
            }
        }
        return -1;
    }
};