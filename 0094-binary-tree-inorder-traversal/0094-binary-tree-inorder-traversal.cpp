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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr=root;
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
                    node->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
            else{
                inorder.push_back(curr->val);
                curr=curr->right;
            }
        }

        return inorder;  
    }
};