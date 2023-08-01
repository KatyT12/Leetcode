class Solution {
public:
    vector<vector<int>> appendAll(int n, vector<vector<int>> a){
        for(auto& i : a){
            i.push_back(n);
        }
        return a;
    }
    vector<vector<int>> combine(int n, int k) {
        if(n < k){
            return {};
        }
        if(k == 0){
            return {{}};
        }
        vector<vector<int>> a = appendAll(n,combine(n-1,k-1));
        vector<vector<int>> b = combine(n - 1, k);
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
};