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
    TreeNode* help(int postStart,int postEnd,int inStart,int inEnd,vector<int>& postorder, vector<int>& inorder,unordered_map<int,int> &m){
        if(postStart>postEnd || inStart>inEnd)return NULL;

        int nodeVal=postorder[postEnd];
        TreeNode* node=new TreeNode(nodeVal);
        int inRootIndx=m[nodeVal];
        int numsLeft=inRootIndx-inStart;
        node->left=help(postStart,postStart+numsLeft-1,inStart,inRootIndx-1,postorder,inorder,m);
        node->right=help(postStart+numsLeft,postEnd-1,inRootIndx+1,inEnd,postorder,inorder,m);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        //element -> i
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }   
        return help(0,postorder.size()-1,0,inorder.size()-1,postorder,inorder,m);
    }
};