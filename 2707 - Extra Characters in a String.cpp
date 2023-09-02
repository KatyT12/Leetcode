class Solution {
public:
    vector<vector<int>> mem;
    int helper(string& s, vector<string>& dictionary, int start, int end){
        if(start < 0 || end >= s.length() || start > end){
            return 0;
        }
        else if(mem[start][end] != -1){
            return mem[start][end];
        }
        int cmin = -1;
        for(int i = start; i <= end; i++){
            for(string& w : dictionary){
                int n = 0; int j = i;
                while(s[j] == w[n] && n < w.length() && j <= end){
                    n++; j++;
                }
                if(n == w.length()){
                    int x = helper(s,dictionary,j, end);
                    int y = helper(s,dictionary, start, i-1);
                    if(cmin == -1) cmin = x + y;
                    else cmin = min(cmin, x + y );
                }
            }
        }
        if(cmin == -1)mem[start][end] = end - start + 1;
        else mem[start][end] = cmin;
        
        return mem[start][end];
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        mem.assign(s.length(), vector(s.length(), -1));
        helper(s, dictionary, 0, s.length() - 1);
        return mem[0][s.length() - 1];
    }
};