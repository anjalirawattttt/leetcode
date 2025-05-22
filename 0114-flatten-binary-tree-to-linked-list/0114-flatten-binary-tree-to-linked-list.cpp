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
    void findRightMost(TreeNode* root , TreeNode* &node){
        if(!root)return;
        node=root;
        findRightMost(root->left,node);
        findRightMost(root->right,node);
    }

    void flatten(TreeNode* root) {
        if(!root)return;
        if(root->left){
            TreeNode * rightMost=NULL;
            findRightMost(root->left,rightMost);
            rightMost->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        flatten(root->right);
    }
};