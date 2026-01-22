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
    int buildExcess(TreeNode* root,map<TreeNode*,int> &excess){
        if(!root)return 0;
        if(!root->left && !root->right){
            excess[root]=root->val-1;
        }
        int left=buildExcess(root->left,excess);
        int right=buildExcess(root->right,excess);
        excess[root]=root->val-1+left+right;
        return excess[root];
    }
    void help(TreeNode* root,map<TreeNode*,int> &excess,int &moves){
        if(!root)return;
        moves+=abs(excess[root]);
        help(root->left,excess,moves);
        help(root->right,excess,moves);
    }
    int distributeCoins(TreeNode* root) {
        map<TreeNode*,int> excess;  
        buildExcess(root,excess); 
        int moves=0;
        help(root,excess,moves);
        return moves;            
    }
};