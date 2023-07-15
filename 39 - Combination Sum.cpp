class Solutions {
public:
    
    // Combinations that sum to target with duplicates
    vector<vector<int>> ret = {};
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        combinationSum_(candidates, target, {});
        return ret;
    }

    void combinationSum_(vector<int>& candidates, int target, vector<int> path) {
        if (candidates.empty()) {
            return;
        }
        vector<int> c1 = candidates;
        for (int i = 0; i < candidates.size(); i++) {
            int k = candidates[i];
            vector<int> p = path;
            p.push_back(k);
            if (k == target) {
                ret.push_back(p);
            }
            else if (k < target) {
                combinationSum_(c1, target - k, p);
            }
            c1.erase(c1.begin());
        }
    }
};