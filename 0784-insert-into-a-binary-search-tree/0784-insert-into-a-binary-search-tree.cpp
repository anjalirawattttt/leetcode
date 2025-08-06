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
    void help(TreeNode* root,TreeNode* node){
        if(node->val<root->val){
            if(!root->left){
                root->left=node;
                return;
            }
            help(root->left,node);
        }
        else{
            if(!root->right){
                root->right=node;
                return;
            }
            help(root->right,node);
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=new TreeNode(val);  
        if(!root)return node;

        help(root,node); 
        return root;
    }
};