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
    int height(TreeNode* node,int &maxDia){
        if(!node)return -1;
        int l=height(node->left,maxDia);
        int r=height(node->right,maxDia);
        maxDia=max(maxDia,2+l+r);
        return 1+max(l,r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int maxDia=0;
        height(root,maxDia);
        return maxDia;
    }
};