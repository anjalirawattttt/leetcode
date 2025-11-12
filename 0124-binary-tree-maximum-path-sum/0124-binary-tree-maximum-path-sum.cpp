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
    int help(TreeNode* root,int &ans){
        if(!root)return 0;
        int left = help(root->left,ans);
        int right = help(root->right,ans);
        // ans=max(ans,left);
        // ans=max(ans,right);
        int temp=root->val;
        if(left>0)temp+=left;
        if(right>0)temp+=right;
        ans=max(ans,temp);
        return max(root->val,max(root->val+left,root->val+right)); 
    }
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        int ans=root->val;
        help(root,ans);
        return ans;       
    }
};