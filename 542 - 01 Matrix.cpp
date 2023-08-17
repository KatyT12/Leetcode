class Solution {
public:
    vector<vector<int>> ret = {};
    vector<vector<int>> vecs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    queue<pair<int,int>> start_from = {};
    int m,n;

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(); n = mat[0].size();
        ret.assign(m, vector<int>(n,1000000));
        
        //Start from zeros
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    ret[i][j] = 0;
                    start_from.push({i,j});
                }
            }
        }
        
        while(!start_from.empty()){
            auto p = start_from.front();
            start_from.pop();
            for(auto& v : vecs){
                int x = p.first + v[0]; int y = p.second + v[1];
                int val = ret[p.first][p.second] + 1;   
                if( (x >= 0 && x < m && y >= 0 && y < n) && val < ret[x][y]){
                    ret[x][y] = val;
                    start_from.push({x,y});
                }
            }   
        }
        return ret;
    }
};