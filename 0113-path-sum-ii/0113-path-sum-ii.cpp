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
    void path(TreeNode* root,int targetSum,int sum,vector<vector<int>> &v,vector<int> &temp){
        if(!root)return;
        temp.push_back(root->val);
        if(!root->left && !root->right){
            if(sum==targetSum)v.push_back(temp);
        }
        
        if(root->left)path(root->left,targetSum,sum+root->left->val,v,temp);
        if(root->right)path(root->right,targetSum,sum+root->right->val,v,temp);
        temp.pop_back();
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> v;
        vector<int> temp;
        if(!root)return v;
        path(root,targetSum,root->val,v,temp);
        return v;
    }
};