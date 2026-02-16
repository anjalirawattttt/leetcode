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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root)return root;
        queue<TreeNode*> q;
        q.push(root);  
        bool rev=false;

        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            vector<TreeNode*> tempn;
            while(size--){
                TreeNode* curr=q.front();
                q.pop();
                temp.push_back(curr->val);
                tempn.push_back(curr);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            if(rev){
                reverse(temp.begin(),temp.end());
                int idx=0;
                for(auto &t:tempn){
                    t->val=temp[idx++];
                }
            }
            rev=!rev;
        }

        return root;
    }
};