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
    TreeNode* invertTree(TreeNode* root) {
        if(!root || (!root->left && !root->right))return root;
        // if(!root->left || !root->right){
        //     if(!root->left){
        //         root->left=root->right;
        //         root->left=invertTree(root->left);
        //         root->right=NULL;
        //     }
        //     else if(!root->right){
        //         root->right=root->left;
        //         root->right=invertTree(root->right);
        //         root->left=NULL;
        //     }
        //     return root;
        // }
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        root->left=invertTree(root->left);
        root->right=invertTree(root->right);
        return root;
    }
};