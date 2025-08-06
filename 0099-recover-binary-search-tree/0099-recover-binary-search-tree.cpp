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
    

    void recoverTree(TreeNode* root) {
        if(!root)return;
        TreeNode* curr=root;
        TreeNode* prev=NULL;
        TreeNode* first=NULL;
        TreeNode* second=NULL;

        while(curr){
            if(curr->left){
                TreeNode* node=curr->left;
                while(node->right!=NULL && node->right!=curr){
                    node=node->right;
                }
                if(node->right==NULL){
                    node->right=curr;
                    curr=curr->left;
                }
                if(node->right==curr){
                    //push
                    if(prev && curr->val<prev->val){
                        if(!first)first=prev;
                        second=curr;
                    }
                    prev=curr;
                    node->right=NULL;
                    curr=curr->right;
                }
            }
            else{
                //push
                if(prev && curr->val<prev->val){
                    if(!first)first=prev;
                    second=curr;
                }
                prev=curr;
                curr=curr->right;
            }
        }

        
        if(first && second)swap(first->val,second->val);
    }
};