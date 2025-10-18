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
    TreeNode* createNode(int x,unordered_map<int,TreeNode*> &m){
        if(m.find(x)!=m.end()){
            return m[x];
        }
        TreeNode* node=new TreeNode(x);
        m[x]=node;
        return node;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> m;
        unordered_set<int> parents,childs;
        for(auto &d:descriptions){
            parents.insert(d[0]);
            childs.insert(d[1]);
            TreeNode* parent=createNode(d[0],m);
            if(d[2]==1){
                parent->left=createNode(d[1],m);
            }
            else{
                parent->right=createNode(d[1],m);
            }            
        }
        for(const int &p:parents){
            if(childs.find(p)==childs.end())return m[p];
        }  
        return NULL;  
    }
};