/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void buildMap(TreeNode* node, TreeNode* parent,unordered_map<TreeNode*,TreeNode*>& m){
        if(!node)return;
        m[node]=parent;
        buildMap(node->left,node,m);
        buildMap(node->right,node,m);

    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> m;
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        buildMap(root,NULL,m);

        q.push(target);
        visited.insert(target);
        int d=0;

        while(!q.empty()){
            if(d==k)break;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && visited.find(node->left)==visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && visited.find(node->right)==visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(m[node] && visited.find(m[node])==visited.end()){
                    q.push(m[node]);
                    visited.insert(m[node]);
                }
            }
            d++;
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;    
    }
};