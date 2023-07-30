class Solution {
public:
    vector<vector<int>> mem;
    int helper(string& s, int start, int end){
        //cout << start << " " << end << "\n";
        if(mem[start][end] != 0){
            return mem[start][end];
        }
        if(start == end){
            mem[start][end] = 1;
            return 1;
        }

        int p = helper(s, start, end - 1) + 1;
        for(int i = start; i < end; i++){
            if(s[i] == s[end]){
                if(i < end - 1){
                    p = min(helper(s,start,i) + helper(s,i+1, end-1), p);
                }else{
                    p = min(helper(s,start,i), p);
                }
                
            }
        }
        mem[start][end] = p;
        return p;
    }

    int strangePrinter(string s) {
        mem.assign(s.size(), vector<int>(s.size(), 0));
        return helper(s, 0, s.size() - 1);
    }
};