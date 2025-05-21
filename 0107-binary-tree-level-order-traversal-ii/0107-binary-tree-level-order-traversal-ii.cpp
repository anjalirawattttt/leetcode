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
    int height(TreeNode* root) {
        if (!root) return 0; 
        return 1 + max(height(root->left), height(root->right));
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h=height(root);
        vector<vector<int>> v(h);
        if(!root)return v;

        queue<TreeNode*> q;
        q.push(root);
        int i=h-1;
        while(!q.empty()){
            int size=q.size();
            vector<int> t;
            while(size--){
                TreeNode* temp=q.front();
                q.pop();
                t.push_back(temp->val);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            v[i]=t;
            i--;
        }
        return v;
    }
};