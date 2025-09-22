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
    TreeNode* help(int ps,int pe,int is,int ie,vector<int>& preorder,vector<int>& inorder){
        if(ps>pe || is>ie)return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        auto it = find(inorder.begin(), inorder.end(), preorder[ps]);
        int x = distance(inorder.begin(), it);
        int left=x-is;
        int right=ie-x;
        root->left=help(ps+1,ps+left,is,x-1,preorder,inorder);
        root->right=help(ps+left+1,pe,x+1,ie,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return help(0,n-1,0,n-1,preorder,inorder);
    }
};