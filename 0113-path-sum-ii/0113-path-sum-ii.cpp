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
    void path (TreeNode* root, int targetSum,vector<int> &temp,vector<vector<int>> &v){
        if(!root)return ;
        temp.push_back(root->val);
        if(!root->left && !root->right){
            if(root->val==targetSum)v.push_back(temp);
        }
        path(root->left,targetSum-root->val,temp,v);
        path(root->right,targetSum-root->val,temp,v);
        temp.pop_back();

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> v;
        vector<int> temp;
        if(!root)return v;
        path(root,targetSum,temp,v);
        return v;
    }
};