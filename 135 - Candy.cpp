#include <vector>
using namespace std;

/*
last_l keeps track of the index of the last rating that does not decrease from the previous rating.
Then update count appropriatly in relation to where the last_l is to the current index. Really it is simple
to work this logic out by working through an example on paper, easier than explaining in a comment.
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int count = 1;
        int last_l = 0;
        int lval = 1;
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] < ratings[i-1]){
                count += i- last_l;
                if(i-last_l >= lval) {lval++; count++;}
            }else if(ratings[i] > ratings[i-1]){
                if(last_l == i - 1)lval = lval +1;
                else lval = 2;     
                last_l = i;count+= lval;
            }else{
                last_l = i;
                lval = 1;
                count++;
            }
        }
        return count;
    }
};