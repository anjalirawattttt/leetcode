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
    int computelH(TreeNode* root){
        int h=0;
        TreeNode* node=root;
        while(node){
            node=node->left;
            h++;
        }
        return h;
    }
    int computerH(TreeNode* root){
        int h=0;
        TreeNode* node=root;
        while(node){
            node=node->right;
            h++;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int lh=  computelH(root);
        int rh=  computerH(root);
        if(lh==rh){
            return ( 1 << lh)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};