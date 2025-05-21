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
    bool validate(TreeNode* node,long minn,long maxx){
        if(node==NULL)return true;
        if(node->val<=minn || node->val>=maxx)return false;
        return validate(node->left,minn,node->val) && validate(node->right,node->val,maxx);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root,LONG_MIN,LONG_MAX);
    }
};