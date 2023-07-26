class Solution {
public:
    
    bool checkValid(int speed, vector<int>& dist, double hour){
        double time = 0;
        for(int d : dist){
            if(time != int(time)){
                time += (1 - (time - int(time)));
            }
            time += d/double(speed);
        }
        return time <= hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int min = 1;
        int max = 10000000;
        while(true){
            int mid = (min + max)/2;
            if(min > max){
                return -1;
            }
            else if(min == max && checkValid(max,dist,hour)){
                return max;
            }
            if(checkValid(mid,dist,hour)){
                max = mid;
            }else{
                min = mid + 1;
            }
        }
        return -1;
    }
};