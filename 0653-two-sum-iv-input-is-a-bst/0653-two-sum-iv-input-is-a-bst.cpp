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
    bool help(TreeNode* root,unordered_set<int> &visited,int k){
        if(!root)return false;
        if(visited.find(k-root->val)!=visited.end())return true;
        visited.insert(root->val);
        return help(root->left,visited,k) || help(root->right,visited,k);
    }

    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        if(!root->left && !root->right)return false;
        unordered_set<int> visited;
        return help(root,visited,k);
    }
};