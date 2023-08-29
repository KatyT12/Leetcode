class Solution {
public:
    int bestClosingTime(string customers) {
        int m = 0;
        int j = 0;
        for(auto& c : customers){
            if(c == 'Y'){
                m++;
            }
        }
        int last = m;
        for(int i = 1; i <= customers.size(); i++){
            if(customers[i-1] == 'N'){
                last++;
            }else{
                last--;
            }
            if(last < m){
                m = last;
                j = i;
            }
        }
        return j;
    }
};