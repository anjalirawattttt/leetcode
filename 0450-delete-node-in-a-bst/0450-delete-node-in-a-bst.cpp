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
    TreeNode* findMin(TreeNode* root){
        if(!root)return root;
        TreeNode* node=root;
        while(node->left)node=node->left;
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;//return NULL

        if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else{
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }

            if(!root->left){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }

            if(!root->right){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }

            //2 children
            TreeNode* minRight=findMin(root->right);
            swap(root->val,minRight->val);
            root->right=deleteNode(root->right,minRight->val);
        }

        return root;
    }
};