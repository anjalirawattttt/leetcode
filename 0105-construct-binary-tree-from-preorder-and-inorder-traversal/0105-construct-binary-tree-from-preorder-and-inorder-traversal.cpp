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
    TreeNode* help(int preStart,int preEnd,int inStart,int inEnd,vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>& m){
        if(preStart>preEnd || inStart>inEnd)return NULL;

        int nodeVal=preorder[preStart];
        TreeNode* node=new TreeNode(nodeVal);
        int inRootIndx=m[nodeVal];
        int numsLeft=inRootIndx-inStart;


        node->left=help(preStart+1,preStart+numsLeft,inStart,inRootIndx-1,preorder,inorder,m);
        node->right=help(preStart+numsLeft+1,preEnd,inRootIndx+1,inEnd,preorder,inorder,m);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //hashmap for inorder 
        //element->i
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return help(0,preorder.size()-1,0,inorder.size()-1,preorder,inorder,m);   
    }
};