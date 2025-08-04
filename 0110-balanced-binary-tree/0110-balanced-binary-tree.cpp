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
        int l=height(node->left);
        int r=height(node->right);
        return 1+max(l,r);
    }

    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        bool flag1= abs(height(root->left)-height(root->right))<=1;
        bool flag2= isBalanced(root->left);
        bool flag3= isBalanced(root->right);
        return flag1 && flag2 && flag3;            
    }
};