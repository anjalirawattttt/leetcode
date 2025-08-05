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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* curr=root;
        while(curr){
            if(curr->left){
                TreeNode* node=curr->left;
                while(node->right!=NULL && node->right!=curr){
                    node=node->right;
                }
                if(node->right==NULL){
                    node->right=curr;
                    preorder.push_back(curr->val);
                    curr=curr->left;
                }
                if(node->right==curr){
                    node->right=NULL;
                    curr=curr->right;
                }
            }
            else{
                preorder.push_back(curr->val);
                curr=curr->right;
            }
        }

        return preorder;    
    }
};