class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<vector<int>>> mem = {};
        for(int i = 0; i < groupSizes.size(); i++){
            int j = groupSizes[i];
            if(mem.find(j) == mem.end()){
                mem[j] = {{i}};
            }else{
                if(mem[j][mem[j].size() - 1].size() == j){
                    mem[j].push_back({i});
                }else{
                    mem[j][mem[j].size() - 1].push_back(i);
                }
            }
        }
        vector<vector<int>> ret = {};
        for(auto& p : mem){
            for(auto& group : p.second){
                ret.push_back(group);
            }
        }
        return ret;
    }
};