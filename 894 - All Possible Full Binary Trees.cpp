#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

class Solution {
public:
    unordered_map<int, vector<TreeNode*>> mem;
    vector<TreeNode*> allPossibleFBT(int n) {
        if (mem.find(n) != mem.end()) {
            return mem[n];
        }
        else if (n == 1) {
            TreeNode* t = new TreeNode();
            t->val = 0;
            return { t };
        }
        else {
            vector<TreeNode*> ret;
            for (int i = 1; i < n - 1; i += 2) {
                vector<TreeNode*> left = allPossibleFBT(i);
                for (auto& l : left) {
                    vector<TreeNode*> right = allPossibleFBT(n - i - 1);
                    for (auto& r : right) {

                        TreeNode* tree = new TreeNode();
                        tree->val = 0;
                        tree->left = l;
                        tree->right = r;
                        ret.push_back(tree);
                    }
                }
            }
            mem[n] = ret;
            return ret;
        }

    }
};