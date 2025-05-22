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
    void helper(TreeNode* root){
        if(!root)return ;
        if(root->left && root->right){
            TreeNode* left=root->left;
            TreeNode* right=root->right;
            root->left=right;
            root->right=left;
        }
        else if(root->left){
            TreeNode* node = root->left;
            root->left = NULL;
            root->right = node; 
        }
        else if(root->right){
            TreeNode* node = root->right;
            root->right = NULL;
            root->left = node; 
        }
        helper(root->left);
        helper(root->right);

    }

    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};