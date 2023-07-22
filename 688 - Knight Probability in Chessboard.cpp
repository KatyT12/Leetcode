class Solution {
public:
    vector<vector<int>> vecs = {{-2,1},{1,-2},{-1,2},{2,-1},{-2,-1},{-1,-2},{1,2},{2,1}};
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> board(n, vector<double>(n, 0));
        board[row][column] = 1;
        // i -> row j-> col
        for(int l=0; l < k; l++){
            vector<vector<double>> nboard(n, vector<double>(n, 0));
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    double p = 0;
                    for(auto& v : vecs){
                        int r = i + v[0];   
                        int c = j + v[1];
                        if(r >= n || c >= n || r < 0 || c < 0){
                            continue;
                        }else{
                            p += board[r][c]/double(8);
                        }
                    }
                    nboard[i][j] = p;
                }
            }
            board = nboard;
        }
        double total = 0;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    total += board[i][j];
                }
        }
        return total;
    }
};