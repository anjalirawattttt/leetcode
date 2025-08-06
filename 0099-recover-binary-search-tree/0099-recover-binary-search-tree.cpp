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
    void help(TreeNode* root,vector<TreeNode*> &inorder){
        if(!root)return;
        help(root->left,inorder);
        inorder.push_back(root);
        help(root->right,inorder);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorder;
        help(root,inorder);

        TreeNode* first=NULL;
        TreeNode* second=NULL;

        for(int i=1;i<inorder.size();i++){
            if(inorder[i]->val<inorder[i-1]->val){
                if(!first)first=inorder[i-1];
                second=inorder[i];
            }
        }
        swap(first->val,second->val);
    }
};