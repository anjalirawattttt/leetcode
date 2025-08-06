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
    int kthSmallest(TreeNode* root, int k) {
        if(!root)return -1;
        int i=0;
        stack<TreeNode*> s;
        TreeNode* node=root;

        while(node || !s.empty()){

            while(node){
                s.push(node);
                node=node->left;
            }
            node=s.top();
            s.pop();
            //push
            i++;
            if(i==k)return node->val;
            node=node->right;
        }

          
        return -1;
    }
};