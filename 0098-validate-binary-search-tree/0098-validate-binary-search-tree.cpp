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
    bool help(TreeNode* node,long long minEle,long long maxEle){
        if(!node)return true;
        if(node->val<=minEle || node->val>=maxEle)return false;
        return help(node->left,minEle,node->val) && help(node->right,node->val,maxEle);
    }
    bool isValidBST(TreeNode* root) {
        return help(root->left,LONG_MIN,root->val) && help(root->right,root->val,LONG_MAX);
    }
};