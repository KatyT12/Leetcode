#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map = {};
        if (s == "") {
            return 0;
        }
        //Initialization
        int maxStart = 0;
        int maxEnd = 0;
        int start = 0;
        int end = 0;
        int i = 0;
        while (i < s.length()) {
            if (map.find(s[i]) != map.end() || i == s.length() - 1) {

                //If we have reached the end we must account for that
                end = i - 1;
                if (map.find(s[i]) == map.end()) {
                    end = i;
                }
                
                //If we have a new maximum
                if (end - start > maxEnd - maxStart) {
                    std::cout << start << " " << end << "\n";
                    maxStart = start;
                    maxEnd = end;
                }
                //Reset to position after repeated character
                if (map.find(s[i]) != map.end()) {
                    start = map[s[i]] + 1;
                    i = start;
                    map = {};
                    map[s[i]] = i;
                }
            }
            else {
                map[s[i]] = i;
            }
            i++;
        }
        return maxEnd - maxStart + 1;
    }
};