/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root, long minVal, long maxVal) {
        if (!root) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }

    void merge(TreeNode* root, unordered_map<int, TreeNode*>& mp) {
        if (!root) return;
        if (root->left && mp.count(root->left->val)) {
            root->left = mp[root->left->val];
            mp.erase(root->left->val);
            merge(root->left, mp);
        } else {
            merge(root->left, mp);
        }

        if (root->right && mp.count(root->right->val)) {
            root->right = mp[root->right->val];
            mp.erase(root->right->val);
            merge(root->right, mp);
        } else {
            merge(root->right, mp);
        }
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, int> count;

        for (auto t : trees) {
            mp[t->val] = t;
            count[t->val]++;
            if (t->left) count[t->left->val]++;
            if (t->right) count[t->right->val]++;
        }

        TreeNode* root = nullptr;
        for (auto t : trees) {
            if (count[t->val] == 1) {
                root = t;
                break;
            }
        }

        if (!root) return nullptr;
        mp.erase(root->val);

        merge(root, mp);

        if (!mp.empty()) return nullptr;

        if (!isValidBST(root, LONG_MIN, LONG_MAX)) return nullptr;

        return root;
    }

};