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
    int height(TreeNode* node){
        if(!node)return 0;
        return 1+max(height(node->left),height(node->right));
    }

    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int diff=abs(height(root->left)-height(root->right));
        return diff<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};