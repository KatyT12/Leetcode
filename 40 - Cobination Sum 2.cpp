class Solutions {
public:
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

    //Combinations that sum to target without duplicates
    vector<vector<int>> ret2 = {};
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        combinationSum2_(candidates, target, {});
        return ret2;
    }

    void eraseAllOf(vector<int>& v, int a) {
        if (v.empty()) {
            return;
        }
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i] == a) {
                v.erase(v.begin() + i);
            }
        }
    }

    void combinationSum2_(vector<int> candidates, int target, vector<int> path) {
        if (candidates.empty()) {
            return;
        }
        while (!candidates.empty()) {
            int k = candidates[0];
            vector<int> p = path;
            p.push_back(k);

            candidates.erase(candidates.begin());
            if (k == target) {
                ret2.push_back(p);
            }
            else if (k < target) {
                vector<int> c = candidates;
                combinationSum2_(c, target - k, p);
            }
            eraseAllOf(candidates, k);
        }
    }
};