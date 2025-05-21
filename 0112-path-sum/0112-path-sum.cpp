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
    bool rec(TreeNode* node, int targetSum,int sum){
        if(!node){
            return false;
        }
        sum+=node->val;
        if(!node->left && !node->right){
            if(sum==targetSum)return true;
        }
        return rec(node->left,targetSum,sum) || rec(node->right,targetSum,sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return rec(root,targetSum,0);
    }
};