class Solution {
public:
    struct Hasher{
        int operator()(const std::pair<int, int>& p) const
        {
            return p.first ^ (p.second << 7) ^ (p.second >> 3);
        }
    };

    unordered_map<pair<int,int>, int, Hasher> mem = {};
    
    
    int helper(vector<int>& nums, int start, int end){
        if(start == end){
            return nums[start];
        }
        if(mem.find({start,end}) != mem.end()){
            return mem[{start,end}];
        }
        mem[{start, end}] = max(nums[start] - helper(nums, start + 1, end), nums[end] - helper(nums,start, end-1));
        return mem[{start, end}];
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1) >= 0;
    }
};