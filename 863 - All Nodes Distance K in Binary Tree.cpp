#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

class Solution {
public:
    vector<int> ret = {};

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        distanceK_(root, target, k);
        return ret;
    }

    int findDistance(TreeNode* root, TreeNode* target, int k) {
        if (!root) {
            return -1;
        }
        if (root->val == target->val) {
            return 0;
        }
        else {
            int l = findDistance(root->left, target, k);
            int r = findDistance(root->right, target, k);

            int distance = 1 + max(l, r);
            if (distance == 0) {
                return -1;
            }
            if (distance == k) {
                ret.push_back(root->val);
            }
            if (distance < k) {
                if (l == -1) {
                    getFrom(root->left, k - distance - 1);
                }
                else {
                    getFrom(root->right, k - distance - 1);
                }
            }
            return distance;
        }
    }

    void getFrom(TreeNode* root, int d) {
        if (!root) {
            return;
        }
        else if (d == 0) {
            ret.push_back(root->val);
        }
        else {
            getFrom(root->left, d - 1);
            getFrom(root->right, d - 1);
        }
    }

    void distanceK_(TreeNode* root, TreeNode* target, int k) {
        if (!root) {
            return;
        }
        int distance = findDistance(root, target, k);


        getFrom(target, k);
    }
};