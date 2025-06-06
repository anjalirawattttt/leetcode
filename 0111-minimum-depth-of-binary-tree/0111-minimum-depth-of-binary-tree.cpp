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
    void depth(TreeNode* root,int &ans,int x){
        if(!root)return;
        if(!root->left && !root->right){
            ans=min(ans,x);
        }
        depth(root->left,ans,x+1);
        depth(root->right,ans,x+1);
    }

    int minDepth(TreeNode* root) {
        if(!root)return 0;
        int ans=INT_MAX;
        int x=1;
        depth(root,ans,x);
        return ans;
    }
};