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
    int help(TreeNode* root,int& ans){
        if(!root)return 0;
        int l=help(root->left,ans);
        int r=help(root->right,ans);
        int temp=root->val;
        if(l>0)temp+=l;
        if(r>0)temp+=r;
        ans=max(ans,temp);
        return max(root->val,max(root->val+l,root->val+r));
    }
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        int ans=root->val;    
        help(root,ans);
        return ans;
    }
};