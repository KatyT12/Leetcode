/* Variation of longest substring problem*/

class Solution {
public:

    vector<vector<int>> mem;
    int countAscii(string& s, int start, int end){
        int total = 0;
        for(int i = start; i < end; i++){
            total += (int) ((char)s[i]);
        }
        return total;
    }

    int helper(string& s1, string& s2, int end1, int end2){
        //cout << end1 << " " << end2 << "\n";
        if(mem[end1][end2] != -1){
            return mem[end1][end2];
        }
        if(end1 == 0){
            mem[end1][end2] = countAscii(s2, 0, end2);
        }else if(end2 == 0){
            mem[end1][end2] = countAscii(s1, 0, end1);
        }else{
            if(s1[end1-1] == s2[end2-1]){
                mem[end1][end2] =  helper(s1, s2, end1 -1, end2 - 1);
            }else{
                mem[end1][end2] =  min(helper(s1,s2, end1 -1, end2) + (int)((char) s1[end1 - 1]), (int)((char) s2[end2 - 1]) + helper(s1, s2, end1, end2 - 1));
            }
        }
        return mem[end1][end2];
    }

    int minimumDeleteSum(string s1, string s2) {
        mem.assign(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return helper(s1, s2, s1.size(), s2.size());
    }
};